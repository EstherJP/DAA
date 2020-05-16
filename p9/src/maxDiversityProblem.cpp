#include "../include/maxDiversityProblem.hpp"

MaxDivProblem::MaxDivProblem() {}

MaxDivProblem::MaxDivProblem(Data setData, int solSize, int maxIter) :
  setData_(setData),
  solutionSize_(solSize),
  maxIter_(maxIter_)
{
  srand(time(NULL));
}

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

int MaxDivProblem::getSolutionSize(void) {
  return solutionSize_;
}

std::vector<std::vector<float>> MaxDivProblem::getAllNodes(void) {
  return setData_.getData();
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

float MaxDivProblem::swapDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, std::vector<float> swapped, float currentDistance) {
  for (int i = 0; i < newSol.size(); i++) {
    if (newSol[i] != added) {
      currentDistance += distanceTwoSets(newSol[i], added);
      currentDistance -= distanceTwoSets(newSol[i], swapped);
    } 
  }
  return currentDistance;
}

float MaxDivProblem::addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance) {
  currentDistance *= newSol.size() - 1;
  for (int i = 0; i < newSol.size(); i++) {
    if (newSol[i] != added) {
      currentDistance += distanceTwoSets(newSol[i], added);
    } 
  }
  return currentDistance / newSol.size();
}

std::vector<std::vector<float>> MaxDivProblem::generateNeightbour(std::vector<std::vector<float>> currentSol, std::vector<float> element, int swapNumber) {
  currentSol[swapNumber] = element;
  return currentSol;
}

void MaxDivProblem::generateRandomSolution(void) {
  while (bestSolution_.size() != solutionSize_) {
    int random = rand() % solutionSize_;
    if (!isInSolution(bestSolution_, setData_.getData()[random])) {
      bestSolution_.push_back(setData_.getData()[random]);
    }
  }
  bestDistance_ = totalDistance(bestSolution_);
}

float MaxDivProblem::getBestDistance(void) {
  return bestDistance_;
}

void MaxDivProblem::localGreedySearch(std::vector<std::vector<float>> currentSol, float currentDistance) {
  std::vector<std::vector<float>> neightbour;
  float neightbourDistance;
  std::vector<std::vector<float>> auxSol = currentSol;
  float auxDistance = currentDistance;
  bool keepSearching;
  std::vector<float> added;
  std::vector<float> deleted;
  do {
    keepSearching = false;
    for (int i = 0; i < currentSol.size(); i++) {
      for (int j = 0; j < noInSolution_.size(); j++) {
        neightbour = generateNeightbour(currentSol, noInSolution_[j], i);
        neightbourDistance = swapDistance(neightbour, noInSolution_[j], currentSol[i], currentDistance);
        if (auxDistance < neightbourDistance) {
          auxSol = neightbour;
          auxDistance = neightbourDistance;
          deleted = noInSolution_[j];
          added = currentSol[i];
          keepSearching = true;
        }
      }
    }
    noInSolution_ = deleteElement(noInSolution_, deleted);
    noInSolution_.push_back(added);
    currentSol = auxSol;
    currentDistance = auxDistance;
  } while (keepSearching);
  bestSolution_ = auxSol;
  bestDistance_ = auxDistance;
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

void MaxDivProblem::postProcessing(void) {
  // std::cout << "Antes\n";
  // showSolution(bestSolution_);
  localGreedySearch(bestSolution_, bestDistance_);
  // std::cout << "Despues\n";
  showSolution(bestSolution_);
}

void MaxDivProblem::showSolution(std::vector<std::vector<float>> sol) {
  bestDistance_ = totalDistance(sol);
  std::cout << "Distancia máxima: " << bestDistance_<< std::endl;
  // std::cout << "Mejor solución: " << std::endl;
  for (int i = 0; i < sol.size(); i++) {
    std::cout << "Conjunto " << i + 1 << ":  ";
    for (int j = 0; j < sol[i].size(); j++) {
      std::cout << sol[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
