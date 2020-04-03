#include <iostream>

#include "../include/matrix.hpp"
#include "../include/calendarDyV.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  try {
    int EQUIPOS = atoi(argv[1]);
    if (argc == 1) {
      throw "ERROR: introducir numero de equipos";
    }

    bool isPotenciaDos = false;
    int newSize;
    for (int i = 0; i < EQUIPOS; i++) {
      if (EQUIPOS == pow(2,i)) {
        isPotenciaDos = true;
        break;
      } else {
        newSize = pow(2, i);
        if (newSize > EQUIPOS) {
          break;
        }
      }
    }

    if (isPotenciaDos == true) {
      cout << "Calendario deportivo con " << EQUIPOS << " equipos" << endl;
      Matrix cal(EQUIPOS);
      calendarDyV calendario(EQUIPOS, cal);
      calendario.write();
      if (calendario.checkResult() == false) {
        cout << "El resultado está mal\n";
      }
    } else {
      cout << "Calendario deportivo con " << EQUIPOS << " equipos" << endl;
      cout << "Los 0 significan que ese día el equipo descansa ese día" << endl;
      Matrix cal(newSize);
      calendarDyV calendario(EQUIPOS, cal);
      calendario.write();
      if (calendario.checkResult() == false) {
        cout << "El resultado está mal\n";
      }
    }
  } catch (char const* e)  {
    cout << e << endl;
  }
}