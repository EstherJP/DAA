#include "quickP.hpp"

quickP::quickP(vector<int> v) : Problema::Problema() {
  v_ = v;
}

quickP::~quickP() {}

bool quickP::isCasoMinimo() {
	return (v_.size() <= 2);
}

pair<Problema*,Problema*> quickP::descomponer() {
	pair<Problema*,Problema*> subProblemas;
  vector<int> v1;
  vector<int> v2;
  
  int i = 1;
  int j = v_.size() - 1;
  int pivote = 0;

  while (i < j) {
    while (v_[i] < v_[pivote]) {
      i++;
    } 
    while (v_[j] > v_[pivote]) {
      j--;
    }
    if ( i < j) {
      int aux = v_[i];
      v_[i] = v_[j];
      v_[j] = aux;
      i++;
      j--;
    }
  }

  int aux = v_[pivote];
  v_[pivote] = v_[j];
  v_[j] = aux;

  for (int k = 0; k <= j; k++) {
    v1.push_back(v_[k]);
  }

  for (int k = j + 1; k < v_.size(); k++) {
    v2.push_back(v_[k]);
  }

  subProblemas.first = new quickP(v1);
  subProblemas.second = new quickP(v2);

  return subProblemas;
} 

void quickP::solver(Solucion* s) {
  vector<int> aux;
  if (v_.size() == 2) {
    if (v_[0] > v_[1]) {
      aux.push_back(v_[1]);
      aux.push_back(v_[0]);
    } else {
      aux = v_;
    }
	  ((quickS*)s)->setValor(aux);
  } else {
	((quickS*)s)->setValor(v_);
  }
}
