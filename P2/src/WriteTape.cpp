#include "WriteTape.hpp"
#include <fstream>

using namespace std;

WriteTape::WriteTape(char* filename) : TapeBase(filename) {}

WriteTape::~WriteTape() {}

void WriteTape::readFile(void) {

    ofstream file();
    file.open(getFilename());

    if(!file.is_open()) {
        cout << "ERROR APERTURA" << endl;
    }

    else {
        while (!file.eof()) {
            for(int i = 0; i < getTape().size(); i++) {
                file << getTape()[i];
            }
        }
    } 
    file.close();
}