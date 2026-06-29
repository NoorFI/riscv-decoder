#include "common.h"
#include "decoder.h"
#include "memory.h"

int main(int argc, char *argv[]){ //For command line arguments
    uint32_t instruction = 0x00A28233;
    
    printf("Instruction = 0x%08X\n", instruction);
    printf("\n");
    printf("opcode  = %u\n", extract_field(instruction, 6, 0));
    printf("rd      = %u\n", extract_field(instruction, 11, 7));
    printf("func3   = %u\n", extract_field(instruction, 14, 12));
    printf("rs1     = %u\n", extract_field(instruction, 19, 15));
    printf("rs2     = %u\n", extract_field(instruction, 24, 20));
    printf("func7   = %u\n", extract_field(instruction, 31, 25));
    printf("\n");
    
    printf("Sign extend test:\n");
    printf("%d\n", sign_extend(0xFFF, 12));
    
    return 0;
}