#include <iostream>
#include "../include/LCS.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    throw "Error: Introducir tamaño de la subsecuencia";
  } 

  size_t firstSize = atoi(argv[1]);
  size_t secondSize = atoi(argv[2]);

  LCS lcs(firstSize, secondSize);
  lcs.write();
}