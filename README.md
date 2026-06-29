# **RISC-V RV32I Instruction Decoder**
## *MEDS Training Programme*
### **Module 2 Grand Assignment**

**Project Description:**

The RISC-V RV32I Instruction Decoder is a command-line tool that reads a hex file containing RISC-V machine instructions, decodes each instruction according to the RV321 ISA specification, and prints the human-readable assembly.

The decoder supports multiple instruction formats, performs proper sign extension of immediates, handles unknown instructions safely, and produces formatted assembly output.

It is designed as part of a C Language for Hardware Engineers lab (MEDS Module 2).

Supported instruction formats include:
- R-type
- I-type
- S-type
- B-type
- U-type
- J-type

The project also demonstrates modular C design, Makefile-based builds, testing, memory management, and Git workflow practices.

**Installation:**

Follow these instructions inside bash:

1. Clone the repository:
    ~~~
    git clone https://github.com/<your-username>/riscv-decoder.git
    cd riscv-decoder
    ~~~
2. Build the project:
    ~~~
    make
    ~~~
3. Build a debug version:
    ~~~
    make debug
    ~~~
4. Verify Valgrind installation:
    ~~~
    valgrind --version
    ~~~

**Project Structure:**
~~~
riscv-decoder/
├── README.md
├── Makefile
├── .gitignore
|
├── include/
│ ├── common.h
│ ├── decoder.h
│ └── memory.h
|
|── src/
│ ├── main.c
│ ├── decoder.c
│ └── memory.c
|
├── test/
│ ├── test_decoder.c
│ └── programs/
│   ├── r_type.hex
│   ├── i_type.hex
│   ├── branch.hex 
|
└── docs/ 
    └── DESIGN.md
~~~

**Usage:**

Basic usage:
~~~
./riscv-decoder test/programs/mixed.hex
~~~
Run automated tests:
~~~
make test
~~~
Run memory leak analysis:
~~~
make valgrind
~~~
Build debug executable:
~~~
make debug
~~~
Remove generated files:
~~~
make clean
~~~

**Supported RV32I Instructions:**

_R-Type:_
1. ADD
2. SUB
3. AND
4. OR
5. XOR
6. SLL
7. SRL
8. SRA
9. SLT
10. SLTU

_I-Type Arithmetic:_
1. ADDI
2. ANDI
3. ORI
4. XORI
5. SLTI
6. SLTIU
7. SLLI
8. SRLI
9. SRAI

_Loads:_
1. LB
2. LH
3. LW
4. LBU
5. LHU

_Stores:_
1. SB
2. SH
3. SW

_Branches:_
1. BEQ
2. BNE
3. BLT
4. BGE
5. BLTU
6. BGEU

_Jumps:_
1. JAL
2. JALR

_Upper Immediate:_
1. LUI
2. AUIPC

**Sample Output:**
~~~
RISC-V RV32I Instruction Decoder
================================

Loaded 8 instructions from test/programs/mixed.hex

Addr         Hex        Assembly
-----------------------------------------
0x00000000 00500113 addi   x2, x0, 5
0x00000004 00A00193 addi   x3, x0, 10
0x00000008 003100B3 add    x1, x2, x3
0x0000000C 40310133 sub    x2, x2, x3
0x00000010 0020A023 sw     x2, 0(x1)
0x00000014 0000A103 lw     x2, 0(x1)
0x00000018 FE209CE3 bne    x1, x2, -8
0x0000001C 004000EF jal    x1, 4

Decoded 8 instructions (8 valid, 0 unknown)
~~~

**Features:**
- RV32I instruction decoding
- Modular C implementation
- Proper sign extension
- Assembly formatting
- Unknown instruction detection
- Makefile automation
- Unit testing support
- Valgrind verified memory safety
- Git version control workflow
- Structured project organization

**Requirements:**
- GCC
- GNU Make
- Valgrind
- Linux / WSL Environment

Author:</br>
***Noor Fatima***