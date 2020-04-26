/**
 * @file main.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Programa principañ
 * @version 0.1
 * @date 2020-04-26
 */

#include <iostream>
#include "../include/graph.hpp"
#include "../include/maxMeanCalculator.hpp"
#include "../include/contructiveGreedy.hpp"
#include "../include/destructiveGreedy.hpp"
#include "../include/grasp.hpp"
#include "../include/multiBoot.hpp"
#include "../include/VNS.hpp"

/**
 * @brief Función principal del programa
 * 
 * @param argc Número de parámetros por la línea de entrada
 * @param argv Fichero con el grafo
 * @return int Código de salida
 */
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
    VNS* vns = new VNS(graph);

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

    interface->setStrategy(vns);
    interface->maxMeanInterface();
    std::cout << std::endl;

    delete constGreedy;
    delete descGreedy;
    delete grasp;
    delete multiboot;
    delete vns;

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}