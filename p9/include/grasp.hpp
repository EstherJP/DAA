#pragma once

#include <iostream>
#include <utility>
#include <time.h>
#include <stdlib.h>

#include "maxDiversityProblem.hpp"

#define CARDINALITY 3

class Grasp : public MaxDivProblem {
  private:
    std::vector<std::pair<std::vector<float>, float>> LRC_;
    int cardinality_;
  public:
    Grasp();
    Grasp(Data setData, int solSize, int maxIter, int cardinality);
    ~Grasp();

    void createLRC(void);
    void addLRC(std::vector<float> currentSet, float currentDistance);
    void constructivePhase(void);
    void searchSolution(void);
};