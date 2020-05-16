#include "../include/grasp.hpp"
    
Grasp::Grasp() {}

Grasp::Grasp(Data setData, int solSize, int maxIter, int cardinality) :
  MaxDivProblem(setData, solSize, maxIter),
  cardinality_(cardinality)
{
  srand(time(NULL));
}

Grasp::~Grasp() {}

void Grasp::addLRC(std::vector<float> currentSet, float currentDistance) {
  if (LRC_.size() < cardinality_) {
    LRC_.push_back(std::make_pair(currentSet, currentDistance));
  } else {
    float currentMinDistance  = currentDistance;
    int posMin = -1;
    for (int i = 0; i < cardinality_; i++) {
      if (currentMinDistance > LRC_[i].second) {
        posMin = i;
        currentMinDistance = LRC_[i].second;
      } else if (currentMinDistance == LRC_[i].second) {
        int random = rand() % 2;
        if (random == 1) {
          posMin = i;
        }
      }  
    }
    if (posMin != -1) {
      LRC_[posMin] = std::make_pair(currentSet, currentDistance);
    }
  }
}

void Grasp::createLRC(void) {
  LRC_.clear();
  std::vector<float> center;

  if (bestSolution_.size() == 0) {
    center = gravityCenter(noInSolution_);
  } else {
    center = gravityCenter(bestSolution_);
  }
  // std::cout << "Centro\n";
  // for (int i = 0; i < center.size(); i++) {
  //   std::cout << center[i] << " ";
  // }
  // std::cout << "\n";

  for (int i = 0; i < noInSolution_.size(); i++) {
    float centerDistance = distanceTwoSets(noInSolution_[i], center);
    addLRC(noInSolution_[i], centerDistance);
  }
}

void Grasp::constructivePhase(void) {
  createLRC();
  do {
    // std::cout << "LRC Vector\n";
    // for (int i = 0; i < LRC_.size(); i++) {
    //   std::cout << "LRC : " << i <<  " Vector -> ";
    //   for (int j = 0; j < LRC_[i].first.size(); j++) {
    //     std::cout << LRC_[i].first[j] << " ";
    //   }
    //   std::cout << " Lejanía " << LRC_[i].second << "\n";
    // }
    int randomNode = rand() % LRC_.size();
    bestSolution_.push_back(LRC_[randomNode].first);
    noInSolution_ = deleteElement(noInSolution_, LRC_[randomNode].first);
    createLRC();
  } while (bestSolution_.size() < solutionSize_);
  bestDistance_ = totalDistance(bestSolution_);
}

void Grasp::searchSolution(void) {
  noInSolution_ = setData_.getData();
  std::vector<std::vector<float>> auxSol;
  float auxDistance = -1;

  int i = 0;
  do {
    noInSolution_ = setData_.getData();
    constructivePhase();
    localGreedySearch(bestSolution_, bestDistance_);

    // std::cout << "Mejor " << auxDistance << " Actual " << bestDistance_ << "\n";
    // showSolution(bestSolution_);
    if (auxDistance < bestDistance_) {
      // std::cout << "Actualizo\n";
      auxDistance = bestDistance_;
      auxSol = bestSolution_;
    }
    bestSolution_.clear();
    bestDistance_ = 0;
    i++;
  } while (i < maxIter_);
  bestSolution_ = auxSol;
  bestDistance_ = auxDistance;
  // std::cout << "final\n";
  showSolution(bestSolution_);
}




  // for (int i = 0; i < LRC_.size(); i++) {
  //   std::cout << "LRC : " << i <<  " Vector -> ";
  //   for (int j = 0; j < LRC_[i].first.size(); j++) {
  //     std::cout << LRC_[i].first[j] << " ";
  //   }
  //   std::cout << " Lejanía " << LRC_[i].second << "\n";
  // }
/** TESTS CUTRES **/
//   std::vector<std::vector<float>> elements = setData_.getData();
//   float dis = totalDistance(elements);

//   noInSolution_.push_back(elements[0]);
//   elements = deleteElement(elements, elements[0]);

//   noInSolution_.push_back(elements[0]);
//   elements = deleteElement(elements, elements[0]);

//   std::cout << "Sol" << std::endl;
//   showSolution(elements);

//   std::cout << "No Sol" << std::endl;
//   showSolution(noInSolution_);
//   dis = totalDistance(elements);

//   std::cout << "Solucion final " << std::endl;
//   localGreedySearch(elements, dis);
//   showSolution(bestSolution_);
//   // dis = totalDistance(elements);

// std::cout << "Dis " << bestDistance_ << std::endl;
// std::vector<std::vector<float>> elements = setData_.getData();

// std::vector<float> element = elements[0];

// std::cout << isInSolution(elements, element) << std::endl;
// elements = deleteElement(elements, element);
// std::cout << isInSolution(elements, element) << std::endl;
// std::cout << isInSolution(elements, elements[3]) << std::endl;