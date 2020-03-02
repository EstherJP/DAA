#include <iostream>

#include "../include/tapeBase.hpp"
#include "../include/ReadTape.hpp"
#include "../include/WriteTape.hpp"
#include "../include/instruction.hpp"
#include "../include/memory.hpp"
#include "../include/RAM.hpp"
#include "../include/program.hpp"


using namespace std;

int main(int argc, char* argv[]) {
    try {
        string err;
        if(argc != 5) {
            err = "Error: insuficient arguments";
            throw err;
        }

        char* fileRam = argv[1];
        char* input = argv[2];
        char* output = argv[3];
        char* c_debug = argv[4];
        int debug = atoi(c_debug);

        ReadTape read(input);
        WriteTape write(output);
        Program program(fileRam);

        RAM sim(program, read, write);

        if(debug == 0) {
            sim.ejecutar();
            cout << "El total de instrucciones ejecutadas ha sido " << sim.getTotalInstr() << endl;
        }

        else if(debug == 1) {
            char opcion;
            do {
                cout << ">h" << endl;
                cout << "r: ver los registros" << endl;
                cout << "t: traza" << endl;
                cout << "e: ejecutar" << endl;
                cout << "s: desensamblador" << endl;
                cout << "i: ver cinta entrada" << endl;
                cout << "o: ver cinta salida" << endl;
                cout << "h: ayuda" << endl;
                cout << "x: salir" << endl;
                cout << "> ";

                cin >> opcion;
                cout << endl;

                switch (opcion) {
                    case 'r':
                        cout << "---Memoria---" << endl;
                        sim.getReg().showMemory();
                        break;
                    
                    case 't': 
                        cout << "---Traza---" << endl;
                        sim.ejecutar(1);
                        cout << endl;
                        break;
                    
                    case 'e':
                        cout << "---Ejecutar---" << endl;
                        sim.ejecutar();
                        cout << "El total de instrucciones ejecutadas ha sido " << sim.getTotalInstr() << endl;
                        opcion = 'x';
                        break;
                    
                    case 's': 
                        cout << "---Desensamblar---" << endl;
                        program.showProgram();
                        break;
                    
                    case 'i':
                        cout << "---Cinta de entrada---" << endl;
                        sim.getRTape().showTape();
                        cout << endl;
                        break;

                    case 'o':
                        cout << "---Cinta de salida---" << endl;
                        sim.getWTape().showTape();
                        cout << endl;
                        break;
                    
                    case 'h':
                        cout << "---Ayuda---" << endl;
                        break;

                    case 'x':
                        cout << "Saliendo..." << endl;
                        break;
                    default:
                        cout << "---Opción inválida---" << endl;
                        break;
                }
            } while(opcion != 'x');
        } 
    } catch(string& err) {
        cout << err << endl;
    }
}
