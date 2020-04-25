#include "../include/contructiveGreedy.hpp"

constructiveGreedy::constructiveGreedy(Graph affinities) : MaxMean(affinities) {
  srand(time(NULL));
}

float constructiveGreedy::getCurrentBestAffinity(void) {
  std::vector<int> auxSol = bestSolution_;
  float newMean = INT_MIN;
  float oldMean;
  int bestNodeFound = -1;
  for (int currentNode = 0; currentNode < affinities_.getNumberVertex(); currentNode++) {
    if (!isInCurrentSolution(currentNode)) {
      auxSol.push_back(currentNode);
      oldMean = meanDispersion(auxSol);
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

void constructiveGreedy::searchSolution(void) {
  std::cout << "----------Constructive Greedy----------\n";
  std::vector<int> auxSol;
  bestMean_ = getMax();

  do {
    auxSol = bestSolution_;
    float currentMean = getCurrentBestAffinity();
    // if (bestMean_ >= currentMean) {
      // bestSolution_.pop_back();
      updateSolution(auxSol, currentMean);

    // } else {
    //   bestMean_ = currentMean;
    // }
  } while (auxSol != bestSolution_);
}