#include <kernel.h>
#include <plic.h>
#include <timer.h>
#include <trap.h>
#include <uart.h>
#include <virtio.h>

void kmain() {
  init_uart();
  init_timer();
  init_plic();
  init_virtio();
  print("Hello RISC-V!\n");
}
