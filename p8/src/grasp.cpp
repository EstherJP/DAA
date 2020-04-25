#include "../include/grasp.hpp"

Grasp::Grasp(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria) : MaxMean(affinities)
{
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}


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

void Grasp::createLRC(void) {
  LRC_.clear();

  float newMean = bestMean_;
  for (int currentNode = 0; currentNode < affinities_.getNumberVertex(); currentNode++) {
    if (!isInCurrentSolution(currentNode)) {
      bestSolution_.push_back(currentNode);
      newMean = meanDispersion(bestSolution_);
      addLRC(currentNode, newMean);
      bestSolution_.pop_back();
    }
  }
}

void Grasp::constructivePhase(void) {
  createLRC();
  float auxMean = bestMean_;
  std::vector<int> auxSol;

  do {
    auxSol = bestSolution_;
    int randomNode = rand() % cardinality_;
    bestSolution_.push_back(LRC_[randomNode].first);
    auxMean = LRC_[randomNode].second;
    // updateSolution(auxSol, auxMean);
    if (bestMean_ < auxMean) {
      bestMean_ = auxMean;
    } else {
      bestSolution_ = auxSol;
    }
    createLRC();
  } while (auxSol != bestSolution_);
  // std::cout << "Saliendo de la fase constructiva la solución es: ";
  // for (int i = 0; i < bestSolution_.size(); i++)
  //   std::cout << bestSolution_[i] << " ";
}

void Grasp::searchSolution(void) {
  std::cout << "----------Grasp----------\n";
  int numberOfIterations = 0;
  std::vector<int> auxSol;
  int auxMean;
  bestMean_ = getMax();
  do {
    constructivePhase();
    // showSolution();

    // std::cout << "Aux mean " << auxMean << "\n";
    // for (int i = 0; i < auxSol.size(); i++) {
    //   std::cout << auxSol[i] << " ";
    // }
    // std::cout << "\n";
    // postProcessing();
    // updateSolution(auxSol, auxMean);
    if (bestMean_ > auxMean) {
      std::cout << "Actualizo valores\n";
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
  // updateSolution(auxSol, auxMean);
}