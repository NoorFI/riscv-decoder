#include "decoder.h"

uint32_t extract_field(uint32_t instruction, int high, int low){
    //Parameters: A 32 bit instruction, high and low bits.
    //Returns the extracted bits
    int width = (high - low) + 1;
    uint32_t mask = (1U << width) - 1;
    return (instruction >> low) & mask;
}

int32_t sign_extend(uint32_t value, int bits){
    //Parameters: A 32 bit unsigned value and number of bits
    //Returns 32 bit signed integer
    uint32_t mask = 1U << (bits - 1);
    return (value ^ mask) - mask;
}

void decode_instruction(uint32_t instruction, decoded_instr_t *decoded){}