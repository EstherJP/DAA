#pragma once

#include "maxMeanStrategyBase.hpp"

class destructiveGreedy : public MaxMean {
  public:
    destructiveGreedy(Graph affinities);

    void initializeAll(void);
    void deleteWorstNode(void);
    void searchSolution(void);
};