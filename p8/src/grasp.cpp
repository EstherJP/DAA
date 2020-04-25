#include "../include/grasp.hpp"

Grasp::Grasp(Graph affinities) : MaxMean(affinities) {
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

    updateSolution(auxSol, auxMean);
    createLRC();
  } while (auxSol != bestSolution_);
}

void Grasp::searchSolution(void) {
  std::cout << "----------Grasp----------\n";
  int i = 0;
  std::vector<int> auxSol;
  int auxMean;
  bestMean_ = getMax();
  do {
    constructivePhase();
    auxSol = bestSolution_;
    auxMean = bestMean_;
    updateSolution(auxSol, auxMean);
    i++;
  } while (i < 200);
}