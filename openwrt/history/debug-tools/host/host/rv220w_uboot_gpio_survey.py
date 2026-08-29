#!/usr/bin/env python3
"""Guided RV220W front-panel GPIO survey through stock U-Boot.

Uses the reconstructed stock commands:
  gpio r <pin>
  gpio w <pin> <0|1>
  read64 <csr-address>
  write64 <csr-address> <value>

The script snapshots each Octeon GPIO BIT_CFGX register plus the observed level,
only toggles lines already configured as outputs by default, and restores both
level and BIT_CFGX immediately after each pin. Ctrl+C restores the current pin.
"""
from __future__ import annotations
import argparse, datetime as dt, json, pathlib, re, sys, time

PROMPT_RE = re.compile(rb"rv200w#\s*$", re.I | re.M)
GPIO_CFG_BASE = 0x1070000000800  # low physical/CSR address accepted by stock read64/write64
KNOWN = {
    1: "RESET/recovery input (known sensitive; skipped by default)",
    2: "POWER LED (survey-qualified active-low; LOW=on, HIGH=off)",
    3: "DIAG LED (survey-qualified active-low; LOW=on, HIGH=off)",
    4: "WIRELESS LED (survey-qualified active-low; LOW=on, HIGH=off)",
    5: "Shared Ethernet switch/PHY LED-control or reset candidate; toggling LOW extinguished LAN1-4/WAN LED groups (known sensitive; excluded from gpio-leds)",
    6: "DMZ LED (survey-qualified active-low; LOW=on, HIGH=off)",
}
SENSITIVE = {1, 5}

class SurveyError(RuntimeError):
    pass

class UBoot:
    def __init__(self, ser, timeout: float = 4.0):
        self.ser = ser
        self.timeout = timeout

    def _read_prompt(self, timeout: float | None = None) -> str:
        deadline = time.monotonic() + (self.timeout if timeout is None else timeout)
        buf = bytearray()
        while time.monotonic() < deadline:
            chunk = self.ser.read(self.ser.in_waiting or 1)
            if chunk:
                buf.extend(chunk)
                if PROMPT_RE.search(bytes(buf)):
                    return bytes(buf).decode("utf-8", "replace")
            else:
                time.sleep(0.02)
        raise SurveyError("timed out waiting for the stock U-Boot rv200w# prompt")

    def sync(self) -> str:
        self.ser.reset_input_buffer()
        self.ser.write(b"\r")
        self.ser.flush()
        return self._read_prompt(3.0)

    def cmd(self, text: str, timeout: float | None = None) -> str:
        self.ser.reset_input_buffer()
        self.ser.write(text.encode("ascii") + b"\r")
        self.ser.flush()
        out = self._read_prompt(timeout)
        return out.replace("\r", "")

    def gpio_read(self, pin: int) -> int:
        out = self.cmd(f"gpio r {pin}")
        m = re.search(rf"read gpio\s+{pin}\s*,?\s*value is\s*:\s*([01])", out, re.I)
        if not m:
            raise SurveyError(f"could not parse gpio r {pin} output: {out!r}")
        return int(m.group(1))

    def gpio_write(self, pin: int, value: int) -> None:
        out = self.cmd(f"gpio w {pin} {value}")
        if not re.search(rf"set gpio\s+{pin}\s+with value\s*:\s*{value}", out, re.I):
            raise SurveyError(f"could not confirm gpio w {pin} {value}: {out!r}")

    def read64(self, address: int) -> int:
        out = self.cmd(f"read64 {address:x}")
        matches = re.findall(r"0x[0-9a-fA-F]+\s*:\s*0x([0-9a-fA-F]+)", out)
        if not matches:
            raise SurveyError(f"could not parse read64 0x{address:x}: {out!r}")
        return int(matches[-1], 16)

    def write64(self, address: int, value: int) -> None:
        out = self.cmd(f"write64 {address:x} {value:x}")
        if "writing" not in out.lower():
            raise SurveyError(f"could not confirm write64 0x{address:x}: {out!r}")


def cfg_addr(pin: int) -> int:
    return GPIO_CFG_BASE + pin * 8


def result_path(directory: pathlib.Path) -> pathlib.Path:
    stamp = dt.datetime.now(dt.timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    return directory / f"rv220w-uboot-gpio-survey-{stamp}.json"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("port", help="serial adapter, e.g. /dev/ttyUSB0")
    ap.add_argument("--baud", type=int, default=115200)
    ap.add_argument("--start", type=int, default=0)
    ap.add_argument("--end", type=int, default=10)
    ap.add_argument("--include-inputs", action="store_true", help="also toggle GPIOs whose BIT_CFGX TX_OE bit is clear (not recommended)")
    ap.add_argument("--include-sensitive", action="store_true", help="allow known-sensitive GPIOs such as GPIO1 reset/recovery and GPIO5 shared Ethernet control")
    ap.add_argument("--settle", type=float, default=0.15)
    ap.add_argument("--output-dir", type=pathlib.Path, default=pathlib.Path.cwd())
    args = ap.parse_args()
    if args.start < 0 or args.end < args.start or args.end > 31:
        ap.error("GPIO range must satisfy 0 <= start <= end <= 31")

    try:
        import serial  # type: ignore
    except ImportError as exc:
        raise SystemExit("pyserial is required; on CachyOS install python-pyserial") from exc

    print("RV220W stock U-Boot guided GPIO survey")
    print("  * Router must already be stopped at the 'rv200w#' U-Boot prompt.")
    print("  * Each pin's BIT_CFGX register and logic level are snapshotted and restored.")
    print("  * Inputs are skipped by default; GPIO1 reset/recovery and GPIO5 shared Ethernet control are skipped unless explicitly overridden.")
    print("  * Unknown outputs can still control non-LED hardware. Keep UART recovery available.")
    confirm = input("Type RV220W_GPIO_SURVEY to continue: ").strip()
    if confirm != "RV220W_GPIO_SURVEY":
        print("Cancelled.")
        return 2

    args.output_dir.mkdir(parents=True, exist_ok=True)
    out_path = result_path(args.output_dir)
    records: list[dict] = []
    current_restore = None

    kwargs = dict(port=args.port, baudrate=args.baud, timeout=0.08, write_timeout=2)
    try:
        try:
            ser = serial.Serial(exclusive=True, **kwargs)
        except TypeError:
            ser = serial.Serial(**kwargs)
        with ser:
            ub = UBoot(ser)
            ub.sync()
            # Prove required commands before touching a pin.
            help_gpio = ub.cmd("help gpio")
            if "gpio" not in help_gpio.lower():
                raise SurveyError("stock U-Boot gpio command is unavailable")
            # Validate CSR read support against GPIO0 configuration.
            ub.read64(cfg_addr(args.start))

            for pin in range(args.start, args.end + 1):
                note = KNOWN.get(pin, "")
                if pin in SENSITIVE and not args.include_sensitive:
                    rec = {"gpio": pin, "status": "skipped-known-sensitive", "note": note}
                    records.append(rec)
                    print(f"\nGPIO{pin}: SKIPPED — {note}")
                    continue

                addr = cfg_addr(pin)
                cfg0 = ub.read64(addr)
                level0 = ub.gpio_read(pin)
                is_output = bool(cfg0 & 1)
                direction = "OUTPUT" if is_output else "INPUT"
                print(f"\nGPIO{pin} Starting State: {'HIGH' if level0 else 'LOW'}  direction={direction}  BIT_CFG=0x{cfg0:016x}")
                if note:
                    print(f"  Known mapping: {note}")

                rec = {
                    "gpio": pin,
                    "cfg_address": f"0x{addr:x}",
                    "initial_cfg": f"0x{cfg0:016x}",
                    "initial_level": level0,
                    "initial_direction": direction,
                    "known_note": note or None,
                }
                if not is_output and not args.include_inputs:
                    choice = input("  GPIO is currently INPUT. Type DRIVE to test it temporarily, or press Enter to skip: ").strip()
                    if choice != "DRIVE":
                        rec["status"] = "skipped-input"
                        records.append(rec)
                        print("  Skipping input. Use --include-inputs to pre-authorize temporary driving of all non-sensitive inputs.")
                        continue
                    rec["input_drive_authorized_interactively"] = True
                    print("  Temporary drive authorized for this pin; exact BIT_CFGX will be restored after the HIGH/LOW test.")

                def restore() -> tuple[int | None, int | None]:
                    # Restore output latch first while command access is valid, then exact per-pin mux/OE config.
                    try:
                        ub.gpio_write(pin, level0)
                    finally:
                        ub.write64(addr, cfg0)
                    cfg1 = ub.read64(addr)
                    level1 = ub.gpio_read(pin)
                    return cfg1, level1

                current_restore = restore
                try:
                    ub.gpio_write(pin, 1)
                    time.sleep(args.settle)
                    high_obs = input(f"Switching GPIO{pin} HIGH, enter result (or blank): ")
                    ub.gpio_write(pin, 0)
                    time.sleep(args.settle)
                    low_obs = input(f"Switching GPIO{pin} LOW, enter result (or blank): ")
                    cfg1, level1 = restore()
                    current_restore = None
                    restored = cfg1 == cfg0
                    rec.update({
                        "high_observation": high_obs,
                        "low_observation": low_obs,
                        "restored_cfg": f"0x{cfg1:016x}",
                        "restored_level_observed": level1,
                        "config_restored_exactly": restored,
                        "status": "tested" if restored else "restore-mismatch",
                    })
                    print(f"Restoring GPIO{pin} state... cfg={'OK' if restored else 'MISMATCH'}, observed level={'HIGH' if level1 else 'LOW'}")
                    if not restored:
                        raise SurveyError(f"GPIO{pin} BIT_CFG restore mismatch; stopping survey")
                    records.append(rec)
                    out_path.write_text(json.dumps({"version":"1.15.1","records":records}, indent=2)+"\n")
                except KeyboardInterrupt:
                    print(f"\nCtrl+C: restoring GPIO{pin} before exit...")
                    try:
                        cfg1, level1 = restore()
                        rec.update({"status":"cancelled-restored","restored_cfg":f"0x{cfg1:016x}","restored_level_observed":level1,"config_restored_exactly":cfg1==cfg0})
                    finally:
                        current_restore = None
                        records.append(rec)
                        out_path.write_text(json.dumps({"version":"1.15.1","records":records}, indent=2)+"\n")
                    print(f"Partial results: {out_path}")
                    return 130

    except KeyboardInterrupt:
        if current_restore is not None:
            try:
                current_restore()
            except Exception as exc:
                print(f"WARNING: restoration after Ctrl+C failed: {exc}", file=sys.stderr)
        out_path.write_text(json.dumps({"version":"1.15.1","records":records}, indent=2)+"\n")
        return 130
    except (SurveyError, OSError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        if records:
            out_path.write_text(json.dumps({"version":"1.15.1","records":records}, indent=2)+"\n")
            print(f"Partial results: {out_path}", file=sys.stderr)
        return 1

    out_path.write_text(json.dumps({"version":"1.15.1","records":records}, indent=2)+"\n")
    print(f"\nSurvey complete. Results: {out_path}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
