/**
 * @file grasp.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de un algoritmo GRASP
 * que resuelve el problema de máxima diversidad
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>
#include <utility>
#include <time.h>
#include <stdlib.h>
#include "maxDiversityProblem.hpp"

/**
 * @brief Clase que implementa el algoritmo GRASP
 */
class Grasp : public MaxDivProblem {
  private:
    std::vector<std::pair<std::vector<float>, float>> LRC_;             // Lista restringida de candidatos
    int cardinality_;                                                   // Cardinalidad
  public:
    Grasp();                                                            // Constructor por defecto
    Grasp(Data setData, int solSize, int maxIter, int cardinality);     // Constructor
    ~Grasp();                                                           // Destructor

    void createLRC(void);                                               // Crea la lista restringida de candidatos
    void addLRC(std::vector<float> currentSet, float currentDistance);  // Añade el mejor subconjunto al LRC
    void constructivePhase(void);                                       // Fase constructiva del GRASP
    void searchSolution(void);                                          // Algoritmo GRASP
};