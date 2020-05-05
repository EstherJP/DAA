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
    std::cout << firstSet[i] << " - " << secondSet[i] << "\n";
    sub = pow(sub, 2);
    std::cout << sub << " ^2\n";
    sum += sub;
    std::cout << "sum " << sum << "\n";
  }

  std::cout << "return " << sqrt(sum) << "\n";
  return sqrt(sum);
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
