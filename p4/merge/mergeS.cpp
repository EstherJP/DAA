#include "mergeS.hpp"

mergeS::mergeS() {}

mergeS::~mergeS() {}


void mergeS::resolver() {  //¿?
  for(int i = 0; i < v_.size(); i++) {
    cout << v_[i] << " ";
  }
  cout << endl;
}

void mergeS::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  vector<int> v1 = (((mergeS*)subSoluciones.first))->v_;
  vector<int> v2 = ((mergeS*)subSoluciones.second)->v_;

  int i = 0;
  int j = 0;

  if (v1.size() < 1 || v2.size() < 1) {
    v_.push_back(v1[0]);
  } else {
    while ((i < v1.size()) && (j < v2.size())) {
      if (v1[i] < v2[j]) {
          v_.push_back(v1[i]);
          i++;
      } else {
        v_.push_back(v2[j]);
        j++;
      }
    }

    while (i < v1.size()) {
      v_.push_back(v1[i]);
      i++;
    }

    while (j < v2.size()) {
      v_.push_back(v2[j]);
      j++;
    }
  }
} 

Solucion* mergeS::getInstance() {
  return new mergeS();
}

void mergeS::setValor(vector<int> v) {
  v_ = v;
}