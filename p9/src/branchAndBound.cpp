#include "../include/branchAndBound.hpp"

BranchBound::BranchBound() {}

BranchBound::BranchBound(MaxDivProblem* LBSolution) : 
  LBSolution_(LBSolution)
{
  LB_ = LBSolution_->getBestDistance();
  tree_ = new Tree(LBSolution);
  // allNodes_ = LBSolution_->getAllNodes();

}


void BranchBound::branchBound(void) {
  std::cout << "cota inferior " << LB_ << std::endl;
  tree_->initializeTree();
  tree_->writeTree();

}