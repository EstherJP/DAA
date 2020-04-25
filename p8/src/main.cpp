#include <iostream>
#include "../include/graph.hpp"
#include "../include/maxMeanCalculator.hpp"
#include "../include/contructiveGreedy.hpp"
#include "../include/destructiveGreedy.hpp"
#include "../include/grasp.hpp"
#include "../include/multiBoot.hpp"

#define STOP_ITERATIONS 1
#define STOP_WITHOUTIMPROVE 2

#define ANXIOUS_SEARCH 1
#define GREEDY_SEARCH 2
#define ENV_OPENING 1
#define ENV_CLOSING 2

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
    Grasp* grasp = new Grasp(graph, STOP_ITERATIONS, ANXIOUS_SEARCH, ENV_OPENING);
    MultiBoot* multiboot = new MultiBoot(graph, STOP_ITERATIONS, ANXIOUS_SEARCH, ENV_OPENING);

    maxMeanCalculator* interface = new maxMeanCalculator(constGreedy);
    interface->maxMeanInterface();
    std::cout << std::endl;

    interface->setStrategy(descGreedy);
    interface->maxMeanInterface();
    std::cout << std::endl;

    interface->setStrategy(grasp);
    interface->maxMeanInterface();
    std::cout << std::endl;

    interface->setStrategy(multiboot);
    interface->maxMeanInterface();
    std::cout << std::endl;

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}