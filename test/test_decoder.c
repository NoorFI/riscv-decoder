#include "decoder.h"
#include <assert.h>

int main() {

    decoded_instr_t inst;

    decode_instruction(0x003100B3, &inst);
    assert(strcmp(inst.mnemonic, "add") == 0);

    decode_instruction(0x00500113, &inst);
    assert(strcmp(inst.mnemonic, "addi") == 0);

    decode_instruction(0x004000EF, &inst);
    assert(strcmp(inst.mnemonic, "jal") == 0);

    return 0;
}