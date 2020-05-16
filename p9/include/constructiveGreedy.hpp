#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"

class consGreedy : public MaxDivProblem {
  public:
    consGreedy();
    consGreedy(Data setData, int solSize, int maxIter);
    ~consGreedy();

    void searchSolution(void);
};