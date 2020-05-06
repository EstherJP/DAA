#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"

class Grasp : public MaxDivProblem {
  public:
    Grasp();
    Grasp(Data setData);
    ~Grasp();

    void searchSolution(void);
};