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

float MaxDivProblem::totalDistance(std::vector<std::vector<float>> auxSol) {
  float auxDistance = 0;
  for (int i = 0; i < auxSol.size() - 1; i++) {
    for (int j = i + 1; j < auxSol.size(); j++) {
      auxDistance += distanceTwoSets(auxSol[j], auxSol[i]);
    }
  }
  // bestDistance_ = auxDistance;
  return auxDistance;
}

std::vector<std::vector<float>> MaxDivProblem::deleteElement(std::vector<std::vector<float>> elements, std::vector<float> deleted) {
  for (auto iter = elements.begin(); iter < elements.end(); iter++) {
    if (*iter == deleted) {
      elements.erase(iter);
    }
  }
  return elements;
}

bool MaxDivProblem::isInSolution(std::vector<std::vector<float>> auxSol, std::vector<float> element) {
  for (int i = 0; i < auxSol.size(); i++) {
    if (auxSol[i] == element) {
      return true;
    }
  }
  return false;
}

std::vector<std::vector<float>> MaxDivProblem::generateNeightbour(std::vector<std::vector<float>> currentSol, std::vector<float> element, int swapNumber) {
  
  
}

std::vector<std::vector<float>> MaxDivProblem::localGreedySearch(std::vector<std::vector<float>> currentSol, float currentDistance) {
  std::vector<std::vector<float>> neightbour;
  float neightbourDistance;
  std::vector<std::vector<float>> auxSol = currentSol;
  float auxDistance = currentDistance;

  for (int i = 0; i < currentSol.size(); i++) {
    for (int j = 0; j < noInSolution_.size(); j++) {
      neightbour = generateNeightbour(currentSol, noInSolution_[j], i);
      neightbourDistance = totalDistance(neightbour); // Equilibramos con swap
      if (auxDistance < neightbourDistance) {
        auxSol = neightbour;
        auxDistance = neightbourDistance;
      }
    }
  }
  return auxSol;
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



void MaxDivProblem::showSolution(std::vector<std::vector<float>> sol) {
  bestDistance_ = totalDistance(bestSolution_);
  std::cout << "Distancia máxima: " << bestDistance_<< std::endl;
  std::cout << "Mejor solución: " << std::endl;
  for (int i = 0; i < sol.size(); i++) {
    std::cout << "Conjunto " << i + 1 << ":  ";
    for (int j = 0; j < sol[i].size(); j++) {
      std::cout << sol[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
