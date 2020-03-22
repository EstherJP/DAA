#include "../include/calendarDyV.hpp"

using namespace std;

calendarDyV::calendarDyV(){}

calendarDyV::calendarDyV(int equipos, Matrix& calendario): 
  calendario_(calendario),
  equipos_(equipos)
{
  crearTabla(0, equipos_ - 1);
}

calendarDyV::~calendarDyV() {}

void calendarDyV::completarTabla(int eqInf, int eqSup, int diaInf, int diaSup, int equipo) {
  for (int j = diaInf; j <= diaSup; j++) {
    calendario_.setValue(eqInf, j, equipo + j - diaInf + 1);
  }
  for (int i = eqInf + 1; i <= eqSup; i++) {
    // Intercambio contrincante
    calendario_.setValue(i, diaInf, calendario_.getValue(i - 1, diaSup)); // el ultimo contricante de i - 1 se el primer contrincante de i
    for (int j = diaInf + 1; j <= diaSup; j++) {
      // rotamos contricantes
      calendario_.setValue(i, j, calendario_.getValue(i - 1, j - 1));
    }
  }
}

void calendarDyV::crearTabla(int inf, int sup) {
  // Caso base: si solo compiten dos, compiten entre ellos
  if (sup - 1 == inf) {
    calendario_.setValue(inf, 0, sup + 1);
    calendario_.setValue(sup, 0, inf + 1);
  } else {
    int medio = ((sup + inf) / 2);
    crearTabla(inf, medio);               // primera subsolucion: participantes del 1 a 2^(k - 1) - 1
    crearTabla(medio + 1, sup);      // segunda subsolucion: participantes del 2^(k - 1) a 2^n uñtimo o equipos idk
   
    // lo del profe
    completarTabla(inf, medio, medio - inf, sup - inf - 1, medio + 1);
    completarTabla(medio + 1, sup, medio - inf, sup - inf - 1, inf);

  }
}

void calendarDyV::write() {
  calendario_.write();
}
