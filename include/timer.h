#ifndef _TIMER_H
#define _TIMER_H

#include <kernel.h>

// CLINT addresses
static volatile unsigned long *mtime = (unsigned long *)(void *)0x0200bff8;
static volatile unsigned long *mtimecmp = (unsigned long *)(void *)0x02004000;

void init_timer();

#endif
