/**
 * @file grasp.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación del algoritmo de GRASP
 * @version 0.1
 * @date 2020-04-26
 */

#include "../include/grasp.hpp"

/**
 * @brief Construct a new Grasp:: Grasp object
 * 
 * @param affinities Objeto con la matriz de afinidades que le pasamos al constructor de la clase padre
 * @param stopCriteria Criterio de parada
 * @param searchCriteria Búsqueda local
 * @param environmentCriteria Entorno
 */
Grasp::Grasp(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria) : 
  MaxMean(affinities)
{
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}

/**
 * @brief Inicializa el LRC
 */
void Grasp::createLRC(void) {
  LRC_.clear();
  float newMean = bestMean_;
  for (int currentNode = 0; currentNode < affinities_.getNumberVertex(); currentNode++) {
    if (!isInSolution(currentNode, bestSolution_)) {
      bestSolution_.push_back(currentNode);
      newMean = meanDispersionAdd(currentNode, bestMean_, bestSolution_);
      addLRC(currentNode, newMean);
      bestSolution_.pop_back();
    }
  }
}

/**
 * @brief Actualiza el LRC para coger los mejor nodos
 * 
 * @param currentNode Nodo a comprobar para meter
 * @param currentMean Media actual
 */
void Grasp::addLRC(int currentNode, float currentMean) {
  if (LRC_.size() < cardinality_) {
    LRC_.push_back(std::make_pair(currentNode, currentMean));
  } else {
    float currentMin = currentMean;
    int posMin = -1;
    for (int i = 0; i < cardinality_; i++) {
      if (currentMin > LRC_[i].second) {
        posMin = i;
        currentMin = LRC_[i].second;
      } else if (currentMin == LRC_[i].second) {
        int random = rand() % 2;
        if (random == 1) {
          posMin = i;
        } 
      }
    }
    if (posMin != -1) {
      LRC_[posMin] = std::make_pair(currentNode, currentMean);
    }
  }
}

/**
 * @brief Fase constructiva del GRASP
 */
void Grasp::constructivePhase(void) {
  createLRC();
  float auxMean;
  std::vector<int> auxSol;

  do {
    auxSol = bestSolution_;
    int randomNode = rand() % cardinality_;
    bestSolution_.push_back(LRC_[randomNode].first);
    auxMean = LRC_[randomNode].second;
    updateSolution(auxSol, auxMean);
    createLRC();
  } while (auxSol != bestSolution_);
}

/**
 * @brief Búsqueda de la mejor solución
 */
void Grasp::searchSolution(void) {
  int numberOfIterations = 0;
  std::vector<int> auxSol;
  float auxMean = FLT_MIN;
  do {
    bestMean_ = initializeBestSolution();
    constructivePhase();
    postProcessing();
    if (bestMean_ > auxMean) {
      auxMean = bestMean_;
      auxSol = bestSolution_;
      numberIterWithoutImprove = 0;
    } else {
      numberIterWithoutImprove++;
    }
    numberOfIterations++;
  } while (stopCriteria(numberOfIterations));
  bestSolution_ = auxSol;
  bestMean_ = auxMean;
}