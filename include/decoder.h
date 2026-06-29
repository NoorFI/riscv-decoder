#ifndef DECODER_H
#define DECODER_H //Guard

#include "common.h"

typedef enum{
    OP_LOAD = 0x03,
    OP_IMM = 0x13,
    OP_AUIPC = 0x17,
    OP_STORE = 0x23,
    OP_REG = 0x33,
    OP_LUI = 0x37,
    OP_BRANCH = 0x63,
    OP_JALR = 0x67,
    OP_JAL = 0x6F,
} opcode_t;

typedef enum{
    ALU_ADD,
    ALU_SUB,
    ALU_AND,
    ALU_OR,
    ALU_XOR,
    ALU_SLL,
    ALU_SRL,
    ALU_SRA,
    ALU_SLT,
    ALU_SLTU,
} alu_op_t;

typedef struct{
    uint32_t raw;
    uint32_t opcode;
    uint32_t rd;
    uint32_t funct3;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct7;
    int32_t imm;
    char mnemonic[MNEMONIC_SIZE];
} decoded_instr_t;

uint32_t extract_field(uint32_t instruction, int high, int low);
int32_t sign_extend(uint32_t value, int bits);
void decode_instruction(uint32_t instruction, decoded_instr_t *decoded);
void decode_r_type(uint32_t instruction, decoded_instr_t *decoded);
void decode_i_type(uint32_t instruction, decoded_instr_t *decoded);
void decode_s_type(uint32_t instruction, decoded_instr_t *decoded);
void decode_b_type(uint32_t instruction, decoded_instr_t *decoded);
void decode_u_type(uint32_t instruction, decoded_instr_t *decoded);
void decode_j_type(uint32_t instruction, decoded_instr_t *decoded); 
void print_instructions(uint32_t address, decoded_instr_t *inst); //Function prototypes

#endif