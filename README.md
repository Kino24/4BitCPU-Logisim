# 4BitCPU-Logisim
I created a 4-Bit CPU in Logisim with its own assembler made with C++! Thank you for visiting this repo!

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
