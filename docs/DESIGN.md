# **RISC-V RV32I Instruction Decoder**
## *MEDS Training Programme*
### **Module 2 Grand Assignment**
### *Design Document*

**Overview:**

The RISC-V RV32I Instruction Decoder is designed to translate 32-bit hexadecimal machine instructions into their corresponding human-readable assembly representation.

The decoder follows the RV32I instruction set architecture specification and supports all instruction formats required in the assignment.

The implementation emphasizes:

- modularity
- readability
- maintainability
- extensibility
- safe memory handling

The project was developed as part of the C Language for Hardware Engineers lab (MEDS Module 2).

**Project Architecture**

The project is organized into independent modules, each responsible for a specific task.

1. **main.c**</br>
    Responsibilities:
    - command-line argument parsing
    - loading input files
    - invoking the decoder
    - formatting output
    - maintaining instruction statistics
    - reporting valid and unknown instructions

2. **decoder.c**</br>
    Responsibilities:
    - extracting instruction fields
    - sign extension
    - instruction classification
    - mnemonic selection
    - instruction family decoding
    - assembly formatting

    Implemented decoding functions include:
    ~~~
    decode_instruction()
    decode_r_type()
    decode_i_type()
    decode_s_type()
    decode_b_type()
    decode_u_type()
    decode_j_type()
    print_instruction()
    ~~~

3. **memory.c**</br>
    Responsibilities:
    - opening hex files
    - reading machine instructions
    - little-endian memory storage
    - memory dump utilities

    Implemented functions include:
    ~~~
    load_hex_file()
    memory_dump()
    ~~~

**Instruction Representation**

Decoded instructions are represented using a structure named:
~~~
decoded_instr_t
~~~

The structure stores all relevant instruction fields.
~~~
typedef struct {
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
~~~
This abstraction allows different instruction formats to share a common representation.

**Enumerations**

Enumerations are used to improve readability and reduce the use of hard-coded values.

**Opcode Enumeration**
~~~
typedef enum {
    OP_LOAD,
    OP_IMM,
    OP_AUIPC,
    OP_STORE,
    OP_REG,
    OP_LUI,
    OP_BRANCH,
    OP_JALR,
    OP_JAL
} opcode_t;
~~~

**ALU Operations Enumeration**
~~~
typedef enum {
    ALU_ADD,
    ALU_SUB,
    ALU_AND,
    ALU_OR,
    ALU_XOR,
    ALU_SLL,
    ALU_SRL,
    ALU_SRA,
    ALU_SLT,
    ALU_SLTU
} alu_op_t;
~~~

**Bit Manipulation Strategy**

Instruction decoding heavily relies on bit manipulation.
Helper functions were implemented to isolate this functionality.

**Field Extraction**
~~~
extract_field()
~~~

Extracts arbitrary bit ranges from a 32-bit instruction.

Example:
~~~
opcode = bits [6:0]
rd = bits [11:7]
funct3 = bits [14:12]
rs1 = bits [19:15]
rs2 = bits [24:20]
funct7 = bits [31:25]
~~~

**Sign Extension**
~~~
sign_extend()
~~~

Used for:
- I-type immediates
- S-type immediates
- B-type offsets
- J-type offsets

Ensures negative immediates are represented correctly as signed integers.

**Instruction Decoding Flow**

Decoding begins by extracting the opcode. A switch statement dispatches execution to the appropriate decoder.

~~~
decode_instruction()
↓
R-Type
I-Type
S-Type
B-Type
U-Type
J-Type
↓
Mnemonic Selection
↓
Assembly Formatting
↓
Output
~~~

This hierarchical design reduces duplicated logic and simplifies maintenance.

**Supported Instruction Set**

The decoder currently supports:
1. R-Type
2. I-Type Arithmetic
3. I-Type Loads
4. S-Type
5. B-Type
6. U-Type
7. J-Type

For more details see README.md

**Unknown Instruction Handling**

Unsupported instructions are assigned the mnemonic:
~~~
UNKNOWN
~~~

This guarantees that invalid instructions do not terminate execution unexpectedly. The decoder remains robust even when malformed or unsupported machine code is encountered.

**Memory Management**

The memory subsystem allocates a fixed memory space of: 64 KB.
Instructions are stored in little-endian format.
Example:
~~~
0xDEADBEEF
↓
EF BE AD DE
~~~
The project was analyzed using Valgrind. Results indicate:
~~~
All heap blocks were freed.

0 bytes in 0 blocks.

ERROR SUMMARY: 0 errors
~~~

Thus the implementation satisfies the assignment requirement of:

- zero leaks
- zero invalid accesses
- zero memory errors

**Testing Methodology**

Testing was performed using four dedicated hex files.
~~~
r_type.hex
i_type.hex
branch.hex
mixed.hex
~~~

These collectively verify:
- arithmetic instructions
- logical instructions
- shifts
- loads
- stores
- branches
- jumps
- sign extension
- unknown instruction handling

Unit testing is additionally supported through:
~~~
test_decoder.c
~~~

**Build System**
Compilation is managed through a Makefile. Supported targets:
~~~
make

make clean

make test

make debug

make valgrind
~~~

The build system automates:
- compilation
- testing
- debugging
- memory verification

**Design Decisions**

Several design decisions were made to improve software quality.
- Structs were used to abstract decoded instructions.
- Enums improve readability.
- Helper functions isolate bit manipulation logic.
- Unknown instructions are safely handled.
- Separate source files improve modularity.
- Include guards prevent duplicate declarations.
- Constants are defined through macros instead of magic numbers.
- Git feature branches were used during development.

**Future Improvements**

Possible future extensions include:

- RV64I support
- compressed instruction decoding
- ELF file loading
- pipeline simulation
- register file visualization
- disassembler frontend
- graphical interface support

Author:</br>
***Noor Fatima***