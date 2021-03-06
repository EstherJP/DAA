#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "matrix.hpp"

class calendarDyV {
  private:
    Matrix calendario_;
    int equipos_;
    bool isPotenciaDos_;
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
    // Comprobar resultado
    bool checkResult();

};