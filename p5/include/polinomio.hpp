#pragma once
#include <iostream>
#include <vector>

#include "monomio.hpp"

using namespace std;

class Polinomio {
  protected:
    int grado_;
    int terminos_;
    vector<Monomio> polinomio_;
  
  public:
    Polinomio();
    Polinomio(const int tam);
    Polinomio(int coef[], const int tam);
    void build();

    void write();

    vector<Monomio> getPolinomio() const;
    int getTerminos();
    int getGrado();

    friend ostream& operator<<(ostream &sout, const Polinomio &p);
    friend ostream& operator<<(ostream &sout, const Polinomio* p);
};