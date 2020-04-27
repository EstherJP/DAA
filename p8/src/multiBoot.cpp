/**
 * @file multiBoot.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación del algoritmo de Multi-Arranque
 * @version 0.1
 * @date 2020-04-26
 */

#include "../include/multiBoot.hpp"

/**
 * @brief Construct a new Multi Boot:: Multi Boot object
 * 
 * @param affinities Objeto con la matriz de afinidades que le pasamos al constructor de la clase padre
 * @param stopCriteria Criterio de parada
 * @param searchCriteria Búsqueda local
 * @param environmentCriteria Entorno 
 */
MultiBoot::MultiBoot(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria) : 
  MaxMean(affinities) 
{
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}

/**
 * @brief Búsqueda de la mejor solución
 */
void MultiBoot::searchSolution(void) {
  std::vector<int> auxSol;
  float auxMean = FLT_MIN;
  do {
    generateRandomSolution();
    postProcessing();

    if (bestMean_ > auxMean) {
        auxMean = bestMean_;
        auxSol = bestSolution_;
        numberIterWithoutImprove_ = 0;
    } else {
        numberIterWithoutImprove_++;
    }
    numberIterations_++;
  } while (stopCriteria());
  bestSolution_ = auxSol;
  bestMean_ = auxMean;
}