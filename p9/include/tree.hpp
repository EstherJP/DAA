#pragma once

#include <iostream>
#include "node.hpp"
#include "maxDiversityProblem.hpp"

class Tree {
  private:
    MaxDivProblem* sol_;
    int totalNodes_;
    int currentDepth_;
    int solutionSize_;

    std::vector<ExpansiveNode*> nodesToExpand_;
    std::vector<ExpansiveNode*> expandedNodes_;
    std::vector<std::vector<float>> allNodes_;

  public:
    Tree();
    Tree(MaxDivProblem*);
    ~Tree();

    void writeTree(void);
    void initializeTree(void);
    void expandTree(void);
    float nodeUpperBound(std::vector<std::vector<float>> sol);
};