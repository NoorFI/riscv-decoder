#include "common.h"
#include "decoder.h"
#include "memory.h"

int main(int argc, char *argv[]){ //For command line arguments
    if(argc != 2){
        printf("Usage:\n");
        printf("%s <hex_file>\n",argv[0]);
        return 1;
    }

    uint8_t memory[MEMORY_SIZE] = {0};
    int instructions = load_hex_file(argv[1], memory);
    
    if(instructions < 0){
        return 1;
    }
    
    printf("Instructions Loaded: %d\n", instructions);
    printf("\n");
    
    memory_dump(memory, instructions * 4);
    return 0;
}