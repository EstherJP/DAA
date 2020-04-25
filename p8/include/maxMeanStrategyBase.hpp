#pragma once

#include <iostream>
#include <math.h>
#include <cfloat>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <utility>

#include "../include/graph.hpp"

class MaxMean {
  protected:
    Graph affinities_;
    std::vector<int> bestSolution_;
    float bestMean_;

    bool isInCurrentSolution(float node);
  
  public:
    MaxMean(Graph affinities);
    ~MaxMean();

    float getMax(void);
    void updateSolution(std::vector<int> newSolution, float newMean);
    std::vector<int> getBestSolution(void);
    float meanDispersion(std::vector<int> nodes);
    void showSolution(void);
    virtual void searchSolution(void) = 0;
};