#include <kernel.h>
#include <plic.h>
#include <trap.h>
#include <uart.h>

struct TrapFrame kframe = {0};

uint64_t _rupt(uint64_t mcause, uint64_t epc, uint64_t tval,
               struct TrapFrame *trap) {
  switch (mcause) {
  case MACHINE_SOFTWARE:
    print("Machine Software INTR\n");
    break;
  case MACHINE_TIMER:
    break;
  case MACHINE_EXTERNAL: {
    int id = plic_claim[0];
    if (id == 10) {
      uart_handler();
    }
    plic_claim[0] = id;
    break;
  }
  case ILLEGAL_INST:
    print("Illegal instruction\n");
    break;
  case BREAKPOINT:
    print("Breakpoint\n");
    break;
  default:
    break;
  }
  return epc;
}
