// TAREA 3

#pragma once

#include <iostream>
#include "maxMeanProblem.hpp"
#include "grasp.hpp"

class GraspVNS : public MaxMean {
  private:
    Grasp* grasp_;
  public:
    GraspVNS(Graph affinities, Grasp* grasp, int stopCriteria, int searchCriteria, int environmentCriteria);
    ~GraspVNS();
    void searchSolution(void);
    std::vector<int> swapEnvironment(std::vector<int> sol);
};