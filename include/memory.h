#ifndef MEMORY_H
#define MEMORY_H //Guard

#include "common.h"

int load_hex_file(const char *filename, uint8_t *memory);
void memory_dump(const uint8_t *memory, size_t size);

#endif