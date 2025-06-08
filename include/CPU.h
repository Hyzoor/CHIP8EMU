#ifndef CPU_H
#define CPU_h
#include <cstdint>
#include "../include/Memory.h"

class CPU{

public:

    CPU(const Memory&);
    ~CPU();

    void init();
    void clockCycle();
    void fetchInstruction();
    void decodeExecuteInstruction();
    uint8_t getNibble(int);

private:
    uint8_t regV[16]{};
    uint16_t stack[16]{};
    uint16_t regI;
    uint8_t soundTimer, delayTimer;
    uint16_t programCounter;
    uint8_t stackPointer;
    Memory RAM;
    uint16_t instruction;
};

#endif