/*

Quino's 4-Bit CPU Assembler
By: Joaquin S. Santos II

Thanks for giving it a try!

 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

uint8_t machineCode;
std::string codeLine, mnemonic;
int operand;
std::map<std::string, uint8_t> opcode =
{
    {"NOP", 0x0},
    {"LDA", 0x1},
    {"STA", 0x2},
    {"LDI", 0x3},
    {"ADD", 0x4},
    {"SUB", 0x5},
    {"AND", 0x6},
    {"OR", 0x7},
    {"XOR", 0x8},
    {"JMP", 0x9},
    {"JZ", 0xA},
    {"JNZ", 0xB},
    {"SETP", 0xC},
    {"INC", 0xD},
    {"DEC", 0xE},
    {"HLT", 0xF},
};


bool writeAssembly(std::istream& input, std::ostream& output)
{
    int lineNum = 0, nextLineCounter = 0;
    std::stringstream outCode;
    outCode << "v2.0 raw\n";

    while(std::getline(input, codeLine))
    {
        std::stringstream op(codeLine);
        op >> mnemonic;
        op >> operand;
        if(opcode.find(mnemonic) == opcode.end())
        { 
            std::cerr << "Warning in line ["<< lineNum << "]! " << "Opcode not found! Aborting assembly process\n";
            break;
        }
        if(operand > 16)
            std::cerr <<"Warning in line ["<< lineNum << "]! " << "Operand greater than 16 detected, operand will only be seen as 0x0F\n";
        
        machineCode = (opcode[mnemonic] << 4) | (operand & 0x0F);
        outCode << std::hex << std::setw(2) << std::setfill('0')<< +machineCode;
        if(nextLineCounter < 8)
        {
            outCode << "\n";
            nextLineCounter = 0;
        }
        else
        {
            outCode << " ";
            nextLineCounter++;
        }
        lineNum++;
        
    }
    output << outCode.str();
    return 1;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr <<"Warning no input file provided!\n" 
        << "Usage: assemble.exe <inputFile.asm> [outputFile.hex]\n" 
        << "Providing an outputFile is optional. Default output filename is out.hex";

        return 1;
    }
    else if (argc < 3)
    {
        std::ifstream input(argv[1]);
        std::ofstream output("out.hex");
        if(writeAssembly(input,output))
            std::cout<<"Hex file out.hex succesfully written\n";
    }
    else
    {
        std::ifstream input(argv[1]);
        std::ofstream output(argv[2]);
        if(writeAssembly(input,output))
            std::cout<<"Hex file " << argv[2] << " succesfully written\n";
    }
    return 0;
    
}