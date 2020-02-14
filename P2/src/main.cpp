#include <iostream>

#include "tapeBase.hpp"
#include "ReadTape.hpp"
#include "WriteTape.hpp"
#include "instruction.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    char* input = argv[1];
    char* output = argv[2];

    ReadTape read(input);
    WriteTape write(output);

    read.readFile();

    write.setTape(4);
    write.incrementCabezal();
    write.setTape(7);
    write.incrementCabezal();

    write.writeFile();
}