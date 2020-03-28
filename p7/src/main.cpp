#include <iostream>
#include "../include/LCS.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    throw "Error: Introducir tamaño de la subsecuencia";
  } 

  size_t firstSize = atoi(argv[1]);
  size_t secondSize = atoi(argv[2]);

  // string second = "abcdaf";
  // string first = "acbcf";

  LCS lcs(firstSize, secondSize);
  // LLamo a la table
  lcs.LCSLength();

  // Le doy la vuelta a la subcadena
  lcs.reverseResult();

  lcs.write();
  cout << "Subsecuencia: " << lcs.getResult() << endl;
  cout << "Tamaño de la subsecuencia: " << lcs.getSubSize() << endl;

  // lcs.showDiff(table, 1, 1);
  // cout << endl;
}