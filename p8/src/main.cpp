/**
 * @file main.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Programa principañ
 * @version 0.1
 * @date 2020-04-26
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include "../include/graph.hpp"
#include "../include/maxMeanCalculator.hpp"
#include "../include/contructiveGreedy.hpp"
#include "../include/destructiveGreedy.hpp"
#include "../include/grasp.hpp"
#include "../include/multiBoot.hpp"
#include "../include/VNS.hpp"

using namespace std;

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
    VNS* vns = new VNS(graph, grasp, STOP_ITERATIONS, ANXIOUS_SEARCH, ENV_OPENING);
 
    std::chrono::time_point<chrono::system_clock> startTime, endTime;

    maxMeanCalculator* interface = new maxMeanCalculator(constGreedy);
    std::cout << "----------Constructive Greedy----------\n";
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "----------Destructive Greedy----------\n";
    interface->setStrategy(descGreedy);
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" <<  std::endl << std::endl;


    std::cout << "----------Grasp----------\n";
    interface->setStrategy(grasp);
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl << std::endl;


    std::cout << "----------Multi Boot----------\n";
    interface->setStrategy(multiboot);
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl << std::endl;


    std::cout << "----------VNS----------\n";
    interface->setStrategy(vns);
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl << std::endl;

    delete constGreedy;
    delete descGreedy;
    delete grasp;
    delete multiboot;
    delete vns;
    delete interface;

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}