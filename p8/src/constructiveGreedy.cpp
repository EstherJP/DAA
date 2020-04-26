/**
 * @file contructiveGreedy.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación de un algoritmo greedy constructivo
 * @version 0.1
 * @date 2020-04-26
 */

#include "../include/contructiveGreedy.hpp"

/**
 * @brief Construct a new constructive Greedy::constructive Greedy object
 * 
 * @param affinities Objeto con la matriz de afinidades que le pasamos al constructor de la clase padre
 */
constructiveGreedy::constructiveGreedy(Graph affinities) : 
  MaxMean(affinities) 
{
  srand(time(NULL));
}

/**
 * @brief Busca el nodo que maximice la función objetivo de la solución
 * 
 * @return float Nueva media
 */
float constructiveGreedy::getCurrentBestAffinity(void) {
  std::vector<int> auxSol = bestSolution_;
  float newMean = INT_MIN;
  float oldMean;
  int bestNodeFound = -1;

  for (int currentNode = 0; currentNode < affinities_.getNumberVertex(); currentNode++) {
    if (!isInCurrentSolution(currentNode)) {
      auxSol.push_back(currentNode);
      oldMean = meanDispersionAdd(currentNode, bestMean_, auxSol);

      if (newMean < oldMean) {
        newMean = oldMean;
        bestNodeFound = currentNode;
      } else if (newMean == oldMean) {
        int random = rand() % 2;
        if (random == 1) {
          newMean = oldMean;
          bestNodeFound = currentNode;
        }
      }
      auxSol.pop_back();
    }
  }
  bestSolution_.push_back(bestNodeFound);
  return newMean;
}

/**
 * @brief Búsqueda de la mejor solución
 */
void constructiveGreedy::searchSolution(void) {
  std::cout << "----------Constructive Greedy----------\n";
  std::vector<int> auxSol;
  bestMean_ = initializeBestSolution();

  do {
    auxSol = bestSolution_;
    float currentMean = getCurrentBestAffinity();
    updateSolution(auxSol, currentMean);
  } while (auxSol != bestSolution_);
}