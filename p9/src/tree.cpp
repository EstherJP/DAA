#include "../include/tree.hpp"

Tree::Tree() {}

Tree::Tree(MaxDivProblem* sol) {
  sol_ = sol;
  allNodes_ = sol->getAllNodes();
  totalNodes_ = sol->getAllNodes().size();
  currentDepth_ = 0;
  solutionSize_ = sol->getSolutionSize();
  lowerBound_ = sol->getBestDistance();
}

std::vector<std::vector<float>> Tree::deleteNode(std::vector<std::vector<float>> nodes, std::vector<float> node) {
  for (auto iter = nodes.begin(); iter < nodes.end(); iter++) {
    if (*iter == node) {
      nodes.erase(iter);
      return nodes;
    }
  }
}

void Tree::initializeTree(void) {
  currentDepth_++;
  for (int i = 0; i < totalNodes_ - solutionSize_ + 1; i++) {
    std::vector<std::vector<float>> noInSolution = deleteNode(allNodes_, allNodes_[i]);
    std::vector<std::vector<float>> partialSolution;
    partialSolution.push_back(allNodes_[i]);
    ExpansiveNode* currentNode = new ExpansiveNode(allNodes_[i], i, currentDepth_, noInSolution, partialSolution, 0);
    // currentNode->setPartialSolution(allNodes_[i]);
    currentNode->upperBound(solutionSize_);
    nodesToExpand_.push_back(currentNode);
    generateNodes_.push_back(currentNode);
    // currentNode->writeNode();
  }
}

void Tree::writeTree(void) {
  // std::cout << "NODOS A EXPANDIR\n";
  // for (int i = 0; i < nodesToExpand_.size(); i++) {
  //   nodesToExpand_[i]->writeNode();
  // }

  std::cout << "NODOS GENERADOS\n";
  for (int i = 0; i < generateNodes_.size(); i++) {
    generateNodes_[i]->writeNode();
  }
}

void Tree::bound(ExpansiveNode* node) {
  for (auto iter = nodesToExpand_.begin(); iter < nodesToExpand_.end(); iter++) {
    if (*iter == node) {
      nodesToExpand_.erase(iter);
    }
  }
}

void Tree::expandNode(ExpansiveNode* node) {
  int maxNode = allNodes_.size() - (solutionSize_ - node->getPartialSolution().size()) - (node->getId());
  for (int i = node->getId() + 1; i < node->getId() + 1 + maxNode; i++) {
    std::vector<std::vector<float>> noInSolution = deleteNode(node->getNoInSolution(), allNodes_[i]);
    std::vector<std::vector<float>> partialSolution = node->getPartialSolution();
    partialSolution.push_back(allNodes_[i]);
    ExpansiveNode* currentNode = new ExpansiveNode(allNodes_[i], i, node->getPartialSolution().size() + 1, noInSolution, partialSolution, node->getDispersion());
    currentNode->upperBound(solutionSize_);

    if (node->getDepth() + 1 == solutionSize_) {
      if (currentNode->getUpperBound() > lowerBound_) {
        lowerBound_ = currentNode->getUpperBound();
        solution_ = currentNode->getPartialSolution();
      }
    } else {
      nodesToExpand_.push_back(currentNode);
    }
    generateNodes_.push_back(currentNode);
  }
  bound(node);
}

std::vector<std::vector<float>> Tree::getSolution() {
  return solution_;
}

float Tree::getLowerBound() {
  return lowerBound_;
}

ExpansiveNode* Tree::nodeToExpand(void) {
  int indexNode = 0;
  float minUB = nodesToExpand_[0]->getUpperBound();
  for (int i = 1; i < nodesToExpand_.size(); i++) {
    if (minUB > nodesToExpand_[i]->getUpperBound()) {
      minUB = nodesToExpand_[i]->getUpperBound();
      indexNode = i;
    }
  }
  return nodesToExpand_[indexNode];
}

std::vector<ExpansiveNode*> Tree::getNodesToExpand() {
  return nodesToExpand_;
}
