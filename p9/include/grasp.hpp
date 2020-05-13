#pragma once

#include <iostream>
#include <utility>
#include <time.h>
#include <stdlib.h>

#include "maxDiversityProblem.hpp"

#define CARDINALITY 3
#define MAXITER 1000

class Grasp : public MaxDivProblem {
  private:
    std::vector<std::pair<std::vector<float>, float>> LRC_;
    int cardinality_ = CARDINALITY;
  public:
    Grasp();
    Grasp(Data setData);
    ~Grasp();

    void createLRC(void);
    void addLRC(std::vector<float> currentSet, float currentDistance);
    void constructivePhase(void);
    void searchSolution(void);
};