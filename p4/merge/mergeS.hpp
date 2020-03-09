#pragma once
#include <iostream>
#include "../framework/Solucion.h"

using namespace std;

class mergeS : public Solucion {
  public:
    mergeS();
    ~mergeS();

    void resolver();
    void mezcla(pair<Solucion*,Solucion*>);
	  Solucion* getInstance();
    void setValor(vector<int> v);
};