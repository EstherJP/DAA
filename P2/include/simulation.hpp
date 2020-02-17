#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>
#include <utility>
#include "../include/instruction.hpp"
#include "../include/memory.hpp"
#include "../include/ReadTape.hpp"
#include "../include/WriteTape.hpp"

using namespace std;

class Simulation {
    private:
        char* filename_;                    // Nombre fichero del programa
        vector<string> program_;            // Programa sin comprobar
        vector<Instruction> legalProgram_;  // Memoria de instruccciones del programa
        int PC_= 0;                         // Program Counter

        int totalInstr_ = 0;                // Total de instrucciones ejecutadas

        vector<pair<string, int>> tags_;    // Vector que contiene el nombre de la etiqueta y su posicion en el programa

        Memory reg_;                        // Memoria de registros
        ReadTape read_;                     // Cinta de entrada
        WriteTape write_;                   // Cinta de salida

    public:
        Simulation();   // Constructor por defecto
        Simulation(char* filename, ReadTape& read, WriteTape& write);   // Constructor que lee el fichero y guarda el programa
        ~Simulation();  // Destructor por defecto

        void readFile(void);        // Lee el programa
        void createProgram(void);   // Crea la memoria de instrucciones asegurandose de que son legales

        Memory getReg(void);        // Gettes
        ReadTape getRTape(void);
        WriteTape getWTape(void);
        int getTotalInstr(void);

        void ejecutar(int t = 0);   // Ejecuta el programa realizando las acciones de las instrucciones

        void showProgram(void);     // Muestra el programa
        void showLegalProgram(void);
};