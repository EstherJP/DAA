#pragma once

#include <iostream>
#include "strategy.hpp"
#include "polinomio.hpp"

using namespace std;

// Clase contexto
class Product {
    private:
        Strategy* strategy_;

    public:
        //Constructor por defecto
        Product(): strategy_(NULL) {}

        //Contructor con puntero a la estrategia querida
        Product(Strategy* strategy): strategy_(strategy) {}

        // Llamada a la estrategia según el contexto
        void ProductInterface(Polinomio* firstPolinomio, Polinomio* secondPolinomio) {
            if(strategy_)
                strategy_->polinomioProduct(firstPolinomio, secondPolinomio);
            else
		        cout << "ERROR: Strategy not set" << endl;
        }
};