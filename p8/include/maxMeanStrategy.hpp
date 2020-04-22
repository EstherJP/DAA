#pragma once

#include <iostream>
#include <climits>
#include "../include/maxMeanStrategyBase.hpp"

class MaxMeanGreedy : public MaxMean {
  public:
    MaxMeanGreedy(Graph affinities) : MaxMean(affinities) {}

    int getMax(void) {
      int max = INT_MIN;
      int iMax;
      int jMax;
          
      for (int i = 0; i < affinities_.getNumberVertex(); i++) {
        for (int j = i; j < affinities_.getNumberVertex(); j++) {
          if (affinities_.getValue(i, j) > max) {
            max = affinities_.getValue(i, j);
            iMax = i;
            jMax = j;
          }
        }
      }
      if (!isInCurrentSolution(iMax)) {
        currentSolution_.push_back(iMax);
      }
      if (!isInCurrentSolution(jMax)) {
        currentSolution_.push_back(jMax);
      }
      return max;
    }

    int getCurrentBestAffinity(void) {
      int max = INT_MIN;
      int jMax;

      if (currentSolution_.size() == 0) {
        return getMax();
      } 

      int currentNode = 0;
      for (int i = currentSolution_[currentNode]; currentNode != currentSolution_.size(); 
          i = currentSolution_[++currentNode]) {
        for (int j = 0; j < affinities_.getNumberVertex(); j++) {
          if (affinities_.getValue(i, j) > max && !isInCurrentSolution(j)) {
            max = affinities_.getValue(i, j);
            jMax = j;
          }
        }
      }
      if (!isInCurrentSolution(jMax)) {
        currentSolution_.push_back(jMax);
      }
      return max;
    }

    void searchSolution(void) {
      std::cout << "Primera estrategia greedy\n";
    }
};

class MyMaxMeanGreedy : public MaxMean {
  public:
    MyMaxMeanGreedy(Graph affinities) : MaxMean(affinities) {}

    void searchSolution(void) {
      std::cout << "Segunda estrategia greedy\n";
    }
};
