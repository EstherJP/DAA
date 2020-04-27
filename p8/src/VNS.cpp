#include "../include/VNS.hpp"

VNS::VNS(Graph affinities, Grasp* grasp, int stopCriteria, int searchCriteria, int environmentCriteria) : 
  MaxMean(affinities),
  grasp_(grasp)
{
  stopCriteria_ = stopCriteria;
  searchCriteria_ = searchCriteria;
  environmentCriteria_ = environmentCriteria;
  srand(time(NULL));
}

void VNS::makeVNS(std::vector<int> auxSol, float auxMean){
  for (int swapChanges = 1; swapChanges < 4; swapChanges++) {
    shake(auxSol, auxMean, swapChanges);
    if (bestMean_ > auxMean) {
      auxMean = bestMean_;
      auxSol = bestSolution_;
      swapChanges = 0;
    }
  }
  bestSolution_ = auxSol;
  bestMean_ = auxMean;
}

std::vector<int> VNS::shake(std::vector<int> auxSol, float auxMean, int swapNumber) {
  std::vector<int> candidates;
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    if (!isInSolution(i, auxSol)) {
      candidates.push_back(i);
    }
  }
  
  int swapped = 0;
  std::vector<int> nodeWasChanged(auxSol.size(), 0);
  for (int i = 0; i < swapNumber; i++) {
    int randomNodeSol = rand() % auxSol.size();
    std::vector<int>::iterator swapCandidate;

    if ((candidates.size() != 0) && (swapped != nodeWasChanged.size())) {
      swapCandidate = candidates.begin();
      std::advance(swapCandidate, (rand() % candidates.size()));
    } else {
      break;
    }

    if (nodeWasChanged[randomNodeSol] != 1) {
      auxSol[randomNodeSol] = *swapCandidate;
      candidates.erase(swapCandidate);
      swapped++;
      nodeWasChanged[randomNodeSol] = 1;
    } else {
      i--;
    }
  }  
  bestMean_ = meanDispersion(auxSol);
  bestSolution_ = auxSol;
  postProcessing();
}

void VNS::searchSolution(void) {
  int iterations = 0;
  std::vector<int> auxSol;
  float auxMean;

  std::vector<int> finalSol;
  float finalMean = FLT_MIN;
  do {
    grasp_->searchSolution();
    // grasp_->generateRandomSolution();
    auxSol = grasp_->getBestSolution();
    auxMean = grasp_->getBestMean();

    makeVNS(auxSol, auxMean);
    if (finalMean < bestMean_) {
      finalSol = bestSolution_;
      finalMean = bestMean_;
    }
    iterations++;
  } while(stopCriteria(iterations));
  bestSolution_ = finalSol;
  bestMean_ = finalMean;
}