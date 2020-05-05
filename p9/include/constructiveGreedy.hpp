#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"

class consGreedy : public MaxDivProblem {
  public:
    consGreedy();
    consGreedy(Data setData);
    ~consGreedy();

    void searchSolution(void);
};