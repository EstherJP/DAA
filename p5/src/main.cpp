#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/monomio.hpp"
#include "../include/polinomio.hpp"
#include "../include/strategyBase.hpp"
#include "../include/strategy.hpp"
#include "../include/product.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  try {
    int size = atoi(argv[1]);
    int size2 = atoi(argv[2]);

    Polinomio firstPolinomio(size);
    Polinomio secondPolinomio(size2);

    cout << "Primer polinomio: " << firstPolinomio << endl;
    cout << "Segundo Polinomio: " << secondPolinomio << endl;

    Product* classicProduct;
    Product* DyVProduct;

    classicProduct = new Product(new StrategyClassic);
    DyVProduct = new Product(new StrategyDyV);

    // cout << "-----ClassicStrategy-----" << endl;
    // classicProduct->ProductInterface(firstPolinomio, secondPolinomio);

    cout << "-----DyVStrategy-----" << endl;
    DyVProduct->ProductInterface(firstPolinomio, secondPolinomio);

    delete classicProduct;
    delete DyVProduct;

  } catch(char const* e) {
    cout << e << endl;
  }    
}