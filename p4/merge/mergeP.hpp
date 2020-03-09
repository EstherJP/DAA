#pragma once
#include <iostream>
#include "../framework/Problema.h"
#include <math.h>
#include "mergeS.hpp"
#include "mergeP.hpp"

using namespace std;

class mergeP : public Problema {
public:
  mergeP(vector<int> v_);
	~mergeP();

	bool isCasoMinimo();
	pair<Problema*,Problema*> descomponer();
	void solver(Solucion* s);

};
