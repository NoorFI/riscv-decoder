#ifndef COMMON_H
#define COMMON_H //Guard

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h> //All headers

#define XLEN 32
#define MEMORY_SIZE (64 * 1024)
#define INSTRUCTION_SIZE 4
#define MNEMONIC_SIZE 16
#define DUMP_WIDTH 16
#define EXTRACT_BITS(value, high, low) \
(((value) >> (low)) & ((1U << (((high)-(low))+1)) - 1))

#endif