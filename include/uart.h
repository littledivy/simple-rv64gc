#ifndef _UART_H
#define _UART_H

#include <kernel.h>

// UART base addr on QEMU Virt
static volatile char *uart = (char *)(void *)0x10000000;

void init_uart();
uint8_t read_uart();
void uart_handler();
void print();

#endif
