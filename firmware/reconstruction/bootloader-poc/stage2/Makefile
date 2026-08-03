SHELL := /bin/sh
CLANG := clang
LD := ld.lld
OBJCOPY := llvm-objcopy
READELF := readelf

TARGET := rv220w-stage2-poc
OUT ?= build
ELF := $(OUT)/$(TARGET).elf
BIN := $(OUT)/$(TARGET).bin
MAP := $(OUT)/$(TARGET).map

CFLAGS := --target=mips64-unknown-linux-gnu -EB -march=mips64r2 -mabi=64 \
  -ffreestanding -fno-builtin -fno-pic -mno-abicalls -G0 -msoft-float \
  -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables \
  -fdata-sections -ffunction-sections -Os -Wall -Wextra -Werror -nostdlib
ASFLAGS := $(CFLAGS)
LDFLAGS := -m elf64btsmip -T linker.ld --gc-sections -Map=$(MAP)

OBJECTS := $(OUT)/start.o $(OUT)/vendor_callgate_asm.o $(OUT)/stage2.o \
  $(OUT)/console.o $(OUT)/mini_lib.o $(OUT)/crc32.o $(OUT)/sha256.o \
  $(OUT)/inspection.o $(OUT)/elf_inspection.o $(OUT)/vendor_callgate.o

.PHONY: all clean verify
all: $(ELF) $(BIN) verify

$(OUT):
	mkdir -p $@

$(OUT)/start.o: start.S | $(OUT)
	$(CLANG) $(ASFLAGS) -c $< -o $@

$(OUT)/vendor_callgate_asm.o: vendor_callgate.S | $(OUT)
	$(CLANG) $(ASFLAGS) -c $< -o $@

$(OUT)/%.o: %.c | $(OUT)
	$(CLANG) $(CFLAGS) -I. -c $< -o $@

$(ELF): $(OBJECTS) linker.ld
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

verify: $(ELF)
	python3 ../tools/verify_stage2.py $(ELF)

clean:
	rm -rf $(OUT)
