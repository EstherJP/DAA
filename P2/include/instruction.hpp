#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class Instruction {
    private:
        string instr_;              // instruccion entera jump hola, halt, read 2, add =4...

        string nameInstr_;          // nombre instruccion

        string operand_;                 // operando o etiqueta 
        int dir_ = 0;                   // tipo de direccionamiento 0 directo 1 indirecto 2 directo

        int typeInstr_ = 4;              // tipo de intruccion: 0 operacion o 1 salto 2 etiqueta 3 halt

        string tag_;                  // etiqueta de salto
        int pos_ = 0;                //posicion de esa instruccion

        public:
            Instruction(string instr, int pos);  // primero comprueba si es legal la etiqueta
            ~Instruction();

            bool legalInstr(void);      // metodo para comprobar 0, no es legal, 1 es legal
         
            string getName(void);
            string getOperand(void);
            int getDir(void);
            int typeInstr(void);
            string getTag(void);
            int getPos(void);

            void showInfo(void);
};