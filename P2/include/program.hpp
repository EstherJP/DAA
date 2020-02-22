#pragma once

#include <iostream>
#include <fstream>
#include <utility>
#include "instruction.hpp"

using namespace std;

class Program {
    private:
        char* filename_;                    // Nombre fichero del programa
        vector<string> program_;            // Programa sin comprobar
        vector<Instruction> legalProgram_;  // Memoria de instruccciones del programa
        int PC_= 0;                         // Program Counter

        vector<pair<string, int>> tags_;    // Vector que contiene el nombre de la etiqueta y su posicion en el programa

    public:
        Program();   // Constructor por defecto
        Program(char* filename);   // Constructor que lee el fichero y guarda el programa
        ~Program();  // Destructor por defecto

        void readFile(void);        // Lee el programa
        void createProgram(void);   // Crea la memoria de instrucciones asegurandose de que son legales

        void showProgram(void);     // Muestra el programa
        void showLegalProgram(void);

        vector<Instruction> getProgram(void);
        int getPC(void);
        void incrPC(void);
        Instruction getInstr(void);

        bool jump(string tag);
        bool jgtz(string tag, int acc);
        bool jzero(string tag, int acc);
};