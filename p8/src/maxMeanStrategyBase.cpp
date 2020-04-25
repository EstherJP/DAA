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
  // std::cout << "\nMejor media: " << bestMean_ << std::endl;
  std::cout << "Conjunto de nodos: " << std::endl;
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    std::cout << bestSolution_[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

float MaxMean::getMax(void) {
  float max = FLT_MIN;
  int iMax;
  int jMax;
      
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    for (int j = i; j < affinities_.getNumberVertex(); j++) {
      if (affinities_.getValue(i, j) > max) {
        max = affinities_.getValue(i, j);
        iMax = i;
        jMax = j;
      } else if (affinities_.getValue(i, j) == max) {
        int random = rand() % 2;
        if (random == 1) {
          max = affinities_.getValue(i, j);
          iMax = i;
          jMax = j;
        }
      }
    }
  }

  bestSolution_.push_back(iMax);
  bestSolution_.push_back(jMax);
  return max / 2.0;
}
