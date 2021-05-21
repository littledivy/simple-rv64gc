#include <kernel.h>
#include <timer.h>

void init_timer() {
  // 40 Hz
  mtimecmp[0] = mtime[0] + (10000000 / 40);
}
