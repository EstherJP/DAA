#pragma once

#include <iostream>
#include <vector>
#include <math.h>

class ExpansiveNode {
  private:
    std::vector<float> node_;
    int vectorId_;

    std::vector<std::vector<float>> noInSolution_;
    std::vector<std::vector<float>> partialSolution_;

    float upperBound_ = 0;
    float dispersion_ = 0;
    int depth_;
    bool expanded_ = false;
    bool pruned_ = false;

  public:
    ExpansiveNode();
    ExpansiveNode(std::vector<float> node, int vectorId, int depth, std::vector<std::vector<float>> noInSolution, 
        std::vector<std::vector<float>> partialSol, float dispersion);
    ~ExpansiveNode();

    int getId();
    std::vector<std::vector<float>> getNoInSolution();
    std::vector<std::vector<float>> getPartialSolution();

    float getUpperBound();

    float getBestDistance();
    std::vector<float> getNode(void);
    float getDispersion(void);
    int getDepth(void);
    std::vector<ExpansiveNode*> getParents(void);

    bool isExpanded(void);
    bool isPruned(void);

    float distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet);
    float addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance);
    void upperBound(int solSize);

    void prune(void);
    void expand(void);

    void writeNode(void);
};