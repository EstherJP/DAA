/**
 * @file grasp.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de un algoritmo GRASP
 * que resuelve el problema de máxima diversidad
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/grasp.hpp"

/**
 * @brief Construct a new Grasp:: Grasp object
 */
Grasp::Grasp() {}

/**
 * @brief Construct a new Grasp:: Grasp object
 * 
 * @param setData Datos del problema
 * @param solSize Tamaño de la solución
 * @param maxIter Número máximo de iteraciones
 * @param cardinality Cardinalidad
 */
Grasp::Grasp(Data setData, int solSize, int maxIter, int cardinality) :
  MaxDivProblem(setData, solSize, maxIter),
  cardinality_(cardinality)
{
  srand(time(NULL));
}

/**
 * @brief Destroy the Grasp:: Grasp object
 */
Grasp::~Grasp() {}

/**
 * @brief Añade el mejor subconjunto al LRC
 * 
 * @param currentSet Conjunto candidato a ser añadido
 * @param currentDistance Distancia actual
 */
void Grasp::addLRC(std::vector<float> currentSet, float currentDistance) {
  if (LRC_.size() < cardinality_) {
    LRC_.push_back(std::make_pair(currentSet, currentDistance));
  } else {
    float currentMinDistance  = currentDistance;
    int posMin = -1;
    for (int i = 0; i < cardinality_; i++) {
      if (currentMinDistance > LRC_[i].second) {
        posMin = i;
        currentMinDistance = LRC_[i].second;
      } else if (currentMinDistance == LRC_[i].second) {
        int random = rand() % 2;
        if (random == 1) {
          posMin = i;
        }
      }  
    }
    if (posMin != -1) {
      LRC_[posMin] = std::make_pair(currentSet, currentDistance);
    }
  }
}

/**
 * @brief Crea el LRC
 */
void Grasp::createLRC(void) {
  LRC_.clear();
  std::vector<float> center;
  if (bestSolution_.size() == 0) {
    center = gravityCenter(noInSolution_);
  } else {
    center = gravityCenter(bestSolution_);
  }
  for (int i = 0; i < noInSolution_.size(); i++) {
    float centerDistance = distanceTwoSets(noInSolution_[i], center);
    addLRC(noInSolution_[i], centerDistance);
  }
}

/**
 * @brief Fase constructiva del GRASP
 */
void Grasp::constructivePhase(void) {
  createLRC();
  do {
    int randomNode = rand() % LRC_.size();
    bestSolution_.push_back(LRC_[randomNode].first);
    noInSolution_ = deleteElement(noInSolution_, LRC_[randomNode].first);
    createLRC();
  } while (bestSolution_.size() < solutionSize_);
  bestDistance_ = totalDistance(bestSolution_);
}

/**
 * @brief Algoritmo GRASP
 * 
 */
void Grasp::searchSolution(void) {
  noInSolution_ = setData_.getData();
  std::vector<std::vector<float>> auxSol;
  float auxDistance = -1;
  int i = 0;
  do {
    noInSolution_ = setData_.getData();
    constructivePhase();
    localGreedySearch(bestSolution_, bestDistance_);
    if (auxDistance < bestDistance_) {
      auxDistance = bestDistance_;
      auxSol = bestSolution_;
    }
    bestSolution_.clear();
    bestDistance_ = 0;
    i++;
  } while (i < maxIter_);
  bestSolution_ = auxSol;
  bestDistance_ = auxDistance;
}
