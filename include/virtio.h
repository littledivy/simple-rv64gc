#ifndef _VIRTIO_H
#define _VIRTIO_H

#include <kernel.h>

// VIRTIO addresses
static volatile unsigned int *virtio_start = (unsigned int *)(void *)0x10001000;
static volatile unsigned int *virtio_end = (unsigned int *)(void *)0x10008000;

void init_virtio();

#endif
