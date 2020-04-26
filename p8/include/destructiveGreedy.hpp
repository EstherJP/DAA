/**
 * @file destructiveGreedy.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación de un algoritmo greedy destructivo
 * @version 0.1
 * @date 2020-04-26
 */

#pragma once

#include "maxMeanStrategyBase.hpp"

/**
 * @brief Clase que contiene la implementación del algoritmo de greedy destructivo
 */
class destructiveGreedy : public MaxMean {
  public:
    destructiveGreedy(Graph affinities); // Constructor

    void initializeAll(void);            // Inicializa la solución con todos los nodos
    float deleteWorstNode(void);         // Elimina el nodo que minimice la función objetivo
    void searchSolution(void);           // Búsqueda de la solución
};