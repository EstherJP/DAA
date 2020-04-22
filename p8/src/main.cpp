#include <iostream>
#include "../include/graph.hpp"
#include "../include/maxMeanCalculator.hpp"
#include "../include/maxMeanStrategy.hpp"

int main(int argc, char* argv[]) {
  try {
    if (argc <= 1) {
      throw "Introducir fichero con grafo";
    } 

    char* filename = argv[1];
    std::cout << "Nombre del fichero: " << filename << std::endl;
    Graph graph(filename);
    // graph.write();

    MaxMeanGreedy* firstGreedy = new MaxMeanGreedy(graph);
    MyMaxMeanGreedy* secondGreedy = new MyMaxMeanGreedy(graph);

    maxMeanCalculator* interface = new maxMeanCalculator(firstGreedy);
    interface->maxMeanInterface();
    std::cout << std::endl;
    interface->setStrategy(secondGreedy);
    interface->maxMeanInterface();

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}