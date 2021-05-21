#include <kernel.h>
#include <uart.h>
#include <virtio.h>

void init_virtio() {
  unsigned int i;
  for (i = 0x10001000; i < 0x10008000; i += 0x1000) {
    volatile unsigned int *ptr = (unsigned int *)(void *)(long)i;
    int magic = *ptr;
    int device_id = *(ptr + 2);
    if (magic == 0x74726976) {
      switch (device_id) {
      case 1:
        print("Network device found.\n");
        break;
      case 2:
        print("Block device found.\n");
        break;
      case 4:
        print("Entropy device found.\n");
        break;
      case 16:
        print("GPU device found.\n");
        break;
      case 18:
        print("Input device found.\n");
        break;
      default:
        break;
      }
    }
  }
}
