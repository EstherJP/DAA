#include "../include/destructiveGreedy.hpp"

destructiveGreedy::destructiveGreedy(Graph affinities) : MaxMean(affinities) {
  srand(time(NULL));
}

void destructiveGreedy::initializeAll(void) {
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    bestSolution_.push_back(i);
  }
}

float destructiveGreedy::deleteWorstNode(void) {
  int min = INT_MAX;
  int minNode;
      
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    for (int j = 0; j < affinities_.getNumberVertex(); j++) {
      if (isInCurrentSolution(j) && affinities_.getValue(i, j) < min) {
        min = affinities_.getValue(i, j);
        int random = rand() % 2;
        if (random == 1) {
          minNode = i;
        } else {
          minNode = j;
        } 
      } else if (isInCurrentSolution(j) && affinities_.getValue(i, j) == min) {
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

void destructiveGreedy::searchSolution(void) {
  std::cout << "----------Destructive Greedy----------\n";
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