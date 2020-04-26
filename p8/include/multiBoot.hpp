/**
 * @file multiBoot.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación del algoritmo de Multi-Arranque
 * @version 0.1
 * @date 2020-04-26
 */

#pragma once

#include "maxMeanStrategyBase.hpp"

/**
 * @brief Clase que contiene la implementación del algoritmo de Multi-Boot
 */
class MultiBoot : public MaxMean {
  public:
    MultiBoot(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria); // Constructor
    
    void generateRandomSolution(void); // Genera soluciones aleatorias
    void searchSolution(void);         // Búsqueda de la mejor solución

};