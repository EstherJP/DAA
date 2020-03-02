#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include "../include/instruction.hpp"
#include "../include/program.hpp"
#include "../include/memory.hpp"
#include "../include/ReadTape.hpp"
#include "../include/WriteTape.hpp"

using namespace std;

class RAM {
    private:
        Program program_;
        Memory reg_;                        // Memoria de registros
        ReadTape read_;                     // Cinta de entrada
        WriteTape write_;                   // Cinta de salida

        int totalInstr_ = 0;                // Total de instrucciones ejecutadas

    public:
        RAM();   // Constructor por defecto
        RAM(Program& program, ReadTape& read, WriteTape& write);   // Constructor que lee el fichero y guarda el programa
        ~RAM();  // Destructor por defecto

        Memory getReg(void);        // Gettes
        ReadTape getRTape(void);
        WriteTape getWTape(void);
        int getTotalInstr(void);

       void ejecutar(int t = 0);   // Ejecuta el programa realizando las acciones de las instrucciones
};