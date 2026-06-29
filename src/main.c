#include "common.h"
#include "decoder.h"
#include "memory.h"

int main(int argc, char *argv[]){ //For command line arguments
    if(argc!=2){
        printf("Usage: %s file.hex\n",argv[0]);
        return 1;
    }

    uint8_t memory[MEMORY_SIZE]={0};
    int count = load_hex_file(argv[1], memory);

    if(count<0){
        printf("Error opening file\n");
        return 1;
    }

    printf("RISC-V RV32I Instruction Decoder\n");
    printf("================================\n\n");

    printf("Loaded %d instructions from %s\n\n", count, argv[1]);
    printf("%-12s %-10s %s\n", "Addr", "Hex", "Assembly");

    printf("-----------------------------------------\n");

    int valid = 0;
    int unknown = 0;

    decoded_instr_t inst;

    for(int i = 0; i < count; i++){
        uint32_t address = i*4;
        uint32_t instruction = memory[address] | (memory[address+1]<<8) | (memory[address+2]<<16) | (memory[address+3]<<24);
        decode_instruction(instruction,&inst);
        print_instructions(address,&inst);

        if(strcmp(inst.mnemonic, "UNKNOWN")==0){
            unknown++;
        }
        else{
            valid++;
        }
    }

    printf("\n");
    printf("Decoded %d instructions (%d valid, %d unknown)\n", count, valid, unknown);

    return 0;
}