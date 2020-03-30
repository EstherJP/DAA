#include <iostream>
#include "../include/LCS.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  try {
    // cadenas por teclado
    if (argc == 3) {
      string first = argv[1];
      string second = argv[2];

      LCS lcs(second, first);
      lcs.LCSLength();
      lcs.reverseResult();

      lcs.write();
      cout << "Subsecuencia: " << lcs.getResult() << endl;
      cout << "Tamaño de la subsecuencia: " << lcs.getSubSize() << endl;

      if (!lcs.checkResult()) {
        cout << "El algoritmo no encontró la solución correcta" << endl;
      }

    // Cadenas aleatorias
    } else if (argc == 4) {
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
      
      if (!lcs.checkResult()) {
        cout << "El algoritmo no encontró la solución correcta" << endl;
      } 
    } else {
      throw "Error: parámetros de entrada";
    }
  } catch (char const *e) {
    cout << e << endl;
  }
}