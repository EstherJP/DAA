#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"
#include "node.hpp"
#include "tree.hpp"

class BranchBound {
  private:
    MaxDivProblem* LBSolution_;
    float LB_;
    Tree* tree_;
    std::vector<std::vector<float>> partialSolution_;

    // std::vector<std::vector<float>> allNodes_;

    // int totalNodes_;
    // int currentDepth_;
    // int solutionSize_;

    // std::vector<ExpansiveNode*> nodesToExpand_;
    // std::vector<ExpansiveNode*> expandedNodes_;
    // std::vector<std::vector<float>> partialSolution_;
  
  public:
    BranchBound();
    BranchBound(MaxDivProblem* LBSolution);

    // void initializeTree(void);
    // void expandTree(void);

    void branchBound(void);
    // void writeTree(void);
    
    // float nodeUpperBound(ExpansiveNode* node);
};