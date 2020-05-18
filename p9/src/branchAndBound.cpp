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
  // std::cout << "cota inferior " << LB_ << std::endl;
  tree_->initializeTree();
  // std::cout << "ARBOL INICIAL\n";
  // tree_->writeTree();
  // std::cout << "----------\n";
  // std::cout << "Expando el primer nodo\n";
  // tree_->expandNode(tree_->getNodesToExpand()[0]);

  while (tree_->getNodesToExpand().size() != 0) {
    ExpansiveNode* currentNode = tree_->nodeToExpand();
    tree_->expandNode(currentNode);
    // std::cout << "----------\n";
    // tree_->writeTree();
    // std::cout << "----------\n";

    for (int i = 0; i < tree_->getNodesToExpand().size(); i++) {
      if (tree_->getNodesToExpand()[i]->getUpperBound() < tree_->getLowerBound()) {
        tree_->bound(tree_->getNodesToExpand()[i]);
      }
    }
  }

  // tree_->writeTree();
  std::cout << "lower final " << tree_->getLowerBound() << "\n";
}