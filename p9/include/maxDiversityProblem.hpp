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

    int m_ = 3;
    // std::vector<float> gravityCenter_;

  public:
    MaxDivProblem();
    MaxDivProblem(Data setData);
    ~MaxDivProblem();

    std::vector<std::vector<float>> getBestSolution(void);

    // void distance(void);
    std::vector<std::vector<float>> deleteElement(std::vector<std::vector<float>> elements, std::vector<float> deleted);

    std::vector<float> farElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center);

    std::vector<float> gravityCenter(std::vector<std::vector<float>> auxSol);

    float distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet);

    virtual void searchSolution(void) = 0;
    void showSolution(std::vector<std::vector<float>> sol);
};