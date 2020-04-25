#pragma once

#include "maxMeanStrategyBase.hpp"

class MultiBoot : public MaxMean {
  public:
    MultiBoot(Graph affinities, int stopCriteria, int searchCriteria, int environmentCriteria); 
    void searchSolution(void);  

    void generateRandomSolution(void);
};