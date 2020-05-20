/**
 * @file tree.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que representa el árbol ramificación y poda
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/tree.hpp"

/**
 * @brief Construct a new Tree:: Tree object
 */
Tree::Tree() {}

/**
 * @brief Construct a new Tree:: Tree object
 * 
 * @param sol Solución que coge la cota superior
 * @param str Estrategia a expandir
 */
Tree::Tree(MaxDivProblem* sol, int str) {
  allNodes_ = sol->getAllNodes();
  totalNodes_ = sol->getAllNodes().size();
  currentDepth_ = 0;
  solutionSize_ = sol->getSolutionSize();
  lowerBound_ = sol->getBestDistance();
  expandStrategy_ = str;
  solution_ = sol->getBestSolution();
}

/**
 * @brief Elimina un subconjunto de nodos de un conjunto
 * 
 * @param nodes Conjunto de subconjuntos
 * @param node Subconjunt
 * @return std::vector<std::vector<float>> Nuevo subconjunto
 */
std::vector<std::vector<float>> Tree::deleteNode(std::vector<std::vector<float>> nodes, std::vector<float> node) {
  for (auto iter = nodes.begin(); iter < nodes.end(); iter++) {
    if (*iter == node) {
      nodes.erase(iter);
      return nodes;
    }
  }
}

/**
 * @brief Devuelve los nodos generados
 * 
 * @return std::vector<ExpansiveNode*> 
 */
std::vector<ExpansiveNode*> Tree::getGenerateNodes() {
  return generateNodes_;
}

/**
 * @brief Inicializa el árbol 
 */
void Tree::initializeTree(void) {
  currentDepth_++;
  for (int i = 0; i < totalNodes_ - solutionSize_ + 1; i++) {
    std::vector<std::vector<float>> noInSolution = deleteNode(allNodes_, allNodes_[i]);
    std::vector<std::vector<float>> partialSolution;
    partialSolution.push_back(allNodes_[i]);
    ExpansiveNode* currentNode = new ExpansiveNode(allNodes_[i], i, currentDepth_, noInSolution, partialSolution, 0);
    currentNode->upperBound(solutionSize_);
    nodesToExpand_.push_back(currentNode);
    generateNodes_.push_back(currentNode);
  }
}

/**
 * @brief Escribe el árbol
 */
void Tree::writeTree(void) {
  for (int i = 0; i < generateNodes_.size(); i++) {
    generateNodes_[i]->writeNode();
  }
}

/**
 * @brief Poda un nodo del árbol
 * 
 * @param node Nodo a podar
 */
void Tree::bound(ExpansiveNode* node) {
  for (auto iter = nodesToExpand_.begin(); iter < nodesToExpand_.end(); iter++) {
    if (*iter == node) {
      nodesToExpand_.erase(iter);
    }
  }
}
 
 /**
  * @brief Expande un nodo
  * 
  * @param node Nodo a expandir
  */
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

/**
 * @brief Devuelve la solución
 * 
 * @return std::vector<std::vector<float>> Solución
 */
std::vector<std::vector<float>> Tree::getSolution() {
  return solution_;
}

/**
 * @brief Devuelve la cota inferior
 * 
 * @return float Cota inferior
 */
float Tree::getLowerBound() {
  return lowerBound_;
}

/**
 * @brief Elige que estrategia de nodos a expendir usar
 * 
 * @return ExpansiveNode* Nodo a expandir
 */
ExpansiveNode* Tree::nodeToExpand(void) {
  if (expandStrategy_ == 0) {
    return expandNodeByLowerUpperBound();
  } else if (expandStrategy_ == 1) {
    return expandNodeByDepth();
  } else if (expandStrategy_ == 2) {
    return expandBySecondBestNode();
  }
}

/**
 * @brief Expande un nodo por profundidad
 * 
 * @return ExpansiveNode* Nodo a expandir
 */
ExpansiveNode* Tree::expandNodeByDepth(void) {
  int index = 0;
  float maxDepth = nodesToExpand_[0]->getDepth();
  for (int i = 1; i < nodesToExpand_.size(); i++) {
    if (maxDepth < nodesToExpand_[i]->getDepth()) {
      index = i;
      maxDepth = nodesToExpand_[i]->getDepth();
    }
  }
  return nodesToExpand_[index];
}

/**
 * @brief Expande un nodo por la cota superior más baja
 * 
 * @return ExpansiveNode* 
 */
ExpansiveNode* Tree::expandNodeByLowerUpperBound(void) {
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

// PRIMER MODIFICACION
ExpansiveNode* Tree::expandBySecondBestNode() {
  int indexFisrtBest = 0;
  float firstUB = nodesToExpand_[0]->getUpperBound();
  for (int i = 1; i < nodesToExpand_.size(); i++) {
    if (firstUB < nodesToExpand_[i]->getUpperBound()) {
      firstUB = nodesToExpand_[i]->getUpperBound();
      indexFisrtBest = i;
    }
  }

  int indexSecondBest = 0;
  float secondUB = nodesToExpand_[0]->getUpperBound();
  for (int i = 0; i < nodesToExpand_.size(); i++) {
    if (secondUB < nodesToExpand_[i]->getUpperBound() && 
        nodesToExpand_[i] != nodesToExpand_[indexFisrtBest]) {
      secondUB = nodesToExpand_[i]->getUpperBound();
      indexSecondBest = i;
    }
  }

  return nodesToExpand_[indexFisrtBest];
}

/**
 * @brief Devuelve el conjunto de nodos a expandir
 * 
 * @return std::vector<ExpansiveNode*> Nodos a expandir
 */
std::vector<ExpansiveNode*> Tree::getNodesToExpand() {
  return nodesToExpand_;
}
