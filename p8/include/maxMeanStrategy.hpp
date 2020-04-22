#pragma once

#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include "../include/maxMeanStrategyBase.hpp"

class MaxMeanGreedy : public MaxMean {
  public:
    MaxMeanGreedy(Graph affinities) : MaxMean(affinities) {
      srand(time(NULL));
    }

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
      return max;
    }

    int getCurrentBestAffinity(void) {
      int max = INT_MIN;
      int iMax;
      int jMax;

      if (bestSolution_.size() == 0) {
        return getMax();
      } 

      int currentNode = 0;
      for (size_t i = bestSolution_[currentNode]; (size_t)currentNode != bestSolution_.size(); 
          i = bestSolution_[++currentNode]) {
        for (int j = 0; j < affinities_.getNumberVertex(); j++) {
          if (affinities_.getValue(i, j) > max && !isInCurrentSolution(j)) {
            max = affinities_.getValue(i, j);
            iMax = i;
            jMax = j;
          } else if (affinities_.getValue(i, j) == max && !isInCurrentSolution(j)) {
            int random = rand() % 2;
            if (random == 1) {
              max = affinities_.getValue(i, j);
              iMax = i;
              jMax = j;
            }
          }
        }
      }

      for (size_t i = 0; i < bestSolution_.size(); i++) {
        if (bestSolution_[i] != iMax) {
          max += affinities_.getValue(bestSolution_[i], jMax);
        }
      }

      bestSolution_.push_back(jMax);
      return max;
    }

    void searchSolution(void) {
      std::cout << "Primera estrategia greedy\n";
      bestMean_ = getCurrentBestAffinity() / 2;
      std::vector<int> auxSol;
      float sumEdge = bestMean_;

      do {
        auxSol = bestSolution_;
        sumEdge += getCurrentBestAffinity();
        float newMean = meanDispersion(sumEdge, bestSolution_.size());
        if (newMean >= bestMean_) {
          bestMean_ = newMean;
        } else {
          bestSolution_ = auxSol;
        }
      } while (auxSol != bestSolution_);
    }
};

class MyMaxMeanGreedy : public MaxMean {
  public:
    MyMaxMeanGreedy(Graph affinities) : MaxMean(affinities) {}

    void searchSolution(void) {
      std::cout << "Segunda estrategia greedy\n";
    }
};
