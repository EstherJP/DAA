/**
 * @file maxMeanStrategyBase.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase base que contiene la solución base al problema max-mean
 * @version 0.1
 * @date 2020-04-26
 */

#pragma once

#include <iostream>
#include <math.h>
#include <cfloat>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <utility>

#include "graph.hpp"

#define MAXITERATIONS 50

#define STOP_ITERATIONS 1
#define STOP_WITHOUTIMPROVE 2

#define ANXIOUS_SEARCH 1
#define GREEDY_SEARCH 2

#define ENV_OPENING 1
#define ENV_CLOSING 2

/**
 * @brief Clase que los atributos y métodos necesarios para resolver
 * problema de maximizar la media en subconjutos de un grafo.
 */
class MaxMean  {
  protected:
    Graph affinities_;                            // Objeto que contiene la matriz distancia del grafo
    std::vector<int> bestSolution_;               // Subconjunto de nodos con la mejor solución encontrada
    float bestMean_;                              // Media de la mejor solución encontrada
    int numberIterWithoutImprove_ = 0;             // Número de iteraciones sin mejora
    int numberIterations_ = 0;
    int stopCriteria_ = STOP_ITERATIONS;          // Criterio de parada (por defecto de inicializa a un número máximo de iteraciones)
    int searchCriteria_ = ANXIOUS_SEARCH;         // Criterio de bísqueda local (por defecto de inicializa a la búsqueda ansiosa)
    int environmentCriteria_ = ENV_OPENING;       // Criterio de entorno (por defecto de inicializa a movimiento de apertura)

    bool isInSolution(int node, std::vector<int> solution); // Comprueba si un nodo está en la solución actual
  
  public:
    MaxMean(void);                                 // Constructor por defecto
    MaxMean(Graph affinities);                     // Constructor
    ~MaxMean(void);                               // Destructor por defecto

    void generateRandomSolution(void);            // Genera soluciones aleatorias

    float initializeBestSolution(void);           // Inicializa la mejor solución con los nodos con función objetivo más alta
    void updateSolution(std::vector<int> newSolution, float newMean); // Actualiza si la solución recibida es mejor

    std::vector<int> getBestSolution(void);       // Devuelve la mejor solución
    float getBestMean(void);
    
    float meanDispersion(std::vector<int> nodes); // Función objetivo
    float meanDispersionAdd(int node, float currentMean, std::vector<int> nodes); // Suma el peso del nodo a añadir a la función objetivo
    float meanDispersionSub(int node, float currentMean, std::vector<int> nodes); // Resta el peso de un nodo que se ha eliminado a la función objetivo

    void showSolution(void);                       // Muestra la solución
    virtual void searchSolution(void) = 0;         // Método virtual que contendrá el código para buscar la mejor solución

    bool stopCriteria(void);            // Selecciona el criterio de parada según el seleccionado
    void localGreedySearch(void);                  // Búsqueda local greedy
    void localAnxiousSearch(void);                 // Búsqueda local ansiosa

    void postProcessing(void);                     // Selecciona la búsqueda local para el post procesamiento

    void initializeAll(void);

    std::vector<int> generateNeightbourd(int node); // Devuelve la mejor solución vecina
};