/**
 * @file branchAndBound.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene el código de ramificación y poda que resulve el
 * problema de máxima diversidad
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/branchAndBound.hpp"

/**
 * @brief Construct a new Branch Bound:: Branch Bound object
 */
BranchBound::BranchBound() {}

/**
 * @brief Construct a new Branch Bound:: Branch Bound object
 * 
 * @param LBSolution Solución que contiene la cota inferior inicial
 * @param str Estrategia de expansión de nodos
 */
BranchBound::BranchBound(MaxDivProblem* LBSolution, int str) : 
  LBSolution_(LBSolution)
{
  LB_ = LBSolution_->getBestDistance();
  tree_ = new Tree(LBSolution, str);
}

/**
 * @brief Método de ramificación y poda
 */
void BranchBound::branchBound(void) {
  tree_->initializeTree();
  while (tree_->getNodesToExpand().size() != 0) {
    ExpansiveNode* currentNode = tree_->nodeToExpand();
    tree_->expandNode(currentNode);
    for (int i = 0; i < tree_->getNodesToExpand().size(); i++) {
      if (tree_->getNodesToExpand()[i]->getUpperBound() < tree_->getLowerBound()) {
        tree_->bound(tree_->getNodesToExpand()[i]);
      }
    }
  }
}

/**
 * @brief Muestra la solución óptima calculada 
 */
void BranchBound::showSolution() {
  std::cout << "Distancia máxima: " << tree_->getLowerBound() << "\n";
  for (int i = 0; i < tree_->getSolution().size(); i++) {
    std::cout << "Conjunto " << i + 1 << ":  ";
    for (int j = 0; j < tree_->getSolution()[i].size(); j++) {
      std::cout << tree_->getSolution()[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}