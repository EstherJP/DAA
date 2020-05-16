#pragma once

#include <iostream>
#include <math.h>
#include "data.hpp"

class MaxDivProblem {
  protected:
    Data setData_;
    std::vector<std::vector<float>> bestSolution_;

    std::vector<std::vector<float>> noInSolution_;
    float bestDistance_;
    // float solutionSize_;
    // float distance_;

    int solutionSize_;
    int maxIter_;
    // std::vector<float> gravityCenter_;

  public:
    MaxDivProblem();
    MaxDivProblem(Data setData, int solSize, int maxIter);
    ~MaxDivProblem();

    std::vector<std::vector<float>> getBestSolution(void);
    float getBestDistance(void);
    int getSolutionSize(void);
    std::vector<std::vector<float>> getAllNodes(void);

    std::vector<float> gravityCenter(std::vector<std::vector<float>> auxSol);
    // std::vector<float> gravityCenter(std::vector<std::vector<float>> auxSol);

    float distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet);
    float totalDistance(std::vector<std::vector<float>> auxSol);
    float swapDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, std::vector<float> swapped, float currentDistance);
    float addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance);

    std::vector<std::vector<float>> deleteElement(std::vector<std::vector<float>> elements, std::vector<float> deleted);
    std::vector<float> farElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center);

    std::vector<std::vector<float>> generateNeightbour(std::vector<std::vector<float>> elements, std::vector<float> element, int swapNumber);
    void localGreedySearch(std::vector<std::vector<float>> elements, float currentDistance);
    void postProcessing(void);

    void generateRandomSolution(void);
    bool isInSolution(std::vector<std::vector<float>> auxSol, std::vector<float> element);
    virtual void searchSolution(void) = 0;
    void showSolution(std::vector<std::vector<float>> sol);
};