#include <kernel.h>
#include <plic.h>

void init_plic() {
  plic_enable[0] = plic_enable[0] | 0b1 << 10;
  plic_priority[4 * 10] = 6;
  plic_threshold[0] = 1;
}
