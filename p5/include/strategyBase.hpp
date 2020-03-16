#pragma once

#include <iostream>
#include "polinomio.hpp"

//Clase abstracta estrategia
class Strategy {
    public: 
        virtual Polinomio* polinomioProduct(Polinomio* firstPolinomio, Polinomio* secondPolinomio) = 0;
};