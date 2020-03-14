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
      int coef[firstPolinomio.getGrado() + secondPolinomio.getGrado() + 1];

      for (int i = 0; i <= 2 * firstPolinomio.getTerminos() - 2; i++) {
        for (int j = 0; j <= i; j++) {
          if (j  > firstPolinomio.getGrado() || (i - j) > secondPolinomio.getGrado()) {
            sum += 0;
          } else {
            sum += firstPolinomio.getPolinomio()[j].getCoeficiente() * secondPolinomio.getPolinomio()[i - j].getCoeficiente();
          }
        }
        coef[i] = sum;
        sum = 0;
      }

      Polinomio resultado(coef, firstPolinomio.getGrado() + secondPolinomio.getGrado() + 1);
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