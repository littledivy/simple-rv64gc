#!/bin/sh

set -e

clang-format -i *.c include/*.h

riscv64-unknown-elf-gcc \
  -Iinclude \
  -T linker.ld \
  -march=rv64g \
  -mabi=lp64 \
  -static \
  -nostdlib \
  -nostartfiles \
  -mcmodel=medany \
  -ffunction-sections \
  -fdata-sections \
  -o kmain uart.c plic.c timer.c virtio.c trap.c kmain.c boot.s trap.s

qemu-system-riscv64 \
  -kernel kmain \
  -smp 4 \
  -machine virt \
  -bios none \
  -serial mon:stdio # -nographic

