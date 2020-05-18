#include "../include/node.hpp"

ExpansiveNode::ExpansiveNode(void) {}

ExpansiveNode::ExpansiveNode(std::vector<float> node, int vectorId, int depth, std::vector<std::vector<float>> noInSolution, 
    std::vector<std::vector<float>> partialSol, float dispersion) : 
  node_(node),
  vectorId_(vectorId),
  depth_(depth),
  noInSolution_(noInSolution),
  partialSolution_(partialSol),
  dispersion_(dispersion)
{}

ExpansiveNode::~ExpansiveNode() {}

std::vector<float> ExpansiveNode::getNode(void) {
  return node_;
}

float ExpansiveNode::getDispersion(void) {
  return dispersion_;
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

void ExpansiveNode::prune(void) {
  pruned_ = true;
}

void ExpansiveNode::expand(void) {
  expanded_ = true;
}

float ExpansiveNode::distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet) {
  float sum = 0;
  for (int i = 0; i < firstSet.size(); i++) {
    float sub = firstSet[i] - secondSet[i];
    sub = pow(sub, 2);
    sum += sub;
  }
  return sqrt(sum);
}

float ExpansiveNode::addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance) {
   float newDistance = currentDistance;

  for (int i = 0; i < newSol.size(); i++) {
    if (newSol[i] != added)
      newDistance += distanceTwoSets(newSol[i], added);
  }
  return newDistance;
}

int ExpansiveNode::getId() {
  return vectorId_;
}

std::vector<std::vector<float>> ExpansiveNode::getPartialSolution() {
  return partialSolution_;
}

float ExpansiveNode::getUpperBound() {
  return upperBound_;
}


void ExpansiveNode::upperBound(int solSize) {
  int numberNodes = solSize - depth_;
  dispersion_ = addDistance(partialSolution_, node_, dispersion_);
  float maxDist = getBestDistance();
  int numberEdges = partialSolution_.size() * (solSize - partialSolution_.size());
  // std::cout << "edge 1 " << numberEdges << "\n";
  numberEdges += ((solSize - partialSolution_.size()) * (solSize - partialSolution_.size() - 1 )) / 2;

  // std::cout << "edge 2 " << numberEdges << "\n";
  upperBound_ = (maxDist * numberEdges) + dispersion_;
  // std::cout << "max " << maxDist << " edg " << numberEdges << "\n";
  // std::cout << "cota " << upperBound_ << "\n";
}

float ExpansiveNode::getBestDistance() {
  float auxDistanceOut = -1;
  for (int i = 0; i < noInSolution_.size(); i++) {
    for (int j = i + 1; j < noInSolution_.size(); j++) {
      float currentDistance = distanceTwoSets(noInSolution_[i], noInSolution_[j]);
      if (currentDistance > auxDistanceOut) {
        auxDistanceOut = currentDistance;
      }
    }
  }
  // return auxDistance;
  float auxDistanceBetween = -1;
  for (int i = 0; i < partialSolution_.size(); i++) {
    for (int j = 0; j < noInSolution_.size(); j++) {
      float currentDistance = distanceTwoSets(partialSolution_[i], noInSolution_[j]);
      if (currentDistance > auxDistanceBetween) {
        auxDistanceBetween = currentDistance;
      } 
    }
  }
  // std::cout << "Bett " << auxDistanceBetween << " Out " << auxDistanceOut << "\n";
  if (auxDistanceBetween > auxDistanceOut) {
    return auxDistanceBetween;
  } else{
    return auxDistanceOut;
  }
}

std::vector<std::vector<float>> ExpansiveNode::getNoInSolution() {
  return noInSolution_;
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
  std::cout << "UpperBound: " << upperBound_ << "\n";
  std::cout << "Dispersion: " << dispersion_ << "\n";
  std::cout << "Rama: \n";
    for (int i = 0; i < partialSolution_.size(); i++) {
    std::cout << "S" << i + 1 << ":  ";
    for (int j = 0; j < partialSolution_[i].size(); j++) {
      std::cout << partialSolution_[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
