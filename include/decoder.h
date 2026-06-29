#ifndef DECODER_H
#define DECODER_H //Guard

#include "common.h"

typedef struct{
    uint32_t raw;
    uint32_t opcode;
    uint32_t rd;
    uint32_t funct3;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct7;
    int32_t imm;
    char mnemonic[16];
} decoded_instr_t;

uint32_t extract_field(uint32_t instruction, int high, int low);
int32_t sign_extend(uint32_t value, int bits);
void decode_instruction(uint32_t instruction, decoded_instr_t *decoded); //Function prototypes

#endif