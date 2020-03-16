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

void Polinomio::extendZero(int size) {
  for (int i = terminos_; i < terminos_ + size; i++) {
    polinomio_.push_back(Monomio(0, i));
  }
  terminos_ += size; 
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

void Polinomio::setMonomio(Monomio m, int i) {
  polinomio_[i] = m;
}

Polinomio* operator+(Polinomio &x, Polinomio &y) {
  if (x.getTerminos() < y.getTerminos()) {
    x.extendZero(y.getTerminos() - x.getTerminos());
  } else if (x.getTerminos() > y.getTerminos()) {
    y.extendZero(x.getTerminos() - y.getTerminos());
  }

  int coef[x.getTerminos()];
  for (int i = 0; i < x.getTerminos(); i++) {
      coef[i] = x.getPolinomio()[i].getCoeficiente() + y.getPolinomio()[i].getCoeficiente();
  }

  Polinomio* resultado = new Polinomio(coef, x.getTerminos());
  return resultado;
}

Polinomio* operator-(Polinomio &x, Polinomio &y) {
  if (x.getTerminos() < y.getTerminos()) {
    x.extendZero(y.getTerminos() - x.getTerminos());
  } else if (x.getTerminos() > y.getTerminos()) {
    y.extendZero(x.getTerminos() - y.getTerminos());
  }

  int coef[x.getTerminos()];
  for (int i = 0; i < x.getTerminos(); i++) {
      coef[i] = x.getPolinomio()[i].getCoeficiente() - y.getPolinomio()[i].getCoeficiente();
  }

  Polinomio* resultado = new Polinomio(coef, x.getTerminos());
  return resultado;
}

Polinomio* operator*(Polinomio &x, const int &exp){
  int coef[x.getTerminos() + exp];
  for (int i = 0; i < exp; i++) {
      coef[i] = 0;
  }
  for (int i = exp; i < (x.getTerminos() + exp); i++) {
      coef[i] = x.getPolinomio()[i - exp].getCoeficiente();
  }

  Polinomio* resultado = new Polinomio(coef, x.getTerminos() + exp);
  return resultado;
}
