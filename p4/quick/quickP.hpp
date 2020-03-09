#pragma once
#include <iostream>
#include "../framework/Problema.h"
#include <math.h>
#include "quickS.hpp"
#include "quickP.hpp"

using namespace std;

class quickP : public Problema {
public:
  quickP(vector<int> v_);
	~quickP();

	bool isCasoMinimo();
	pair<Problema*,Problema*> descomponer();
	void solver(Solucion* s);

};