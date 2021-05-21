#ifndef _TRAP_H
#define _TRAP_H

#include <kernel.h>

#define SYNC_INTR(N) (0UL << 63) + N
#define ASYNC_INTR(N) (1UL << 63) + N

#define MACHINE_SOFTWARE ASYNC_INTR(3)
#define MACHINE_TIMER ASYNC_INTR(7)
#define MACHINE_EXTERNAL ASYNC_INTR(11)

#define ILLEGAL_INST SYNC_INTR(2)
#define BREAKPOINT SYNC_INTR(3)
#define INST_PAGE_FAULT SYNC_INTR(12)
#define LOAD_PAGE_FAULT SYNC_INTR(13)
#define STORE_PAGE_FAULT SYNC_INTR(15)

struct TrapFrame {
  uint8_t regs[32]; // 0-255
};

uint64_t _rupt(uint64_t mcause, uint64_t epc, uint64_t tval,
               struct TrapFrame *trap);
struct TrapFrame kframe;

#endif
