#include "../include/ReadTape.hpp"
#include <fstream>

using namespace std;

ReadTape::ReadTape(char* filename) : TapeBase(filename) {
    readFile();
}

ReadTape::~ReadTape() {}

void ReadTape::readFile(void) {

    fstream file;
    file.open(getFilename());

    if(!file.is_open()) {
        cout << "ERROR APERTURA" << endl;
    }

    else {
        while (!file.eof()) {
            int n;

            file >> n;
            setTape(n);
        }
    } 
    file.close();
}