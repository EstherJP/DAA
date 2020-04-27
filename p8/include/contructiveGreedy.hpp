/**
 * @file contructiveGreedy.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación de un algoritmo greedy constructivo
 * @version 0.1
 * @date 2020-04-26
 */

#pragma once

#include "maxMeanProblem.hpp"

/**
 * @brief Clase que contiene la implementación del algoritmo de greedy constructivo
 */
class constructiveGreedy : public MaxMean {
  public:
    constructiveGreedy(Graph affinities); // Constructor

    float getCurrentBestAffinity(void);   // Busca el nodo con mejor función objetivo si se añde
    void searchSolution(void);            // Búsqueda de la mejor solución
};