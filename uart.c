#include <kernel.h>
#include <uart.h>

int putchar(int ch) {
  while (uart[0] < 0)
    ;
  return uart[0] = ch & 0xff;
}

void print(char *str) {
  while (*str)
    putchar(*str++);
}

void init_uart() {
  (uart + 3)[0] = (1 << 0) | (1 << 1);
  (uart + 2)[0] = (1 << 0);

  (uart + 1)[0] = (1 << 0);

  int divisor = 592;
  uint8_t d_lower = (uint8_t)divisor;
  uint8_t d_upper = (uint8_t)(divisor >> 8);

  (uart + 3)[0] = (1 << 0) | (1 << 1) | 1 << 7;

  uart[0] = d_lower;
  (uart + 1)[0] = d_upper;

  (uart + 3)[0] = (1 << 0) | (1 << 1);
}

uint8_t read_uart() {
  if (*(uart + 5) & 1 == 0) {
    return 0;
  } else {
    return *uart;
  }
}

void uart_handler() {
  uint8_t ch = read_uart();
  // TODO
  putchar('H');
}
