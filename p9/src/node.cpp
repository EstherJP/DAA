#include "../include/node.hpp"

ExpansiveNode::ExpansiveNode(void) {}

ExpansiveNode::ExpansiveNode(std::vector<float> node, int vectorId, int depth, std::vector<std::vector<float>> noInSolution) : 
  node_(node),
  vectorId_(vectorId),
  depth_(depth),
  noInSolution_(noInSolution)
{}

ExpansiveNode::~ExpansiveNode() {}

std::vector<float> ExpansiveNode::getNode(void) {
  return node_;
}

float ExpansiveNode::getDispersion(void) {
  return dispertion_;
}

int ExpansiveNode::getDepth(void) {
  return depth_;
}

bool ExpansiveNode::isExpanded(void) {
  return expanded_;
}

bool ExpansiveNode::isPruned(void) {
  return pruned_;
}

std::vector<ExpansiveNode*> ExpansiveNode::getParents(void) {
  return parents_;
}

void ExpansiveNode::setParents(ExpansiveNode* parent) {
  parents_.push_back(parent);
}

void ExpansiveNode::prune(void) {
  pruned_ = true;
}

void ExpansiveNode::expand(void) {
  expanded_ = true;
}

void ExpansiveNode::upperBound(int solSize) {
  int numberNodes = solSize - depth_;
  
}

void ExpansiveNode::writeNode(void) {
  std::cout << "\nNodo: ";
  for (int i = 0; i < node_.size(); i++) {
    std::cout << node_[i] << " ";
  }
  // std::cout << "no nodes: \n";
  // for (int i = 0; i < noInSolution_.size(); i++) {
  //   std::cout << "Conjunto " << i + 1 << ":  ";
  //   for (int j = 0; j < noInSolution_[i].size(); j++) {
  //     std::cout << noInSolution_[i][j] << " ";
  //   }
  //   std::cout << "\n";
  // }
  // std::cout << "\n";
  std::cout << "\n";
  std::cout << "Id Node: " << vectorId_ << "\n";
  std::cout << "Profundidad: " << depth_ << "\n";
  std::cout << "Expandido: " << expanded_ << "\n";
  std::cout << "Podado: " << pruned_ << "\n";
  std::cout << "Dispersion: " << dispertion_ << "\n\n";
  std::cout << "Rama: ";
    for (int i = 0; i < parents_.size(); i++) {
    std::cout << "S " << i + 1 << ":  ";
    for (int j = 0; j < parents_[i]->getNode().size(); j++) {
      std::cout << parents_[i]->getNode()[j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
