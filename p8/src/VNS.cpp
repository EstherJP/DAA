/**
 * @file VNS.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Implementación del algoritmo de Multi-Arranque
 * @version 0.1
 * @date 2020-04-27
 */

#include "../include/VNS.hpp"


/**
 * @brief Construct a new VNS::VNS object
 * 
 * @param affinities Objeto con la matriz de afinidades que le pasamos al constructor de la clase padre
 * @param stopCriteria Criterio de parada
 * @param searchCriteria Búsqueda local
 * @param environmentCriteria Entorno
 */
VNS::VNS(Graph affinities, Grasp* grasp, int stopCriteria, int searchCriteria, int environmentCriteria) : 
  MaxMean(affinities),
  grasp_(grasp)
{
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}

/**
 * @brief Recorre los distintos entornos en busca de la solución óptima contenida en los tres a la vez
 * 
 * @param auxSol Primera solución a la que va a buscar en el entorno
 * @param auxMean Media de la solución
 */
void VNS::makeVNS(std::vector<int> auxSol, float auxMean){
  for (int swapChanges = 1; swapChanges < K; swapChanges++) {
    shake(auxSol, auxMean, swapChanges);
    if (bestMean_ > auxMean) {
      auxMean = bestMean_;
      auxSol = bestSolution_;
      swapChanges = 0;
    }
  }
  bestSolution_ = auxSol;
  bestMean_ = auxMean;
}

/**
 * @brief Genera de forma aleatoria la vecina de la solución actual dependiendo del entorno
 * 
 * @param auxSol Solución en la que se va a buscar la vecina
 * @param auxMean Media de la solución
 * @param swapNumber Número de intercambios, define la estructura de entorno
 */
void VNS::shake(std::vector<int> auxSol, float auxMean, int swapNumber) {
  std::vector<int> candidates;
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    if (!isInSolution(i, auxSol)) {
      candidates.push_back(i);
    }
  }
  
  int swapped = 0;
  std::vector<int> nodeWasChanged(auxSol.size(), 0);
  for (int i = 0; i < swapNumber; i++) {
    int randomNodeSol = rand() % auxSol.size();
    std::vector<int>::iterator swapCandidate;

    if ((candidates.size() != 0) && (swapped != nodeWasChanged.size())) {
      swapCandidate = candidates.begin();
      std::advance(swapCandidate, (rand() % candidates.size()));
    } else {
      break;
    }

    if (nodeWasChanged[randomNodeSol] != 1) {
      auxSol[randomNodeSol] = *swapCandidate;
      candidates.erase(swapCandidate);
      swapped++;
      nodeWasChanged[randomNodeSol] = 1;
    } else {
      i--;
    }
  }  
  bestMean_ = meanDispersion(auxSol);
  bestSolution_ = auxSol;
  postProcessing();
}

void VNS::searchSolution(void) {
  std::vector<int> auxSol;
  float auxMean;

  std::vector<int> finalSol;
  float finalMean = FLT_MIN;
  do {
    grasp_->searchSolution();
    // grasp_->generateRandomSolution();
    auxSol = grasp_->getBestSolution();
    auxMean = grasp_->getBestMean();

    makeVNS(auxSol, auxMean);
    if (finalMean < bestMean_) {
      finalSol = bestSolution_;
      finalMean = bestMean_;
    }
    numberIterations_++;
  } while(stopCriteria());
  bestSolution_ = finalSol;
  bestMean_ = finalMean;
}