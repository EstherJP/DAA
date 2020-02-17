#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class Instruction {
    private:
        string instr_;              // Instrucción 

        string nameInstr_;          // Nombre instrucción
        string operand_;            // Operando o etiqueta 
        int dir_ = 0;               // Tipo de direccionamiento: 0 directo, 1 indirecto, 2 inmediato
        int typeInstr_ = 4;         // Tipo de intruccion: 0 operacion, 1 salto, 2 etiqueta, 3 halt
        int pos_ = 0;               // Posicion de la instruccion sin tener en cuenta los comentarios

        string tag_;                // Etiqueta de la instrucción de salto, si lo es

        public:
            Instruction();          // Constructor por defecto
            Instruction(string instr, int pos);  // Contructor: comprueba si la instruccion es legal y la almacena.
            ~Instruction();         // Destructor por defecto

            bool legalInstr(void);      // Comprobar: 0 no legal, 1 legal
         
            string getName(void);
            string getOperand(void);
            int getDir(void);
            int getTypeInstr(void);
            string getTag(void);
            int getPos(void);

            void showInfo(void);    // Muestra la informacion de la instruccion
};