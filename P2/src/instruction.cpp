#include "../include/instruction.hpp"

using namespace std;

Instruction::Instruction(string instr, int pos): instr_(instr) {
    // si es etiqueta
    if(instr_.back() == ':') {
        instr_.pop_back();
        tag_ = instr_;
        posTag_ = pos;
        typeInstr_ = 2;
    }

    else if(instr_ == "halt") {
        nameInstr_ = instr_;
        typeInstr_ = 3;
    }

    else {
        // leo la instruccion
        for(auto i: instr_){
            if(i != ' ') {
                nameInstr_ += i;
            }
            else {
                break;
            }
        }

        // leo el operando de forma muy rara
        string r;
        for(int i=instr_.length()-1; i>=0; i--) {
            r += instr_[i];
        }

        string aux;
        for(auto i: r) {
            if(i == '*') {
                dir_ = 1;
            }

            else if(i == '=') {
                dir_ = 2;
            }

            else if(i != ' ') {
                aux += i;
            }

            else if(i == ' '){
                break;
            }

            else {
                dir_ = 0;
            }
        }

        for(int i=aux.length()-1; i>=0; i--) {
            operand_ += aux[i];
        }
    }
    legalInstr(); // compruebo si es legal
    // showInfo();
}

Instruction::~Instruction() {}

bool Instruction::legalInstr(void) {
    vector<string> salto = {"jump", "jgtz", "jzero"};
    vector<string> operacion = {"load", "store", "add", "sub", "mult", "div", "read", "write"};

    for(int i = 0; i < salto.size(); i++) {
        if(salto[i] == nameInstr_) {
            typeInstr_ = 1;
            break;
        }
    }

    for(int i = 0; i < operacion.size(); i++) {
        if(operacion[i] == nameInstr_) {
            typeInstr_ = 0;
            break;
        }
    }

    if(typeInstr_ == 4) {
        cout << "No existe la instruccion: " << nameInstr_ << endl;
    }
}

string Instruction::getName(void) {
    return nameInstr_;
}

string Instruction::getOperand(void) {
    return operand_;
}

int Instruction::getDir(void) {
    return dir_;
}

int Instruction::typeInstr(void) {
    return typeInstr_;
}

string Instruction::getTag(void) {
    return tag_;
}

int Instruction::getPosTag(void) {
    return posTag_;
}

void Instruction::showInfo(void) {
    cout << "---INSTRUCCIONES---" << endl;
    if(!tag_.empty()) {
        cout << "Etiqueta: " << tag_ << endl;
        cout << "postag: " << posTag_ << endl << endl;
    }

    else {
        cout << "Instru: " << nameInstr_ << endl;
        cout << "Operand: " << operand_ << endl;
        cout << "Tipo: " << typeInstr_ << endl;
        cout << "dir: " << dir_ << endl << endl;
    }
}


