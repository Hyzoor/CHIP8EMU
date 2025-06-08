#include "../include/CPU.h"
#include <cstdint>
#include <stdexcept>

CPU::CPU(const Memory &memory){
    RAM = memory;
    init();
}

CPU::~CPU() {};

void CPU::init(){
    regI = 0;
    soundTimer = 0;
    delayTimer = 0;
    stackPointer = 0;
    instruction = 0;
    programCounter = 0x200;
}

void CPU::fetchInstruction(){

    uint8_t msB = RAM.read(programCounter);
    uint8_t lsB = RAM.read(programCounter + 0x1);
    instruction = msB << 4 | lsB;
    programCounter += 0x02;
}

uint8_t CPU::getNibble(int i){

    uint8_t nibble = 0;
    switch (i){

    case 1:
        nibble = instruction & 0xF000 >> 12;
        break;
    case 2:
        nibble = instruction & 0x0F00 >> 8;
        break;
    case 3:
        nibble = instruction & 0x00F0 >> 4;
        break;
    case 4:
        nibble = instruction & 0x000F;
        break;
    default:
        throw std::out_of_range("Nibble i must be 1-4");
    }

    return nibble;
}

void CPU::decodeExecuteInstruction(){

    uint8_t opcode = instruction & 0xF000;
    uint8_t x = getNibble(2);
    uint8_t y = getNibble(3);
    uint8_t n = getNibble(4);
    uint8_t nn = y << 4 | n;
    uint16_t nnn = x << 8 | nn;

    switch (opcode){

    case 0x0:
        switch (instruction){
            
        case 0x00E0: // todo clear screen;
            break;
        }

        break;

    case 0x1:
        programCounter = nnn;
        break;

    case 0x6:
        regV[x] = nn;
        break;

    case 0x7:
        regV[x] = regV[x] + nn;
        break;

    case 0xA:
        regI = nnn;
        break;

    case 0xD:
        // Draw function;
        break;
    }
}