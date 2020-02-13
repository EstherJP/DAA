#include <iostream>

#include "tapeBase.hpp"
#include "ReadTape.hpp"
#include "instruction.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    char* input = argv[1];

    TapeBase *read;

    read = new ReadTape(input);
    read->readFile();
}