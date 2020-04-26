#include "../include/multiBoot.hpp"

MultiBoot::MultiBoot(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria) : MaxMean(affinities) {
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}

void MultiBoot::generateRandomSolution(void) {
  bestSolution_.clear();
  int randomSize = 2 + rand() % (affinities_.getNumberVertex() - 2);
  for (int i = 0; i < randomSize; i++) {
    int randomNode = rand() %  affinities_.getNumberVertex();
    if (!isInCurrentSolution(randomNode)) {
      bestSolution_.push_back(randomNode);
    }
  }
  bestMean_ = meanDispersion(bestSolution_);
}

void MultiBoot::searchSolution(void) {
  std::cout << "----------Multi Boot----------\n";
  std::vector<int> auxSol;
  float auxMean = FLT_MIN;
  int iterationsNumber = 0;
  do {
    generateRandomSolution();
    postProcessing();

    if (bestMean_ > auxMean) {
        auxMean = bestMean_;
        auxSol = bestSolution_;
        numberIterWithoutImprove = 0;
    } else {
        numberIterWithoutImprove++;
    }
    iterationsNumber++;
  } while (stopCriteria(iterationsNumber));
  bestSolution_ = auxSol;
  bestMean_ = auxMean;
}