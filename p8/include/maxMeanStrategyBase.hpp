#pragma once

#include <iostream>
#include <math.h>
#include <cfloat>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <utility>

#include "../include/graph.hpp"

#define MAXITERATIONS 50

class MaxMean {
  protected:
    Graph affinities_;
    std::vector<int> bestSolution_;
    std::vector<int> currentSolution_;
    float bestMean_;

    int numberIterWithoutImprove = 0;

    int stopCriteria_ = 0;
    int searchCriteria_ = 0;
    int environmentCriteria_ = 0;

    bool isInCurrentSolution(float node);
  
  public:
    MaxMean(Graph affinities);
    ~MaxMean();

    float getMax(void);
    void updateSolution(std::vector<int> newSolution, float newMean);
    std::vector<int> getBestSolution(void);
    float meanDispersion(std::vector<int> nodes);
    void showSolution(void);
    virtual void searchSolution(void) = 0;

    bool stopCriteria(int nIterations);

    void localGreedySearch(void);
    void localAnxiousSearch(void);

    void postProcessing(void);

    std::vector<int> generateNeightbourd(int node);
};