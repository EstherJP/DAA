#pragma once

#include "maxMeanStrategyBase.hpp"

class constructiveGreedy : public MaxMean {
  public:
    constructiveGreedy(Graph affinities);

    float getCurrentBestAffinity(void);
    void searchSolution(void);
};