#include <iostream>
#include "../include/Memory.h"


int main(){


    Memory memory;
    std::string romPath = "../roms/test1.ch8";

    try{

        memory.loadROM(romPath);

        std::cout << "Rom cargado correctamente\n\n";
        
    }catch(std::runtime_error){
        std::cout << "No se ha podido leer correctamente el rom\n\n";
    }

    return 0;
}