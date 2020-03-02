#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>

// PONER CONSTANTES EN PLAN DIRECTO 0 Y ASIII
// CAMBIAR QUE ME LEA EN MAYUS Y MINUS

#define DIRECTO 0
#define INDIRECTO 1
#define INMEDIATO 2

#define OPERACION 0
#define SALTO 1
#define ETIQUETA 2
#define HLT 3
#define BAD_INSTR 4

#define LOAD 1
#define STORE 2
#define ADD 3
#define SUB 4
#define MULT 5
#define DIV 6
#define READ 7
#define WRITE 8
#define JUMP 9
#define JGTZ 10
#define JZERO 11
#define HALT 12

using namespace std;

class Instruction {
    private:
        string instr_;              // Instrucción 

        string nameInstr_;          // Nombre instrucción
        string operand_;            // Operando o etiqueta 
        int dir_ = DIRECTO;               // Tipo de direccionamiento: 0 directo, 1 indirecto, 2 inmediato
        int typeInstr_ = BAD_INSTR;         // Tipo de intruccion: 0 operacion, 1 salto, 2 etiqueta, 3 halt
        int pos_ = 0;               // Posicion de la instruccion sin tener en cuenta los comentarios
        int opcode_;                 // Identificador en numero de la instruccion

        string tag_;                // Etiqueta de la instrucción de salto, si lo es

        public:
            Instruction();          // Constructor por defecto
            Instruction(string instr, int pos);  // Contructor: comprueba si la instruccion es legal y la almacena.
            ~Instruction();         // Destructor por defecto

            void legalInstr(void);      // Comprobar: 0 no legal, 1 legal
         
            string getName(void);
            string getOperand(void);
            int getDir(void);
            int getTypeInstr(void);
            string getTag(void);
            int getPos(void);
            int getOpcode(void);

            void showInfo(void);    // Muestra la informacion de la instruccion
};