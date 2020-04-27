/**
 * @file grasp.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación del algoritmo de GRASP
 * @version 0.1
 * @date 2020-04-26
 */

#pragma once

#include "maxMeanProblem.hpp"

#define CARDINALITY 4

/**
 * @brief Clase que contiene la implementación del algoritmo de GRASP
 */
class Grasp : public MaxMean {
  private:
    std::vector<std::pair<int, float>> LRC_;  // Lista restringida de candidatos (<nodo, media>)
    int cardinality_ = CARDINALITY;           // Cardinalidad

  public:
    Grasp() {}
    Grasp(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria); // Constructor

    void createLRC(void);                     // Inicializa el LRC de cero
    void addLRC(int currentNode, float currentMean); // Añade los nodos al LRC
    void constructivePhase(void);             // Fase constructica de GRASP
    void searchSolution(void);                // Búsqueda solución
};