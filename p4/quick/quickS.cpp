#include "quickS.hpp"

quickS::quickS() {}

quickS::~quickS() {}


void quickS::resolver() { 
  bool ordenado;
  for(int i = 0; i < v_.size(); i++) {
    cout << v_[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < v_.size() - 1; i++) {
    if (v_[i] < v_[i + 1]) {
      ordenado = true;
    } else {
      ordenado = false;
      break;
    }
  }
  if (ordenado == true) {
    cout << "El vector está ordenado correctamente.\n";
  } else {
    cout << "El vector no está ordenado correctamente.\n";
  }
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