#pragma once

#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <cfloat>
#include "../include/maxMeanStrategyBase.hpp"

class MaxMeanGreedy : public MaxMean {
  public:
    MaxMeanGreedy(Graph affinities) : MaxMean(affinities) {
      srand(time(NULL));
    }

    float getMax(void) {
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

    float getCurrentBestAffinity(void) {
      std::vector<int> auxSol = bestSolution_;
      float newMean = INT_MIN;
      float oldMean;
      int bestNodeFound = -1;
      for (int currentNode = 0; currentNode < affinities_.getNumberVertex(); currentNode++) {
        if (!isInCurrentSolution(currentNode)) {
          auxSol.push_back(currentNode);
          oldMean = meanDispersionVector(auxSol);
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

    void searchSolution(void) {
      std::cout << "----------Primera estrategia greedy----------\n";
      std::vector<int> auxSol;
      bestMean_ = getMax();

      do {
        auxSol = bestSolution_;
        float currentMean = getCurrentBestAffinity();
        if (bestMean_ >= currentMean) {
          bestSolution_.pop_back();
        } else {
          bestMean_ = currentMean;
        }
      } while (auxSol != bestSolution_);
    }
};

class MyMaxMeanGreedy : public MaxMean {
  public:
     MyMaxMeanGreedy(Graph affinities) : MaxMean(affinities) {
      srand(time(NULL));
    }

    void initializeAll(void) {
      for (int i = 0; i < affinities_.getNumberVertex(); i++) {
        bestSolution_.push_back(i);
      }
    }

    void deleteWorstNode(void) {
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
          break;
        }
      }
    }

    void searchSolution(void) {
      std::cout << "----------Segundo Greedy----------\n";
      initializeAll();
      bestMean_ = meanDispersionVector(bestSolution_);
      std::vector<int> auxSol;

      do {
        auxSol = bestSolution_;
        deleteWorstNode();
        float newMean = meanDispersionVector(bestSolution_);
        if (newMean >= bestMean_) {
          bestMean_ = newMean;
        } else {
          bestSolution_ = auxSol;
        }
      } while (auxSol != bestSolution_);
    }
};

class Grasp : public MaxMean {
  private:
    std::vector<int> LRC_;
    int cardinality_ = 4;

  public:
    Grasp(Graph affinities) : MaxMean(affinities) {
    srand(time(NULL));
    // LRC_.resize(cardinality_);
  }

  void createLRC(void) {
    std::vector<int> auxSol = bestSolution_;
    int auxMean = bestMean_;

    // for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    //   auxSol.push_back(i);
    //   if (bestMean_ )
    // }
  }

  void constructivePhase(void) {

  }

  void searchSolution(void) {
    std::cout << "----------Grasp----------\n";


  }

};
