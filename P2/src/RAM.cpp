#include "../include/RAM.hpp"
#include <sstream>

using namespace std;

RAM::RAM(Program& program, ReadTape& read, WriteTape& write): 
    program_(program),
    read_(read), 
    write_(write)
{}

RAM::~RAM() {}

Memory RAM::getReg(void) {
    return reg_;
}

ReadTape RAM::getRTape(void) {
    return read_;
}

WriteTape RAM::getWTape(void) {
    return write_;
}

void RAM::ejecutar(int t) {
    for(program_.getPC(); program_.getPC() < program_.getProgram().size(); program_.incrPC()) {
        string name = program_.getInstr().getName();
        string operand = program_.getInstr().getOperand();
        int dir = program_.getInstr().getDir();
        int opcode = program_.getInstr().getOpcode();
        bool salta = false;
        string d;
        if(dir == 0) d = "directo";
        else if(dir == 1) d = "indirecto";
        else if(dir == 2) d = "inmediato";

        stringstream dato(operand); 
        int o = 0; 
        dato >> o; 

        if(program_.getInstr().getTypeInstr() != ETIQUETA) {
            totalInstr_++;
            if(opcode == LOAD) {
                reg_.load(o, dir);

                if(t == 1) {
                    cout << "LOAD: direccionamiento " << d << " con el operando " << operand << endl; 
                    program_.incrPC();
                    break;
                }   
            }

            else if(opcode == STORE) {
                reg_.store(o, dir);
                
                if(t == 1) {
                    cout << "STORE: direccionamiento " << d << " con el operando " << operand << endl; 
                    program_.incrPC();
                    break;
                }
            }

            else if(opcode == ADD) { 
                if(dir == DIRECTO) {
                    reg_.setAcc(reg_.getAcc() + reg_.getReg(o));
                }
                else if(dir == INDIRECTO) {
                    int aux = reg_.getReg(o);
                    reg_.setAcc(reg_.getAcc() + aux);
                }
                else if(dir == INMEDIATO) {
                    reg_.setAcc(reg_.getAcc() + o);
                }

                if(t == 1) {
                    cout << "ADD: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                    program_.incrPC();
                    break;
                }
            }

            else if(opcode == SUB) {
                if(dir == DIRECTO) {
                    reg_.setAcc(reg_.getAcc() - reg_.getReg(o));
                }
                else if(dir == INDIRECTO) {
                    int aux = reg_.getReg(o);
                    reg_.setAcc(reg_.getAcc() - aux);
                }
                else if(dir == INMEDIATO) {
                    reg_.setAcc( reg_.getAcc() - o);
                }

                if(t == 1) {
                    cout << "SUB: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                    program_.incrPC();
                    break;
                }
            }

            else if(opcode == MULT) {
                if(dir == DIRECTO) {
                    reg_.setAcc(reg_.getAcc() * reg_.getReg(o));
                }
                else if(dir == INDIRECTO) {
                    int aux = reg_.getReg(o);
                    reg_.setAcc(reg_.getAcc() * aux);
                }
                else if(dir == INMEDIATO) {
                    reg_.setAcc(reg_.getAcc() * o);
                }
                
                if(t == 1) {
                    cout << "MULT: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                    program_.incrPC();
                    break;
                }
            }

            else if(opcode == DIV) {
                string err = "Error: division 0";
                if(dir == DIRECTO) {
                    if(reg_.getReg(o) == 0) throw err;
                    else reg_.setAcc(reg_.getAcc() / reg_.getReg(o));
                }

                else if(dir == INDIRECTO) {
                    int aux = reg_.getReg(o);
                    if(aux == 0) throw err;
                    else reg_.setAcc(reg_.getAcc() / aux);
                }

                else if(dir == INMEDIATO) {
                    if(o == 0) throw err;
                    else reg_.setAcc(reg_.getAcc() / o);
                }

                if(t == 1) {
                    cout << "DIV: direccionamiento " << d << " -> " << reg_.getAcc() << " y " << operand << " y operando " << operand << endl;
                    program_.incrPC();
                    break;
                }
            }

            else if(opcode == READ) {
                reg_.read(o, read_.getValue());

                if(t == 1) {
                    cout << "READ: " << read_.getValue() << " y lo guardo en " << operand << endl;
                    program_.incrPC();
                    read_.incrementCabezal();

                    break;
                }
                read_.incrementCabezal();
            }

            else if(opcode == WRITE) {
                if(o == 0 && dir == DIRECTO) {
                    string err = "Error: can't WRITE 0";
                    throw err;
                }
                else if(dir == DIRECTO) {
                    write_.setTape(reg_.getReg(o));
                    write_.incrementCabezal();
                }
        
                else if(dir == INDIRECTO) {
                    int aux = reg_.getReg(o);
                    write_.setTape(aux);
                    write_.incrementCabezal();
                }
                else if(dir == INMEDIATO) {
                    write_.setTape(o);
                    write_.incrementCabezal(); 
                }

                if(t == 1) {
                    cout << "WRITE: direccionamiento " << d << " con el operando " << operand << endl;
                    program_.incrPC();
                    break;
                }
            }

            else if(opcode == JUMP) {
                // Recorro las etiquetas y si el operando del salto coincide con la etiqueta, PC = posicion etiqueta, si no PC++
                if(program_.jump(operand)) salta = true;

                if(t == 1) {
                    if(salta == false) {
                        program_.incrPC();
                    }
                    cout << "JUMP: " << operand << ". PC apunta a " << program_.getPC()  << endl;
                    salta = false;
                    break;
                }
            }

            else if(opcode == JGTZ) {
                if(program_.jgtz(operand, reg_.getAcc())) salta = true;

                if(t == 1) {
                    if(salta == false) {
                        program_.incrPC();
                    }
                    cout << "JGTZ: " << operand << ". PC apunta a " << program_.getPC() << " Acc: " << reg_.getAcc() << endl;
                    salta = false;
                    break;
                }
            }

            else if(opcode == JZERO) {
                if(program_.jzero(operand, reg_.getAcc())) salta = true;

                if(t == 1) {
                    if(salta == false) {
                        program_.incrPC();
                    }
                    cout << "JZERO: " << operand << ". Pc apunta a " << program_.getPC() << " Acc: " << reg_.getAcc() << endl;
                    salta = false;
                    break;
                }
            }

            else if(opcode == HALT) {
                if(t == 1) cout << "Paro el programa y escribo en la cinta de salida" << endl;
        
                write_.writeFile();
                break;
            }
        }
    }
}

int RAM::getTotalInstr(void) {
    return totalInstr_;
}

