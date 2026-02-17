# 4BitCPU-Logisim
I created a 4-Bit CPU in Logisim with its own assembler made with C++! Thank you for visiting this repo!

## Hard Requirements
```
Logisim Evolution
C++ Compiler (I use minGW)
```

## How to use assembler
Compile the C++ file first
```
g++ 4BitCPUEmulator.cpp -o 'assemble.exe'
```

Now you can run the assembler using this syntax
```
assemble.exe <inputFile.asm> [outputFile.hex]
```
**Entering an output file name is optional. Default output file name is out.hex**

In this case you can just enter
```
assemble.exe test.asm
```
to quickly assemble the sample assembly code and import it in logisim.

# Instruction Set

## NOP (No Operation)

**Syntax:**
```
NOP
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x0` | NOP | — | No-operation instruction | Does nothing |

---

## LDA (Load Accumulator)

**Syntax:**
```
LDA addr
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x1` | LDA | addr | Load instruction | ACC ← RAM[PAGE:addr] |

---

## STA (Store Accumulator)

**Syntax:**
```
STA addr
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x2` | STA | addr | Store instruction | RAM[PAGE:addr] ← ACC |

---

## LDI (Load Immediate)

**Syntax:**
```
LDI imm
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x3` | LDI | imm | Immediate load instruction | ACC ← immediate (0–15) |

---

## ADD (Add Immediate)

**Syntax:**
```
ADD imm
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x4` | ADD | imm | Arithmetic instruction | ACC ← ACC + immediate (0–15) |

---

## SUB (Subtract Immediate)

**Syntax:**
```
SUB imm
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x5` | SUB | imm | Arithmetic instruction | ACC ← ACC − immediate (0–15) |

---

## AND (Logical AND)

**Syntax:**
```
AND imm
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x6` | AND | imm | Logical instruction | ACC ← ACC AND immediate (0–15) |

---

## OR (Logical OR)

**Syntax:**
```
OR imm
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x7` | OR | imm | Logical instruction | ACC ← ACC OR immediate (0–15) |

---

## XOR (Logical XOR)

**Syntax:**
```
XOR imm
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x8` | XOR | imm | Logical instruction | ACC ← ACC XOR immediate (0–15) |

---

## JMP (Jump)

**Syntax:**
```
JMP addr
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0x9` | JMP | addr | Unconditional jump | PC ← PAGE:addr |

---

## JNZ (Jump if Not Zero)

**Syntax:**
```
JZ addr
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0xA` | JZ | addr | Conditional jump | Jump if Zero flag = 0 |

---

## JZ (Jump if Zero)

**Syntax:**
```
JNZ addr
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0xB` | JNZ | addr | Conditional jump | Jump if Zero flag = 1 |

---

## SETP (Set Page)

**Syntax:**
```
SETP page
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0xC` | SETP | page | Page control instruction | PAGE ← operand |

---

## INC (Increment Accumulator)

**Syntax:**
```
INC
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0xD` | INC | — | Unary arithmetic instruction | ACC ← ACC + 1 |

---

## DEC (Decrement Accumulator)

**Syntax:**
```
DEC
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0xE` | DEC | — | Unary arithmetic instruction | ACC ← ACC − 1 |

---

## HLT (Halt)

**Syntax:**
```
HLT
```

| Opcode (hex) | Mnemonic | Operand | Instruction Class | Description |
|-------------|----------|---------|-------------------|-------------|
| `0xF` | HLT | — | Processor control instruction | Halt CPU execution |
