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

    printf("Loaded %d instructions\n", count);
    decoded_instr_t inst = {0};

    /* Temporary test instructions */

    decode_instruction(0x00500113, &inst);
    print_instructions(0x00000000, &inst);

    decode_instruction(0x003100B3, &inst);
    print_instructions(0x00000008, &inst);

    decode_instruction(0x0020A023, &inst);
    print_instructions(0x00000010, &inst);

    decode_instruction(0x004000EF, &inst);
    print_instructions(0x0000001C, &inst);

    return 0;
}