#include "memory.h"

int load_hex_file(const char *filename, uint8_t *memory){
    //Parameters: filename is the path to the hex file, memory is pointing to the beginning of simulated memory.
    //It returns no. of instructions loaded.

    FILE *fp = fopen(filename, "r"); //file pointer

    if (fp == NULL) {
        perror("Failed to open file");
        return -1;
    }

    uint32_t instruction; //current instruction
    size_t address = 0; //address inside memory
    int count = 0; //no. of instr loaded (to be returned)

    while(fscanf(fp, "%x", &instruction) == 1){
        memory[address] = instruction & 0xFF;

        for(size_t i = 1; i < 4; i++){
            memory[address + i] = (instruction >> (8*i)) & 0xFF;
        }

        address +=4;
        count++;
    }

    fclose(fp);
    return count;
}
void memory_dump(const uint8_t *memory, size_t size){
    //Parameters: size is the number of bytes to be displayed.

    for (size_t i = 0; i < size; i++){
        if(i % 16 == 0){
            printf("%04zX: ", i); //Print address every 16 bits
        }
        
        printf("%02X ", memory[i]); //Print current byte

        if ((i + 1) % 16 == 0){
            printf("\n"); //After every 16 bits print new line
        }
    }

    if (size % 16 != 0){
        printf("\n");
    }
}