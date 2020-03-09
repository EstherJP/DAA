#include "quickS.hpp"

quickS::quickS() {}

quickS::~quickS() {}


void quickS::resolver() { 
  for(int i = 0; i < v_.size(); i++) {
    cout << v_[i] << " ";
  }
  cout << endl;
}

void quickS::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  vector<int> v1 = ((quickS*)subSoluciones.first)->v_;
  vector<int> v2 = ((quickS*)subSoluciones.second)->v_;

  for (int i = 0; i < v1.size(); i++) {
    v_.push_back(v1[i]);
  }

  for (int i = 0; i < v2.size(); i++) {
    v_.push_back(v2[i]);
  }
} 

Solucion* quickS::getInstance() {
  return new quickS();
}

void quickS::setValor(vector<int> v) {
  v_ = v;
}