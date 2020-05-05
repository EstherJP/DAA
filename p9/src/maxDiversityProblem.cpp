#include "../include/maxDiversityProblem.hpp"

MaxDivProblem::MaxDivProblem() {

}

MaxDivProblem::MaxDivProblem(Data setData) :
  setData_(setData)
{}

MaxDivProblem::~MaxDivProblem() {}

std::vector<std::vector<float>> MaxDivProblem::getBestSolution(void) {
  return bestSolution_;
}

float MaxDivProblem::distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet) {
  float sum = 0;
  for (int i = 0; i < setData_.getElementsSize(); i++) {
    float sub = firstSet[i] - secondSet[i];
    sub = pow(sub, 2);
    sum += sub;
  }
  return sqrt(sum);
}

std::vector<float> MaxDivProblem::farElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center) {
  float oldDistance = distanceTwoSets(elements[0], center);
  int farIndex = 0;
  for (int i = 1; i < elements.size(); i++) {
    float newDistance = distanceTwoSets(elements[i], center);
    if (oldDistance < newDistance) {
      oldDistance = newDistance;
      farIndex = i;
    }
  } 
  return elements[farIndex];
}


std::vector<std::vector<float>> MaxDivProblem::deleteElement(std::vector<std::vector<float>> elements, std::vector<float> deleted) {
  for (auto iter = elements.begin(); iter != elements.end(); iter++) {
    if (*iter == deleted) {
      elements.erase(iter);
    }
  }

  return elements;
}


std::vector<float> MaxDivProblem::gravityCenter(std::vector<std::vector<float>> auxSol) {
  std::vector<float> center;
  for (int i = 0; i < setData_.getElementsSize(); i++) {
    float sum = 0;
    for (int j = 0; j < auxSol.size(); j++) {
      sum += auxSol[j][i];
    }
    center.push_back(sum / auxSol.size());
    sum = 0;
  } 
  return center;
}



void MaxDivProblem::showSolution(void) {
  std::cout << "Distancia máxima: " << std::endl;
  std::cout << "Mejor solución: " << std::endl;
  for (int i = 0; i < bestSolution_.size(); i++) {
    std::cout << "Conjunto " << i + 1 << ":  ";
    for (int j = 0; j < bestSolution_[i].size(); j++) {
      std::cout << bestSolution_[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
