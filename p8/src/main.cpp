#include <iostream>
#include "../include/graph.hpp"
#include "../include/maxMeanCalculator.hpp"
// #include "../include/maxMeanStrategy.hpp"
#include "../include/contructiveGreedy.hpp"
#include "../include/destructiveGreedy.hpp"
#include "../include/grasp.hpp"

int main(int argc, char* argv[]) {
  try {
    if (argc <= 1) {
      throw "Introducir fichero con grafo";
    } 

    char* filename = argv[1];
    std::cout << "Nombre del fichero: " << filename << std::endl;
    Graph graph(filename);

    constructiveGreedy* constGreedy = new constructiveGreedy(graph);
    destructiveGreedy* descGreedy = new destructiveGreedy(graph);
    Grasp* grasp = new Grasp(graph);


    maxMeanCalculator* interface = new maxMeanCalculator(constGreedy);
    interface->maxMeanInterface();
    std::cout << std::endl;
    interface->setStrategy(descGreedy);
    interface->maxMeanInterface();

    // graph.write();
    interface->setStrategy(grasp);
    interface->maxMeanInterface();

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}