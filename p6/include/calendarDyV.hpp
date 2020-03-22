#pragma once

#include <iostream>

#include "matrix.hpp"

class calendarDyV {
  private:
    Matrix calendario_;
    int equipos_;
  public:
    // Constructor por defecto
    calendarDyV();
    // Constructor con numero de equipos potencia de dos
    calendarDyV(int equipos, Matrix& calendario);
    // Destructor por defecto
    ~calendarDyV();
    // recursividad
    void crearTabla(int inf, int sup);
    void completarTabla(int eqSup, int eqInf, int diaSup, int diaInf, int equipo);
    //escribir calendario
    void write();

};