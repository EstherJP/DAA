#pragma once

#include <iostream>
#include "strategy.hpp"
#include "matrix.hpp"

using namespace std;

// Clase contexto
class Context {
    private:
        Strategy* strategy_;

    public:
        //Constructor por defecto
        Context(): strategy_(NULL) {}

        //Contructor con puntero a la estrategia querida
        Context(Strategy* strategy): strategy_(strategy) {}

        // Llamada a la estrategia según el contexto
        void ContextInterface(Matrix& a, Matrix& b) {
            if(strategy_)
                strategy_->MatrixProduct(a, b);
            else
		        cout << "ERROR: Strategy not set" << endl;
        }
};