# v1.0.2 Distrobox and source-preparation recovery

## Observed sequence

The host and Fish syntax checks passed, but `setup-box` printed:

```text
sudo: apt-get: command not found
```

`prepare-sources` then cloned the repositories and failed while running OpenWrt's `scripts/feeds` with host-style Perl library paths and a missing core module:

```text
Can't locate FindBin.pm in @INC
```

The Linux stable clone also expanded to roughly 6 GiB because the server ignored partial-clone filtering and the v1.0.1 helper requested all branches/history.

## Cause

The name `rv220w-openwrt` already referred to a reachable Distrobox that was not the requested Ubuntu 24.04 image. v1.0.1 treated any reachable box as ready, so both provisioning and source preparation executed in the wrong userspace.

The source helper also used:

```text
git clone --filter=blob:none --no-single-branch
```

This is unsuitable for the large Linux stable repository when the remote does not support filtering.

## Correct recovery

Apply the v1.0.2 hotfix, then recreate only the toolkit build container:

```fish
./rv220w.fish doctor
./rv220w.fish setup-box --recreate
./rv220w.fish doctor
./rv220w.fish prepare-sources
```

The existing checkouts under `$RV220W_WORKSPACE/sources` are shared through the host home and survive replacement of the container. `prepare-sources` will reuse them and continue with OpenWrt feed setup.

The existing full Linux clone is valid and may be kept. To reclaim disk space, explicitly replace it with a shallow `linux-6.12.y` clone:

```fish
./rv220w.fish prepare-sources --reclone-linux
```

The old tree is moved to a timestamped backup rather than deleted automatically. Remove that backup only after confirming the replacement checkout is complete.

## New safeguards

- `doctor` reports the actual container OS and provisioning state.
- `setup-box` refuses an incompatible existing container and requests `--recreate`.
- `prepare-sources`, `build`, `build-linux`, and container-backed extraction require a validated and provisioned Ubuntu 24.04 box.
- New clones use `--depth 1 --single-branch --branch REF`.
- `provision-openwrt-box.sh` verifies Ubuntu 24.04 and `apt-get` before package installation.
- Perl `FindBin` and `mips64-linux-gnuabi64-gcc` are checked after provisioning.
