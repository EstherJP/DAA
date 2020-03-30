#include <iostream>
#include "../include/LCS.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1) {
    string first, second;
    cout << "Introduzca primera subsecuencia: ";
    cin >> first;
    cout << "Introduzca segunda subsecuencia: ";
    cin >> second;
    cout << endl;

    LCS lcs(second, first);
    lcs.LCSLength();
    lcs.reverseResult();
    cout << "Subsecuencia: " << lcs.getResult() << endl;
    cout << "Tamaño de la subsecuencia: " << lcs.getSubSize() << endl;

  } else if (argc == 3) {
    size_t firstSize = atoi(argv[1]);
    size_t secondSize = atoi(argv[2]);

    LCS lcs(firstSize, secondSize);
    // LLamo a la table
    lcs.LCSLength();

    // Le doy la vuelta a la subcadena
    lcs.reverseResult();

    lcs.write();
    cout << "Subsecuencia: " << lcs.getResult() << endl;
    cout << "Tamaño de la subsecuencia: " << lcs.getSubSize() << endl;
  } else {
    throw "Error: parámetros de entrada";
  }
}