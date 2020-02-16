#include "../include/simulation.hpp"
#include <sstream>

using namespace std;

Simulation::Simulation(char* filename, ReadTape& read, WriteTape& write): 
    filename_(filename), 
    read_(read), 
    write_(write)
{
    readFile();
    createProgram();
}

Simulation::~Simulation() {}

void Simulation::readFile(void) {
    fstream file;
    file.open(filename_);

    if(!file.is_open()) throw "Error: program file don't exist";

    else {
        while (!file.eof()) {
            string instr;   

            file >> instr;
            for (int i = 0; i < instr.length(); i++){
		        instr[i] = tolower(instr[i]);
	        }

            if(instr.front() == ';' || instr.front() == '#') {
                getline(file, instr);
            }
             
            else if(instr.back() == ':') {  
                program_.push_back(instr); 
            }

            else if(instr == "halt") {
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

void Simulation::createProgram(void) {
    for(int i = 0; i < program_.size(); i++) {
        if(program_[i].back() == ':') {
            program_[i].pop_back();  
            pair<string, int> tag = make_pair(program_[i], i);
            tags_.push_back(tag);

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

void Simulation::showProgram(void) {
    for(int i = 0; i < program_.size(); i++) {
        cout << program_[i] << endl;
    }
    cout << endl;
}

Memory Simulation::getReg(void) {
    return reg_;
}

ReadTape Simulation::getRTape(void) {
    return read_;
}

WriteTape Simulation::getWTape(void) {
    return write_;
}

void Simulation::ejecutar(int t) {
    for(PC_; PC_ < legalProgram_.size(); PC_++) {
        string name = legalProgram_[PC_].getName();
        string operand = legalProgram_[PC_].getOperand();
        int dir = legalProgram_[PC_].getDir();
        string d;
        if(dir == 0) d = "directo";
        else if(dir == 1) d = "indirecto";
        else if(dir == 2) d = "inmediato";

        stringstream dato(operand); 
        int o = 0; 
        dato >> o; 
         
        if(name == "load") {
            reg_.load(o, dir);

            if(t == 1) {
                cout << "LOAD: direccionamiento " << d << " con el operando " << operand << endl; 
                PC_++;
                break;
            }   
        }

        else if(name == "store") {
            reg_.store(o, dir);
            
            if(t == 1) {
                cout << "STORE: direccionamiento " << d << " con el operando " << operand << endl; 
                PC_++;
                break;
            }
        }

        else if(name == "add") { 
            if(dir == 0) {
                reg_.setAcc(reg_.getAcc() + reg_.getReg(o));
            }
            else if(dir == 1) {
                int aux = reg_.getReg(o);
                reg_.setAcc(reg_.getAcc() + aux);
            }
            else if(dir == 2) {
                reg_.setAcc(reg_.getAcc() + o);
            }

            if(t == 1) {
                cout << "ADD: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                PC_++;
                break;
            }
        }

        else if(name == "sub") {
            if(dir == 0) {
                reg_.setAcc(reg_.getAcc() - reg_.getReg(o));
            }
            else if(dir == 1) {
                int aux = reg_.getReg(o);
                reg_.setAcc(reg_.getAcc() - aux);
            }
            else if(dir == 2) {
                reg_.setAcc( reg_.getAcc() - o);
            }

            if(t == 1) {
                cout << "SUB: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                PC_++;
                break;
            }
        }

        else if(name == "mult") {
            if(dir == 0) {
                reg_.setAcc(reg_.getAcc() * reg_.getReg(o));
            }
            else if(dir == 1) {
                int aux = reg_.getReg(o);
                reg_.setAcc(reg_.getAcc() * aux);
            }
            else if(dir == 2) {
                reg_.setAcc(reg_.getAcc() * o);
            }
            
            if(t == 1) {
                cout << "MULT: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                PC_++;
                break;
            }
        }

        else if(name == "div") {
            string err = "Error: division 0";
            if(dir == 0) {
                if(reg_.getReg(o) == 0) throw err;
                else reg_.setAcc(reg_.getAcc() / reg_.getReg(o));
            }

            else if(dir == 1) {
                int aux = reg_.getReg(o);
                if(aux == 0) throw err;
                else reg_.setAcc(reg_.getAcc() / aux);
            }

            else if(dir == 2) {
                if(o == 0) throw err;
                else reg_.setAcc(reg_.getAcc() / o);
            }

            if(t == 1) {
                cout << "DIV: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                PC_++;
                break;
            }
        }

        else if(name == "read") {
            reg_.read(o, read_.getValue());

            if(t == 1) {
                cout << "READ: " << read_.getValue() << " y lo guardo en " << operand << endl;
                PC_++;
                break;
            }

            read_.incrementCabezal();
        }

        else if(name == "write") {
            if(dir == 0) {
                if(reg_.getReg(o) == 0) throw "Error: can't WRITE 0";
                else {
                    write_.setTape(reg_.getReg(o));
                    write_.incrementCabezal();
                }
            }
            else if(dir == 1) {
                int aux = reg_.getReg(o);
                write_.setTape(aux);
                write_.incrementCabezal();
            }
            else if(dir == 2) {
                write_.setTape(o);
                write_.incrementCabezal(); 
            }

            if(t == 1) {
                cout << "WRITE: direccionamiento " << dir << " con el operando " << operand << endl;
                PC_++;
                break;
            }
        }

        else if(name == "jump") {
            for(auto i: tags_) {
                if(i.first == operand) {
                    PC_ = i.second;
                    break;
                }
                else if(t == 1) {
                    PC_++;
                    break;
                }
            }

            if(t == 1) {
                cout << "JUMP: " << operand << " a la posicion " << PC_  << endl;
                break;
            }
        }

        else if(name == "jgtz") {
            for(auto i: tags_) {
                if(reg_.getAcc() > 0 && i.first == operand) {
                    PC_ = i.second;
                    break;
                }
                else if(t == 1) {
                    PC_++;
                    break;
                }
            }

            if(t == 1) {
                cout << "JGTZ: " << operand << " a la posicion " << PC_ << " Acc: " << reg_.getAcc() << endl;
                break;
            }
        }

        else if(name == "jzero") {
            for(auto i: tags_) {
                if(reg_.getAcc() == 0 && i.first == operand) {
                    PC_ = i.second;
                    break;
                }
                else if(t == 1)  { 
                    PC_++;
                    break;
                }
            }

            if(t == 1) {
                cout << "JZERO: " << operand << " en la posicion " << PC_ << " Acc: " << reg_.getAcc() << endl;
                break;
            }
        }

         else if(name == "halt") {
            if(t == 1) cout << "Paro el programa y escribo en la cinta de salida" << endl;
    
            write_.writeFile();
            break;
        }
        totalInstr_++;
    }
}

int Simulation::getTotalInstr(void) {
    return totalInstr_;
}

