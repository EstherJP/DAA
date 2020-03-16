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

    vector<Monomio>& getPolinomio();
    int getTerminos();
    int getGrado();
    void setMonomio(Monomio m, int i);

    void extendZero(int size);
  
    friend ostream& operator<<(ostream &sout, Polinomio &p);
    friend ostream& operator<<(ostream &sout, Polinomio* p);

    friend Polinomio* operator+(Polinomio &x, Polinomio &y);
    friend Polinomio* operator-(Polinomio &x, Polinomio &y);
    friend Polinomio* operator*(Polinomio &x, const int &exp);
};