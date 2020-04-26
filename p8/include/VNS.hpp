#pragma once

#include "maxMeanStrategyBase.hpp"

class VNS : public MaxMean {
  public:
    VNS(Graph affinities);

    std::vector<int> shake(void);
    void searchSolution(void);
};