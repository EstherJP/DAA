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

    float lowerBound_;

    std::vector<ExpansiveNode*> nodesToExpand_;
    std::vector<ExpansiveNode*> generateNodes_;
    std::vector<std::vector<float>> allNodes_;

    std::vector<std::vector<float>> solution_;

    int expandStrategy_;

  public:
    Tree();
    Tree(MaxDivProblem*, int);
    ~Tree();

    std::vector<std::vector<float>> deleteNode(std::vector<std::vector<float>> nodes, std::vector<float> node);

    std::vector<ExpansiveNode*> getNodesToExpand();
    float getLowerBound();
    std::vector<std::vector<float>> getSolution();

    void bound(ExpansiveNode* node);

    void expandNode(ExpansiveNode* node);
    void writeTree(void);
    void initializeTree(void);

    void setExpandStrategy(int str);
    
    ExpansiveNode* nodeToExpand();
    ExpansiveNode* expandNodeByLowerUpperBound();
    ExpansiveNode* expandNodeByDepth();
};