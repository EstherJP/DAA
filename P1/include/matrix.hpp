#pragma once

#include <iostream>

// Clase matriz
class Matrix {
    private:
        int row_;
        int col_;
        int** m_;
        int** t_;

    public:

        // Constructor matriz vacía
        Matrix(int row, int col);   
        // Constructor matriz aleatoria
        Matrix(int row, int col, int s);
        // Destructor
        ~Matrix();

        // Rellenar la matriz con numerso aleatorios
        void build_matrix(int s);

        // Gettes y settes
        int get_row(void);
        int get_col(void);
        int** get_m(void);
        int get_value(int i, int j);
        int** get_t(void);
        int get_value_t(int i, int j);

        void set_value(int i, int j, int a);

        //trasponer
        void trasponer(void);

        // Imprimir matriz
        void write(void);
        void write_t(void);
};
