#include "common.h"
#include "decoder.h"
#include "memory.h"

int main(int argc, char *argv[]){ //For command line arguments
    decoded_instr_t inst = {0};
    
    inst.raw = 0x00A28233;
    inst.opcode = 51;
    inst.rd = 4;
    inst.rs1 = 5;
    inst.rs2 = 10;
    inst.funct3 = 0;
    inst.funct7 = 0;
    inst.imm = 0;
    
    strcpy(inst.mnemonic, "add");

    printf("Decoded Instruction\n");
    printf("Raw         : 0x%08X\n", inst.raw);
    printf("Mnemonic    : %s\n", inst.mnemonic);
    printf("opcode      : %u\n", inst.opcode);
    printf("rd          : %u\n", inst.rd);
    printf("funct3      : %u\n", inst.funct3);
    printf("rs1         : %u\n", inst.rs1);
    printf("rs2         : %u\n", inst.rs2);
    printf("funct7      : %u\n", inst.funct7);
    printf("imm         : %d\n", inst.imm);

    return 0;
}