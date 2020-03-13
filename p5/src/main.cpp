#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/monomio.hpp"
#include "../include/polinomio.hpp"

using namespace std;

vector<Monomio> createMonomio(int size) {
  vector<Monomio> polinomio;
  for (int i = 0; i < size; i++) {
    int coef = rand() % 11;
    if (coef != 0) {
      Monomio monomio(coef, i);
      polinomio.push_back(monomio);
    }
  }
  return polinomio;
}

int main(int argc, char* argv[]) {
  try {
    vector<Monomio> polinomio;
    int size = atoi(argv[1]);
    int size2 = atoi(argv[2]);

    Polinomio firstPolinomio(createMonomio(size));
    Polinomio secondPolinomio(createMonomio(size2));

    firstPolinomio.write();
    cout << firstPolinomio;

    secondPolinomio.write();
    cout << secondPolinomio;


  } catch(char const* e) {
    cout << e << endl;
  }    
}