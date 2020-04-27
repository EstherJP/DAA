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
 * @brief Función principal del programa.
 * 
 * Esta función le llega como parámetro el fichero que contiene el grafo y lo lee. Luego
 * crea punteros a los distintos algoritmos que vamos a utilizar. A los dos primero algoritmos les
 * llega simplemente el grafo. En el caso de los otros, además del grafo, les mandamos el criterio de parada
 * que en este caso existen dos, parar por el número de iteraciones y por el número de iteraciones sin mejora. El
 * valor máximo de iteraciones es una constante que se encuentra en la clase MaxMean. Luego les llega la búsqueda local
 * que se quiere realizar, en este caso también se han implementado dos, la ansiosa y la greedy, también declaradas como
 * constantes en la clase padre del problema. Por último, les llega la estructura de entorno con la que se quiere realizar la 
 * búsqueda local, las implementadas en este código son dos, de apertura y de cierre.
 * 
 * Por último, cuenta y muestra por pantalla el tiempo de ejecución de cada algoritmo. 
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