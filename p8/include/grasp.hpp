#pragma once

#include "maxMeanStrategyBase.hpp"

class Grasp : public MaxMean {
  private:
    std::vector<std::pair<int, float>> LRC_;
    int cardinality_ = 4;

  public:
    Grasp(Graph affinities);

    void createLRC(void);
    void addLRC(int currentNode, float currentMean);
    void constructivePhase(void);
    void searchSolution(void);
};