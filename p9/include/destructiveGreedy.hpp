#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"

class desGreedy : public MaxDivProblem {
  public:
    desGreedy();
    desGreedy(Data setData);
    ~desGreedy();

    std::vector<float> nearElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center);
    void searchSolution(void);
};