#pragma once

#include <iostream>

#include "polinomio.hpp"
#include "strategyBase.hpp"

using namespace std;

//Clase estrategia por filas
class StrategyClassic : public Strategy {
  public:
    void polinomioProduct(Polinomio& firstPolinomio, Polinomio& secondPolinomio) {
      int sum = 0;
      int sum2 = 0;
      vector<Monomio> res;
      cout << "-----ClassicStrategy-----" << endl;
      for (int i = 0; i < 2 * firstPolinomio.getTerminos() - 2; i++) {
        for (int j = 0; j < i; j++) {
          sum += firstPolinomio.getPolinomio()[i].getCoeficiente() * secondPolinomio.getPolinomio()[i - j].getCoeficiente();
        }
        Monomio m(sum, i);
        res.push_back(m);
      }
      Polinomio resultado(res);
      cout << "Primer polinomio: " << firstPolinomio << endl;
      cout << "Segungo polinomio: " << secondPolinomio << endl; 
      cout << "Resultado: " << endl;
      cout << resultado << endl;
    }
};

//Clase estrategia por columnas
class StrategyDyV: public Strategy {
  public:     
    void polinomioProduct(Polinomio& firstProduct, Polinomio& secondProduct) {
      cout << "-----DyVStrategy-----" << endl;
          

    }
};