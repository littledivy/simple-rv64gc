## Barebones RISC-V (rv64gc) kernel

### Running

```shell
qemu-system-riscv64 \
  -kernel kmain \
  -smp 4 \
  -machine virt \
  -bios none \
  -serial mon:stdio \
  -nographic
```

### License

MIT License
