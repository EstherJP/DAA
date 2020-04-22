#include "../include/maxMeanStrategyBase.hpp"

MaxMean::MaxMean(Graph affinities): 
  affinities_(affinities)
{}

MaxMean::~MaxMean() {}

std::vector<int> MaxMean::getBestSolution(void) {
  return bestSolution_;
}

bool MaxMean::isInCurrentSolution(int node) {
  for (size_t i = 0; i < currentSolution_.size(); i++) {
    if (currentSolution_[i] == node) {
      return true;
    }
  }
  return false;
}