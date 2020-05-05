#include "../include/constructiveGreedy.hpp"

consGreedy::consGreedy() {}

consGreedy::consGreedy(Data setData) : 
  MaxDivProblem(setData)
{}

void consGreedy::searchSolution(void) {
  std::vector<std::vector<float>> elements = setData_.getData();
  std::vector<std::vector<float>> auxSol;

  std::vector<float> center = gravityCenter(elements);
  do {
    std::vector<float> farElement = farElementOfCenter(elements, center); 
    auxSol.push_back(farElement);
    elements = deleteElement(elements, farElement);
    center = gravityCenter(auxSol);
  } while (auxSol.size() < m_);

  bestSolution_ = auxSol;
  showSolution(bestSolution_);
}
/** TESTS CUTRES **/
  // std::cout << "mas lejos\n";
  // elements =  deleteElement(elements, elements[2]);
  // std::cout << "eliminar un vector\n";
  // for (int i = 0; i < elements.size(); i++) {
  //   for (int j = 0; j < elements[i].size(); j++) {
  //     std::cout << elements[i][j] << " ";
  //   }
  //   std::cout << "\n";
  // }
  // std::cout << "\n";
  // std::cout << "distancia dos sets\n";
  // std::cout << distanceTwoSets(setData_.getData()[2], setData_.getData()[3]) << std::endl;
  // std::cout << "centro\n";
  // std::vector<float> centro = gravityCenter(setData_.getData());
  // for (int i = 0; i < centro.size(); i++) {
  //     std::cout << centro[i] << " ";
  // }
  // std::cout << "\n";
