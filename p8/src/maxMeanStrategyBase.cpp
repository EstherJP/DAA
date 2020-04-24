#include "../include/maxMeanStrategyBase.hpp"

MaxMean::MaxMean(Graph affinities): 
  affinities_(affinities)
{}

MaxMean::~MaxMean() {}

std::vector<int> MaxMean::getBestSolution(void) {
  return bestSolution_;
}

bool MaxMean::isInCurrentSolution(float node) {
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

float MaxMean::meanDispersionVector(std::vector<int> nodes) {
  float sum = 0;
  int iterNodeI = 0;
  for (size_t i = iterNodeI; i < nodes.size(); i++) {
    for (size_t j = i + 1; j < nodes.size(); j++) {
      sum += affinities_.getValue(nodes[i], nodes[j]);
    }
  }
  return (sum / nodes.size());
}


void MaxMean::showSolution(void) {
  std::cout << "\nMejor media: " << bestMean_ << std::endl;
  std::cout << "Conjunto de nodos: " << std::endl;
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    std::cout << bestSolution_[i] << " ";
  }
  std::cout << std::endl << std::endl;
}
