#include "../include/maxMeanStrategyBase.hpp"

MaxMean::MaxMean(Graph affinities): 
  affinities_(affinities)
{}

MaxMean::~MaxMean() {}

std::vector<int> MaxMean::getBestSolution(void) {
  return bestSolution_;
}

bool MaxMean::isInCurrentSolution(float node) {
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    if (bestSolution_[i] == node) {
      return true;
    }
  }
  return false;
}

float MaxMean::meanDispersion(std::vector<int> nodes) {
  float sum = 0;
  int iterNodeI = 0;
  for (size_t i = iterNodeI; i < nodes.size(); i++) {
    for (size_t j = i + 1; j < nodes.size(); j++) {
      sum += affinities_.getValue(nodes[i], nodes[j]);
    }
  }
  return (sum / nodes.size());
}


void MaxMean::showSolution(void) {
  std::cout << "\nMejor media: " << bestMean_ << std::endl;
  std::cout << "Conjunto de nodos: " << std::endl;
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    std::cout << bestSolution_[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

float MaxMean::getMax(void) {
  bestSolution_.clear();
  float max = FLT_MIN;
  int iMax;
  int jMax;
      
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    for (int j = i; j < affinities_.getNumberVertex(); j++) {
      if (affinities_.getValue(i, j) > max) {
        max = affinities_.getValue(i, j);
        iMax = i;
        jMax = j;
      } else if (affinities_.getValue(i, j) == max) {
        int random = rand() % 2;
        if (random == 1) {
          max = affinities_.getValue(i, j);
          iMax = i;
          jMax = j;
        }
      }
    }
  }

  bestSolution_.push_back(iMax);
  bestSolution_.push_back(jMax);
  return max / 2.0;
}

void MaxMean::updateSolution(std::vector<int> currentSolution, float currentMean) {
  if (bestMean_ < currentMean) {
    bestMean_ = currentMean;
    numberIterWithoutImprove = 0;
  } else {
    bestSolution_ = currentSolution;
    numberIterWithoutImprove++;
  }
}

bool MaxMean::stopCriteria(int nIterations) {
  switch (stopCriteria_)  {
  case 1:
    return nIterations < MAXITERATIONS;
    break;
  
  case 2:
    return numberIterWithoutImprove < MAXITERATIONS;
    break;
  
  default:
    throw "Error: You need to set the stop criteria";
    break;
  }
}

void MaxMean::localGreedySearch(void) {
  float currentMean = bestMean_;
  std::vector<int> currentSolution_;

  float neightbourdMean;
  std::vector<int> neightbourdSolution;
  bool keepSearchingBest;
  
  do {
    keepSearchingBest = false;
    for (int node = 0; node < affinities_.getNumberVertex(); node++) {
      neightbourdSolution = generateNeightbourd(node);
      neightbourdMean = meanDispersion(neightbourdSolution);

      if (neightbourdMean > bestMean_) {
        currentSolution_ = neightbourdSolution;
        currentMean = neightbourdMean;
        keepSearchingBest = true;
      } 
    }
    bestSolution_ = currentSolution_;
    bestMean_ = currentMean;
  } while (keepSearchingBest);
}

std::vector<int> MaxMean::generateNeightbourd(int node) {
  std::vector<int> neightbourd = bestSolution_;
  
  switch (environmentCriteria_) {
  case 1: // Apertura
    if (!isInCurrentSolution(node)) {
      neightbourd.push_back(node);
      return neightbourd;
    }
    break;
  
  case 2: // Cierre
    if (isInCurrentSolution(node)) {
      for (auto iter = neightbourd.begin(); iter != neightbourd.end(); iter++) {
        if (*iter == node) {
          neightbourd.erase(iter);
          break;
        }
      }
    }

  default:
    throw "Error: You need to set an environment criteria";
    break;
  }
}

void MaxMean::localAnxiousSearch(void) {
  float currentMean = bestMean_;
  for (int node = 0; node < affinities_.getNumberVertex(); node++) {
    std::vector<int> neightbourdSolution = generateNeightbourd(node);
    float neightbourdMean = meanDispersion(neightbourdSolution);
  
    if (neightbourdMean > bestMean_) {
      bestSolution_ = neightbourdSolution;
      bestMean_ = neightbourdMean;
      break;
    } 
  }
}

void MaxMean::postProcessing(void) {
  switch (searchCriteria_) {
  case 1:
    localAnxiousSearch();
    break;
  
  case 2:
    localGreedySearch();
    break;
  
  default:
    throw "Error: You need to set a local search";
    break;
  }
}

float MaxMean::meanDispersionAdd(int node, float currentMean, std::vector<int> nodes) {
  float costNode = 0;
  for (int i = 0; i < nodes.size(); i++) {
    costNode += affinities_.getValue(nodes[i], node);
  }
  costNode++;
  return ((currentMean * (nodes.size() - 1) + costNode) / nodes.size());
}

float MaxMean::meanDispersionSub(int node, float currentMean, std::vector<int> nodes) {
  float costNode = 0;
  for (int i = 0; i < nodes.size(); i++) {
    costNode += affinities_.getValue(nodes[i], node);
  }
  return ((currentMean * (nodes.size()) - costNode) / (nodes.size() - 1));
}
