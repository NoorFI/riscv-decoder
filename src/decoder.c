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

void decode_instruction(uint32_t instruction, decoded_instr_t *decoded){
    //Parameters: A 32 bit instruction and the decoded structure
    decoded->raw = instruction;
    decoded->opcode = extract_field(instruction, 6, 0);
    decoded->rd = extract_field(instruction, 11, 7);
    decoded->funct3 = extract_field(instruction, 14, 12);
    decoded->rs1 = extract_field(instruction, 19, 15);
    decoded->rs2 = extract_field(instruction, 24, 20);
    decoded->funct7 = extract_field(instruction, 31, 25);

    strcpy(decoded->mnemonic, "UNKNOWN");
    
    if(decoded->opcode != OP_REG){
        return;
    }

    switch(decoded->funct3){
        case 0:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "add");
            }
            else if(decoded->funct7 ==32){
                strcpy(decoded->mnemonic, "sub");
            }
            break;

        case 1:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "sll");
            }
            break;

        case 2:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "slt");
            }
            break;

        case 3:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "sltu");
            }
            break;

        case 4:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "xor");
            }
            break;

        case 5:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "srl");
            }
            else if(decoded->funct7 == 32){
                strcpy(decoded->mnemonic, "sra");
            }
            break;

        case 6:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "or");
            }
            break;
        
        case 7:
            if(decoded->funct7 == 0){
                strcpy(decoded->mnemonic, "and");
            }
            break;
    }
}