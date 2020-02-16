#include "../include/WriteTape.hpp"
#include <fstream>

using namespace std;

WriteTape::WriteTape(char* filename) : TapeBase(filename) {}

WriteTape::~WriteTape() {}

void WriteTape::writeFile(void) {

    ofstream file(getFilename());

    for(int i = 0; i < getTape().size(); i++) {
        file << getTape()[i] << endl;
    }
    file.close();
}