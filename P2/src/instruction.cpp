#include "../include/instruction.hpp"

using namespace std;

Instruction::Instruction() {}

Instruction::Instruction(string instr, int pos): instr_(instr),  pos_(pos) {
    // Si es etiqueta 
    if(instr_.back() == ':') {
        instr_.pop_back();
        tag_ = instr_;
        typeInstr_ = 2;
    }

    // Si la instruccion es halt
    else if(instr_ == "halt") {
        nameInstr_ = instr_;
        typeInstr_ = 3;
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
                dir_ = 1;
            }

            else if(instr_[i] == '=') {
                dir_ = 2;
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

bool Instruction::legalInstr(void) {
    // Creo un vector string con las instrucciones de salto y otra con las instrucciones de operación
    vector<string> salto = {"jump", "jgtz", "jzero"};
    vector<string> operacion = {"load", "store", "add", "sub", "mult", "div", "read", "write"};
    // Recorro las instrucciones de salto y compruebo si pertenecen
    for(int i = 0; i < salto.size(); i++) {
        if(salto[i] == nameInstr_) {
            typeInstr_ = 1;
            break;
        }
    }
    // Compruebo si pertenecen a las instrucciones de operacion
    for(int i = 0; i < operacion.size(); i++) {
        if(operacion[i] == nameInstr_) {
            typeInstr_ = 0;
            break;
        }
    }
    // Si no son ni etiqueta ni intruccion, significa que la instruccion no existe
    if(typeInstr_ == 4) {
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


