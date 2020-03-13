#pragma once
#include <iostream>
#include <vector>

#include "monomio.hpp"

using namespace std;

class Polinomio {
  private:
    int grado_;
    int terminos_;
    vector<Monomio> polinomio_;
  
  public:
    Polinomio();
    Polinomio(/*int coef[], const int tam,*/ vector<Monomio> pol);
    void build();

    void write();

    vector<Monomio> getPolinomio() const;

    friend ostream& operator<<(ostream &sout, const Polinomio &p);
};