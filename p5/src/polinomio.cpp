#include "../include/polinomio.hpp"

using namespace std;

Polinomio::Polinomio() {}

Polinomio::Polinomio(const int tam): 
  terminos_(tam),
  grado_(tam - 1)
{
  build();
}
    
Polinomio::Polinomio(int coef[], const int tam):
  terminos_(tam),
  grado_(tam - 1)
{
  for (int i = 0; i < terminos_; i++) {
    polinomio_.push_back(Monomio(coef[i], i));
  }
}

void Polinomio::build() {
  for (int i = 0; i < terminos_; i++) {
    int coef = rand() % 11;
    polinomio_.push_back(Monomio(coef, i));
  }
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

ostream& operator<<(ostream &sout, const Polinomio* p) {
  for (int i = 0; i < p->getPolinomio().size(); i++) {
    if (i == p->getPolinomio().size() - 1) {
      cout << p->getPolinomio()[i];
    } else {
      cout << p->getPolinomio()[i] << " + ";
    }
  }
  cout << endl;
}