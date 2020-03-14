#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Monomio {
  private:
    int coeficiente_;
    int exponente_;

  public:
    Monomio();
    Monomio(int coef, int exp);
    ~Monomio();

    int evaluar(int x);

    int getCoeficiente() const;
    void setCoeficiente(int c);

    int getExponente() const;
    void setExponente(int e);

    friend ostream& operator<<(ostream &sout, const Monomio &s);
    friend istream& operator>>(istream &sin, Monomio &r);

    friend Monomio operator+(const Monomio &x, const Monomio &y);
    friend Monomio operator*(const Monomio &x, const Monomio &y);
};