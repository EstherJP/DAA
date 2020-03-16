#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "../include/monomio.hpp"
#include "../include/polinomio.hpp"
#include "../include/strategyBase.hpp"
#include "../include/strategy.hpp"
#include "../include/product.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  try {
    int size = atoi(argv[1]);

    Polinomio* firstPolinomio = new Polinomio(size);
    Polinomio* secondPolinomio = new Polinomio(size);

    Product* classicProduct;
    Product* DyVProduct;

    classicProduct = new Product(new StrategyClassic);
    DyVProduct = new Product(new StrategyDyV);

    chrono::time_point<chrono::system_clock> start, end;

    cout << "-----ClassicStrategy-----" << endl;
    start = chrono::system_clock::now();
    classicProduct->ProductInterface(firstPolinomio, secondPolinomio);
    end = chrono::system_clock::now();

    chrono::duration<float, milli> duration = end-start;
    cout << "Tiempo transcurrido: " << duration.count() << "ms" << endl << endl;

    cout << "-----DyVStrategy-----" << endl;
    start = chrono::system_clock::now();
    DyVProduct->ProductInterface(firstPolinomio, secondPolinomio);
    end = chrono::system_clock::now();

    duration = end-start;
    cout << "Tiempo transcurrido: " << duration.count() << "ms" << endl << endl;

    delete classicProduct;
    delete DyVProduct;

  } catch(char const* e) {
    cout << e << endl;
  }    
}