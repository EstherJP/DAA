#include "../include/monomio.hpp"

using namespace std;

Monomio::Monomio() {}
Monomio::Monomio(int coef, int exp): coeficiente_(coef), exponente_(exp) {}
Monomio::~Monomio() {}

int Monomio::evaluar(int x) {
  return coeficiente_ * pow(x, exponente_);
}

int Monomio::getCoeficiente() const {
  return coeficiente_;
}

void Monomio::setCoeficiente(int c) {
  coeficiente_ = c;
}

int Monomio::getExponente() const {
  return exponente_;
}

void Monomio::setExponente(int e) {
  exponente_ = e;
}

ostream& operator<<(ostream &sout, const Monomio &s) {
  if (s.getCoeficiente() != 0) {
    if (s.getExponente() != 0 && s.getExponente() != 1) {
      sout << s.getCoeficiente() << "x" << "^" << s.getExponente();
    } else if (s.getExponente() == 1) {
      sout << s.getCoeficiente() << "x";
    } else {
      sout << s.getCoeficiente();
    }
  }
  return sout;
}

istream& operator>>(istream &sin, Monomio &r) {
  int c, e;
  sin >> c >> e;
  r.setCoeficiente(c);
  r.setExponente(e);
  return sin;
}

Monomio operator+(const Monomio &x, const Monomio &y) {
  Monomio res;
  if (x.getExponente() == y.getExponente()) {
    res.setExponente(x.getExponente());
    res.setCoeficiente(x.getCoeficiente() + y.getCoeficiente());
  } else {
    throw "ERR: Cannot + 2 monomios";
  }
  return res;
}

Monomio operator*(const Monomio &x, const Monomio &y) {
  Monomio res;
  res.setExponente(x.getExponente() + y.getExponente());
  res.setCoeficiente(x.getCoeficiente() * y.getCoeficiente());
  return res;
}