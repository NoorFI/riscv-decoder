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
    memory_dump(memory,64);

    return 0;
}