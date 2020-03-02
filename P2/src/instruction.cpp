#include "../include/instruction.hpp"

using namespace std;

Instruction::Instruction() {}

Instruction::Instruction(string instr, int pos): instr_(instr),  pos_(pos) {
    // Si es etiqueta 
    if(instr_.back() == ':') {
        instr_.pop_back();
        tag_ = instr_;
        typeInstr_ = ETIQUETA;
    }

    // Si la instruccion es halt
    else if(instr_ == "halt" || instr == "HALT") {
        nameInstr_ = instr_;
        opcode_ = HALT;
        typeInstr_ = HLT;
    }

    else {
        // Leo el nombre de la instruccion
        for(auto i: instr_){
            if(i != ' ') {
                nameInstr_ += i;
            }
            else {
                break;
            }
        }

        // Leo el operando y compruebo se direccionamiento
        string aux;
        for(int i = instr_.length()-1; i >= 0; i--) {
            if(instr_[i] == '*') {
                dir_ = INDIRECTO;
            }

            else if(instr_[i] == '=') {
                dir_ = INMEDIATO;
            }

            else if(instr_[i] != ' ') {
                aux += instr_[i];
            }

            else if(instr_[i] == ' '){ // He cambiado aquí
                break;
            }
        }
        // Le doy la vuelta a la cadena ya que la he leido al reves
        for(int i = aux.length()-1; i >= 0; i--) {
            operand_ += aux[i];
        }
    }
    legalInstr(); // Compruebo si la instrucción es legal
    // showInfo();
}

Instruction::~Instruction() {}

void Instruction::legalInstr(void) {
    if(nameInstr_ == "LOAD" || nameInstr_ == "load") {
        opcode_ = LOAD;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "STORE" || nameInstr_ == "store") {
        opcode_ = STORE;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "ADD" || nameInstr_ == "add") {
        opcode_ = ADD;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "SUB" || nameInstr_ == "sub") {
        opcode_ = SUB;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "MULT" || nameInstr_ == "mult") {
        opcode_ = MULT;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "DIV" || nameInstr_ == "div") {
        opcode_ = DIV;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "READ" || nameInstr_ == "read") {
        opcode_ = READ;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "WRITE" || nameInstr_ == "write") {
        opcode_ = WRITE;
        typeInstr_ = OPERACION;
    }

    else if(nameInstr_ == "JUMP" || nameInstr_ == "jump") {
        opcode_ = JUMP;
        typeInstr_ = SALTO;
    }

    else if(nameInstr_ == "JGTZ" || nameInstr_ == "jgtz") {
        opcode_ = JGTZ;
        typeInstr_ = SALTO;
    }

    else if(nameInstr_ == "JZERO" || nameInstr_ == "jzero") {
        opcode_ = JZERO;
        typeInstr_ = SALTO;
    }

    // Si no son ni etiqueta ni intruccion, significa que la instruccion no existe
    if(typeInstr_ == BAD_INSTR) {
        string pos = to_string(pos_);
        string err = "Error: illegal_instruction at line " + pos;
        throw err;
    }
}

// Gettes
string Instruction::getName(void) {
    return nameInstr_;
}

string Instruction::getOperand(void) {
    return operand_;
}

int Instruction::getDir(void) {
    return dir_;
}

int Instruction::getTypeInstr(void) {
    return typeInstr_;
}

string Instruction::getTag(void) {
    return tag_;
}

int Instruction::getPos(void) {
    return pos_;
}

int Instruction::getOpcode(void) {
    return opcode_;
}

// Informacion de la instruccion
void Instruction::showInfo(void) {
    if(!tag_.empty()) {
        cout << "Etiqueta: " << tag_ << endl;
        cout << "Pos: " << pos_ << endl;
    }

    else {
        cout << "Instr: " << nameInstr_ << endl;
        cout << "Operand: " << operand_ << endl;
        cout << "Tipo: " << typeInstr_ << endl;
        cout << "Pos: " << pos_ << endl;
        cout << "Dir: " << dir_ << endl << endl;
    }
}


