#include "../include/destructiveGreedy.hpp"

desGreedy::desGreedy() {}

desGreedy::desGreedy(Data setData) : 
  MaxDivProblem(setData)
{}

std::vector<float> desGreedy::nearElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center) {
  float oldDistance = distanceTwoSets(elements[0], center);
  int nearIndex = 0;
  for (int i = 1; i < elements.size(); i++) {
    float newDistance = distanceTwoSets(elements[i], center);
    if (oldDistance > newDistance) {
      oldDistance = newDistance;
      nearIndex = i;
    }
  } 
  return elements[nearIndex];
}

void desGreedy::searchSolution(void) {
  std::vector<std::vector<float>> auxSol = setData_.getData();

  std::vector<float> center = gravityCenter(auxSol);
  do {
    std::vector<float> nearElement = nearElementOfCenter(auxSol, center); 
    auxSol = deleteElement(auxSol, nearElement);
    center = gravityCenter(auxSol);
  } while (auxSol.size() > m_);
  bestSolution_ = auxSol;
  showSolution(auxSol);
}