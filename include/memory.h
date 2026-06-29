#ifndef MEMORY_H
#define MEMORY_H //Guard

#include "common.h"

#define MEMORY_SIZE (64*1024) //Because we are not using magic numbers, defining constants.

int load_hex_file(const char *filename, uint8_t *memory);
void memory_dump(const uint8_t *memory, size_t size);

#endif