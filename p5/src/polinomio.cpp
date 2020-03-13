#include "../include/polinomio.hpp"

using namespace std;

Polinomio::Polinomio() {}
Polinomio::Polinomio(/*int coef[], const int tam,*/ vector<Monomio> p):
  polinomio_(p)
{
  build();
}

void Polinomio::build() {
  terminos_ = polinomio_.size();
  int maxExpo = 0;
  
  for (int i = 0; i < terminos_; i++) {
    if (polinomio_[i].getExponente() > maxExpo) {
      maxExpo = polinomio_[i].getExponente();
    }
  }
  grado_ = maxExpo;
}

void Polinomio::write() {
  cout << "Grado: " << grado_ << endl;
  cout << "Nº terminos: " << terminos_ << endl;
  // cout << "Polinomio: " << polinomio_ << endl;
}

int Polinomio::getTerminos() {
  return terminos_;
}

int Polinomio::getGrado() {
  return grado_;
}

vector<Monomio> Polinomio::getPolinomio() const {
  return polinomio_;
}

ostream& operator<<(ostream &sout, const Polinomio &p) {
  for (int i = 0; i < p.getPolinomio().size(); i++) {
    if (i == p.getPolinomio().size() - 1) {
      cout << p.getPolinomio()[i];
    } else {
      cout << p.getPolinomio()[i] << " + ";
    }
  }
  cout << endl;
}