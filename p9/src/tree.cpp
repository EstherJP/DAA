#include "../include/tree.hpp"

Tree::Tree() {}

Tree::Tree(MaxDivProblem* sol)

{
  sol_ = sol;
  allNodes_ = sol->getAllNodes();
  totalNodes_ = sol->getAllNodes().size();
  currentDepth_ = 0;
  solutionSize_ = sol->getSolutionSize();
}


void Tree::initializeTree(void) {
  currentDepth_++;
  for (int i = 0; i < totalNodes_ - solutionSize_; i++) {
    std::vector<std::vector<float>> noInSolution = allNodes_;
    for (auto iter = noInSolution.begin(); iter < noInSolution.end(); iter++) {
      if (*iter == allNodes_[i]) {
        noInSolution.erase(iter);
      }
    }
    ExpansiveNode* currentNode = new ExpansiveNode(allNodes_[i], i, currentDepth_, noInSolution);
    currentNode->upperBound(solutionSize_);
    nodesToExpand_.push_back(currentNode);
  }
}

void Tree::writeTree(void) {
  for (int i = 0; i < nodesToExpand_.size(); i++) {
    nodesToExpand_[i]->writeNode();
  }
}

float Tree::nodeUpperBound(std::vector<std::vector<float>> sol) {
  // float z1, z2, z3;
  // // z1, distancia solucion actual
  // int i = currentDepth_;
  // z1 = sol_->totalDistance(currentBranch_);
  // std::cout << "z1 " << z1 << std::endl;
}


void Tree::expandTree(void) {
  // for ()
}