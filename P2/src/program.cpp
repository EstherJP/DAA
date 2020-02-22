#include "../include/program.hpp"

using namespace std;

Program::Program() {}


Program::Program(char *filename): filename_(filename) {
    readFile();
    createProgram();
    // showLegalProgram();
}

Program::~Program() {}

void Program::readFile(void) {
    fstream file;
    file.open(filename_);

    // Si no se abre lanza un error
    string err = "Error: program file doesn't exist";
    if(!file.is_open()) throw err;

    else {
        // Recorro el fichero
        while (!file.eof()) {
            string instr;   
            // Paso la instruccion a minuscula
            file >> instr;

            if(instr.front() == ';' || instr.front() == '#') {
                getline(file, instr);
            }
             
            else if(instr.back() == ':') {   // un if con haly y :
                program_.push_back(instr); 
            }

            else if(instr == "halt" || instr == "HALT") {
                    program_.push_back(instr);

            }
            else {
                string aux;
                aux = instr;
                aux += ' ';
                file >> instr;
                aux+= instr;

                program_.push_back(aux);
            }
        }
    } 
    file.close();
}
// Creo el programa
void Program::createProgram(void) {
    for(int i = 0; i < program_.size(); i++) {
        if(program_[i].back() == ':') {
            // lo meto en el vector de pair
            program_[i].pop_back();  
            pair<string, int> tag = make_pair(program_[i], i);
            tags_.push_back(tag);
            // lo meto en el programa legal
            program_[i].push_back(':');
            Instruction instr(program_[i], i);
            legalProgram_.push_back(instr);
        }

        else {
            Instruction instr(program_[i], i);
            legalProgram_.push_back(instr);
        }
    }
}

void Program::showProgram(void) {
    for(int i = 0; i < program_.size(); i++) {
        cout << program_[i] << endl;
    }
    cout << endl << endl;
    cout << "---Etiquetas---" << endl;
    for(auto i: tags_) {
        cout << "La etiqueta " << i.first << " se encuentra en la posicion " << i.second << endl;
    }
    cout << endl;
}

void Program::showLegalProgram(void) {
    for(int i = 0; i < legalProgram_.size(); i++) {
        legalProgram_[i].showInfo();
    }
    cout << endl;
}

vector<Instruction> Program::getProgram(void) {
    return legalProgram_;
}

int Program::getPC(void) {
    return PC_;
}

void Program::incrPC(void) {
    PC_++;
}

Instruction Program::getInstr(void) {
    return legalProgram_[PC_];
}

bool Program::jump(string tag) {
    for(auto i: tags_) {
        if(i.first == tag) {
            PC_ = i.second;
            return true;
        }
    }
    return false;
}

bool Program::jgtz(string tag, int acc) {
    for(auto i: tags_) {
        if(acc > 0 && i.first == tag) {
            PC_ = i.second;
            return true;
        }
    }
    return false;
}

bool Program::jzero(string tag, int acc) {
    for(auto i: tags_) {
        if(acc == 0 && i.first == tag) {
            PC_ = i.second;
            return true;
        }
    }
    return false;
}


