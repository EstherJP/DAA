#pragma once

#include <iostream>

#include "polinomio.hpp"
#include "strategyBase.hpp"
#include <cmath>
#include <math.h>

using namespace std;

class StrategyClassic : public Strategy {
  public:
    Polinomio* polinomioProduct(Polinomio* firstPolinomio, Polinomio* secondPolinomio) {
      int sum = 0;
      int coef[firstPolinomio->getGrado() + secondPolinomio->getGrado() + 1];

      for (int i = 0; i <= 2 * firstPolinomio->getTerminos() - 2; i++) {
        for (int j = 0; j <= i; j++) {
          if (j  > firstPolinomio->getGrado() + 1 || (i - j) > secondPolinomio->getGrado() + 1) {
            sum += 0;
          } else {
            sum += firstPolinomio->getPolinomio()[j].getCoeficiente() * secondPolinomio->getPolinomio()[i - j].getCoeficiente();
          }
        }
        coef[i] = sum;
        sum = 0;
      }

      Polinomio* resultado = new Polinomio(coef, firstPolinomio->getGrado() + secondPolinomio->getGrado() + 1);
    }
};

class StrategyDyV: public Strategy {
  public:     
    pair<Polinomio*, Polinomio*> dividirPolinomio(Polinomio* &polinomio) {
	    pair<Polinomio*, Polinomio*> polinomios;
      int sizeLow = polinomio->getTerminos() / 2;
      int sizeHigh = ceil((double)(polinomio->getTerminos()) / 2);
      bool flag = false;

      if (sizeLow == 0) {
        sizeLow = 1;
        flag = true;
      }

      int low[sizeLow];
      int high[sizeHigh];

      if (flag) {
        low[0] = {0};
        high[0] = {polinomio->getPolinomio()[0].getCoeficiente()};
      } else {
        for (int i = 0; i < sizeLow; i++) {
          low[i] = polinomio->getPolinomio()[i].getCoeficiente();
        }
      }

      int iter = 0;
      for (int i = sizeLow; i < polinomio->getTerminos(); i++) {
        high[iter] = polinomio->getPolinomio()[i].getCoeficiente();
        iter++;
      }
    
      polinomios.first = new Polinomio(low, sizeLow);
      polinomios.second = new Polinomio(high, sizeHigh);

      return polinomios;
    }

    Polinomio* polinomioProduct(Polinomio* firstPolinomio, Polinomio* secondPolinomio) {
      if (firstPolinomio->getTerminos() == 1 && secondPolinomio->getTerminos() == 1) {
        Monomio resMult = firstPolinomio->getPolinomio()[0] * secondPolinomio->getPolinomio()[0];
        int coef[firstPolinomio->getTerminos()] = {resMult.getCoeficiente()};

        Polinomio* res = new Polinomio(coef, firstPolinomio->getTerminos());
        return res;
      } else {
        pair<Polinomio*, Polinomio*> primeraDivision = dividirPolinomio(firstPolinomio);
        Polinomio* plow = primeraDivision.first;
        Polinomio* phigh = primeraDivision.second;

        pair<Polinomio*, Polinomio*> segundaDivision = dividirPolinomio(secondPolinomio);
        Polinomio* qlow = segundaDivision.first;
        Polinomio* qhigh = segundaDivision.second;

        Polinomio* rlow = polinomioProduct(plow, qlow);
        Polinomio* rm = polinomioProduct(*(plow) + *(phigh), *(qlow) + *(qhigh));
        Polinomio* rhigh = polinomioProduct(phigh, qhigh);

        Polinomio* resultado = *(rm) - *(rlow);
        resultado = *(resultado) - *(rhigh);
        resultado = *(resultado) * (firstPolinomio->getTerminos() / 2);
        resultado = *(rlow) + *(resultado);

        Polinomio* aux;
        if (firstPolinomio->getTerminos() % 2 == 0) {
          aux = *(rhigh) * (firstPolinomio->getTerminos());
        } else {
          aux = *(rhigh) * (firstPolinomio->getTerminos() - 1);
        }
        resultado = *(resultado) + *(aux);
        return resultado;
      }
    }
};