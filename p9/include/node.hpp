#pragma once

#include <iostream>
#include <vector>

class ExpansiveNode {
  private:
    std::vector<float> node_;
    std::vector<ExpansiveNode*> parents_;
    int vectorId_;

    std::vector<std::vector<float>> noInSolution_;

    float upperBound_;
    float dispertion_;
    int depth_;
    bool expanded_ = false;
    bool pruned_ = false;

  public:
    ExpansiveNode();
    ExpansiveNode(std::vector<float> node, int vectorId, int depth, std::vector<std::vector<float>> noInSolution);
    ~ExpansiveNode();

    void setParents(ExpansiveNode* parent);

    std::vector<float> getNode(void);
    float getDispersion(void);
    int getDepth(void);
    std::vector<ExpansiveNode*> getParents(void);

    bool isExpanded(void);
    bool isPruned(void);

    void upperBound(int solSize);

    void prune(void);
    void expand(void);

    void writeNode(void);
};