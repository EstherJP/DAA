#pragma once

#include <iostream>
#include "matrix.hpp"

//Clase abstracta estrategia
class Strategy {
    public: 
        virtual void MatrixProduct(Matrix& a, Matrix& b) = 0;
};