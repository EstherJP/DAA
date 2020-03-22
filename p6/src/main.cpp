#include <iostream>

#include "../include/matrix.hpp"
#include "../include/calendarDyV.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  int EQUIPOS = atoi(argv[1]);
  if (argc == 0) {
    cout << "ERROR: introducir numero de equipos" << endl;
  }

  Matrix cal(EQUIPOS);
  calendarDyV calendario(EQUIPOS, cal);

  cout << "Calendario deportivo con " << EQUIPOS << " equipos" << endl;
  calendario.write();
}