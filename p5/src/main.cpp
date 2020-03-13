#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/monomio.hpp"
#include "../include/polinomio.hpp"
#include "../include/strategyBase.hpp"
#include "../include/strategy.hpp"
#include "../include/product.hpp"

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

    Product* classicProduct;
    Product* DyVProduct;

    classicProduct = new Product(new StrategyClassic);
    DyVProduct = new Product(new StrategyDyV);

    classicProduct->ProductInterface(firstPolinomio, secondPolinomio);
    // DyVProduct->ProductInterface(firstPolinomio, secondPolinomio);

    delete classicProduct;
    delete DyVProduct;

  } catch(char const* e) {
    cout << e << endl;
  }    
}