/**
 * @file VNS.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación del algoritmo de Multi-Arranque
 * @version 0.1
 * @date 2020-04-27
 */

#pragma once

#include "maxMeanProblem.hpp"
#include "grasp.hpp"

#define K 4

/**
 * @brief Clase que contiene la implementación del algoritmo VNS
 */
class VNS : public MaxMean {
  private:
    Grasp* grasp_;        // Solución inicial creada con grasp

  public:
    VNS(Graph affinities, Grasp* grasp, int stopCriteria, int searchCriteria, int environmentCriteria); // Constructor

    void makeVNS(std::vector<int> auxSol, float auxMean);     // Busca las solucion optima en k entornos distintos
    void shake(std::vector<int> auxSol, float auxMean, int swapNumber); // Realiza la agitacion
    void searchSolution(void);                                // Búsqueda de la solución
};