#pragma once

#include <iostream>
#include <math.h>
#include "data.hpp"

class MaxDivProblem {
  protected:
    Data setData_;
    std::vector<std::vector<float>> bestSolution_;
    float bestDistance_;
    float solutionSize_;
    float distance_;

  public:
    MaxDivProblem();
    MaxDivProblem(Data setData);
    ~MaxDivProblem();

    std::vector<std::vector<float>> getBestSolution(void);

    float distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet);

    virtual void searchSolution(void) = 0;
    void showSolution(void);
};