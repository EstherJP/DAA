/**
 * @file destructiveGreedy.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación de un algoritmo greedy destructivo
 * @version 0.1
 * @date 2020-04-26
 */

#include "../include/destructiveGreedy.hpp"

/**
 * @brief Construct a new destructive Greedy::destructive Greedy object
 * 
 * @param affinities Objeto con la matriz de afinidades que le pasamos al constructor de la clase padre
 */
destructiveGreedy::destructiveGreedy(Graph affinities) : 
  MaxMean(affinities) 
{
  srand(time(NULL));
}

// /**
//  * @brief Inicializa la solución actual con todos los todos
//  */
// void destructiveGreedy::initializeAll(void) {
//   for (int i = 0; i < affinities_.getNumberVertex(); i++) {
//     bestSolution_.push_back(i);
//   }
// }

/**
 * @brief Busca el peor nodo y lo elimina
 * 
 * @return float Nueva media sin ese nodo
 */
float destructiveGreedy::deleteWorstNode(void) {
  int min = INT_MAX;
  int minNode;
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    for (int j = 0; j < affinities_.getNumberVertex(); j++) {
      if (isInSolution(j, bestSolution_) && affinities_.getValue(i, j) < min) {
        min = affinities_.getValue(i, j);
        int random = rand() % 2;
        if (random == 1) {
          minNode = i;
        } else {
          minNode = j;
        } 
      } else if (isInSolution(j, bestSolution_) && affinities_.getValue(i, j) == min) {
        int random = rand() % 3;
        if (random == 1) {
          minNode = i;
        } else if (random == 2) {
          minNode = j;
        }
      } 
    }
  }
  for (auto iter = bestSolution_.begin(); iter != bestSolution_.end(); iter++) {
    if (*iter == minNode) {
      bestSolution_.erase(iter);
      return minNode;
    }
  }
}

/**
 * @brief Búsqueda de la mejor solución
 */
void destructiveGreedy::searchSolution(void) {
  initializeAll();
  bestMean_ = meanDispersion(bestSolution_);
  std::vector<int> auxSol;
  do {
    auxSol = bestSolution_;
    float deleteNode = deleteWorstNode();
    float newMean = meanDispersionSub(deleteNode, bestMean_, bestSolution_);
    updateSolution(auxSol, newMean);
  } while (auxSol != bestSolution_);
}