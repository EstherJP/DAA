#pragma once

#include <iostream>

// Clase matriz
class Matrix {
  private:
    int row_;
    int col_;
    int** m_;

  public:
    // Constructor por defecto
    Matrix();
    // Constructor matriz vacía
    Matrix(int row, int col);   
    // Destructor por defecto
    ~Matrix();
    // Contruir matriz
    void build(int row, int col);
    // Imprimir matriz
    void write(void);
    // Get matriz
    int** getMatrix(void);
    // Get valor de la posición
    int getValue(int i, int j);
    // Set valor en la posicion
    void setValue(int i, int j, int value);
    // Get filas
    int getRow();
    // Get columnas
    int getCol();
};
