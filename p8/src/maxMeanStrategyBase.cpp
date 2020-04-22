#include "../include/maxMeanStrategyBase.hpp"

MaxMean::MaxMean(Graph affinities): 
  affinities_(affinities)
{}

MaxMean::~MaxMean() {}

std::vector<int> MaxMean::getBestSolution(void) {
  return bestSolution_;
}

bool MaxMean::isInCurrentSolution(int node) {
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    if (bestSolution_[i] == node) {
      return true;
    }
  }
  return false;
}

float MaxMean::meanDispersion(float numerator, float denominator) {
  return numerator / denominator;
}

void MaxMean::showSolution(void) {
  std::cout << "Mejor media: " << bestMean_ << std::endl;
  std::cout << "Conjunto de nodos: " << std::endl;
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    std::cout << bestSolution_[i] << " ";
  }
  std::cout << std::endl;
}
