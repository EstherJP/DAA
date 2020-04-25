#pragma once

#include <iostream>
#include <math.h>
#include <cfloat>

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

    virtual void searchSolution(void) = 0;
    std::vector<int> getBestSolution(void);
    float meanDispersion(float numerator, float denominator);
    float meanDispersionVector(std::vector<int> nodes);
    void showSolution(void);
    float getMax(void);
};