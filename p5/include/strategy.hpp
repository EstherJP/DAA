#pragma once

#include <iostream>

#include "polinomio.hpp"
#include "strategyBase.hpp"
#include <cmath>
#include <math.h>

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
    pair<Polinomio*, Polinomio*> dividirPolinomio(Polinomio& polinomio) {
	    pair<Polinomio*, Polinomio*> polinomios;
      int sizeLow = polinomio.getTerminos() / 2;
      int sizeHigh = ceil((double)(polinomio.getTerminos()) / 2);

      int low[sizeLow];
      int high[sizeHigh];

      for (int i = 0; i < sizeLow; i++) {
        low[i] = polinomio.getPolinomio()[i].getCoeficiente();
      }

      int iter = 0;
      for (int i = sizeLow; i < polinomio.getTerminos(); i++) {
        high[iter] = polinomio.getPolinomio()[i].getCoeficiente();
        iter++;
      }

      polinomios.first = new Polinomio(low, sizeLow);
      polinomios.second = new Polinomio(high, sizeHigh);

      return polinomios;
    }

    void polinomioProduct(Polinomio& firstPolinomio, Polinomio& secondPolinomio) {
      dividirPolinomio(firstPolinomio);
      dividirPolinomio(secondPolinomio);

      Polinomio* plow = dividirPolinomio(firstPolinomio).first;
      Polinomio* phigh = dividirPolinomio(firstPolinomio).second;

      cout << "Parte baja p: " << plow;
      cout << "Parte alta p: " << phigh << endl;

      Polinomio* qlow = dividirPolinomio(secondPolinomio).first;
      Polinomio* qhigh = dividirPolinomio(secondPolinomio).second;

      cout << "\nParte baja q: " << qlow << endl;
      cout << "Parte alta q: " << qhigh << endl;

      // polinomioProduct();
      // polinomioProduct();
      // polinomioProduct();
      

    }
};