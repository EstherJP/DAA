// TAREA 3

#include "../include/GRASP-VNS.hpp"

GraspVNS::GraspVNS(Graph affinities, Grasp* grasp, int stopCriteria, int searchCriteria, int environmentCriteria) :
  MaxMean(affinities),
  grasp_(grasp)
{}

GraspVNS::~GraspVNS() {

}

std::vector<int> GraspVNS::swapEnvironment(std::vector<int> auxSol) {
  std::vector<int> candidates;
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    if (!isInSolution(i, auxSol)) {
      candidates.push_back(i);
    }
  }
  
  int swapped = 0;
  int swapNumber = rand() % affinities_.getNumberVertex();
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
  return auxSol;
}

void GraspVNS::searchSolution(void) {
  std::cout << "Tarea 3\n";
  int iter = 1;
  initializeAll();
  std::vector<int> finalSol = bestSolution_;
  float finalMean = bestMean_;

  do {
    grasp_->constructivePhase();
    std::vector<int> auxSol = grasp_->getBestSolution();
    float auxMean = meanDispersion(auxSol);
    int k = 1;
    do {
      for (int i = 0; i < affinities_.getNumberVertex(); i++) {
        bestSolution_ = generateNeightbourd(i);
        bestMean_ = meanDispersion(bestSolution_);
        if (k = 3) {
          bestSolution_ = swapEnvironment(auxSol);
          bestMean_ = meanDispersion(bestSolution_);
          k++;
        }
        if (bestSolution_ != auxSol) {
          break;
        }
        postProcessing();
        if (bestMean_ > auxMean) {
          auxMean = bestMean_;
          auxSol = bestSolution_;
          k = 1;
          stopCriteria_ = 1;
        } else {
          stopCriteria_ = 2;
          k++;
        }
      }
    } while (k < 4);
    if (auxMean > finalMean) {
      finalMean = auxMean;
      finalSol = auxSol;
    }
    iter++;
  } while (iter < 5);

  bestSolution_ = finalSol;
  bestMean_ = finalMean;
}