#ifndef _PLIC_H
#define _PLIC_H

#include <kernel.h>

// PLIC addresses
static volatile unsigned int *plic_enable = (unsigned int *)(void *)0x0c002000;
static volatile unsigned int *plic_priority =
    (unsigned int *)(void *)0x0c000000;
static volatile unsigned int *plic_threshold =
    (unsigned int *)(void *)0x0c200000;
static volatile unsigned int *plic_claim = (unsigned int *)(void *)0x0c200004;

void init_plic();

#endif
