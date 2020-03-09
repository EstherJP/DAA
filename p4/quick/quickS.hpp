#pragma once
#include <iostream>
#include "../framework/Solucion.h"

using namespace std;

class quickS : public Solucion {
  public:
    quickS();
    ~quickS();

    void resolver();
    void mezcla(pair<Solucion*,Solucion*>);
	  Solucion* getInstance();
    void setValor(vector<int> v);
};