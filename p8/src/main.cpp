#include <iostream>
#include "../include/graph.hpp"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    throw "Introducir fichero con grafo";
  } 

  char* filename = argv[1];
  std::cout << "Nombre del fichero: " << filename << std::endl;

  Graph prueba(filename);
  prueba.write();
}