#include "mergeP.hpp"

mergeP::mergeP(vector<int> v) : Problema::Problema() {
  v_ = v;
}

mergeP::~mergeP() {}

bool mergeP::isCasoMinimo() {
	return (v_.size() < 2);
}

pair<Problema*,Problema*> mergeP::descomponer() {
	pair<Problema*,Problema*> subProblemas;
  
  vector<int> v1;
  vector<int> v2;
  int p = v_.size() / 2;

  for (int i = 0; i < p; i++) {
    v1.push_back(v_[i]);
  }

  for (int i = p; i < v_.size(); i++) {
    v2.push_back(v_[i]);
  }

  subProblemas.first = new mergeP(v1);
  subProblemas.second = new mergeP(v2);

  return subProblemas;

} 

void mergeP::solver(Solucion* s) {
	((mergeS*)s)->setValor(v_);
}