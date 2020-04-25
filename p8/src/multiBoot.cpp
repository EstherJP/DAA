#include "../include/multiBoot.hpp"

MultiBoot::MultiBoot(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria) : MaxMean(affinities) {
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}

void MultiBoot::generateRandomSolution(void) {
  bestSolution_.clear();
  int randomSize = 2 + rand() % affinities_.getNumberVertex();
  std::cout << "random size" << randomSize << "\n";
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
  generateRandomSolution();
  showSolution();

}