#pragma once

#include <iostream>
#include "../include/graph.hpp"

class MaxMean {
  protected:
    Graph affinities_;
    std::vector<int> bestSolution_;
    int bestMaxMean_;

    std::vector<int> currentSolution_;
    int currentMaxMean_;

    bool isInCurrentSolution(int node);
  
  public:
    MaxMean(Graph affinities);
    ~MaxMean();

    virtual void searchSolution(void) = 0;
    std::vector<int> getBestSolution(void);
};