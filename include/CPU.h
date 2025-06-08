#ifndef CPU_H
#define CPU_h
#include <cstdint>
#include "../include/Memory.h"
#include "../include/Display.h"

class CPU{

public:

    CPU(const Memory&, const Display&);
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
    uint16_t instruction;
    Display display;
    Memory RAM;
};

#endif