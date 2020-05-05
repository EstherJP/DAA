#include "../include/constructiveGreedy.hpp"

consGreedy::consGreedy() {}

consGreedy::consGreedy(Data setData) : 
  MaxDivProblem(setData)
{}

void consGreedy::searchSolution(void) {
  std::vector<std::vector<float>> elements = setData_.getData();
  std::vector<std::vector<float>> auxSol;

  std::cout << "Elementos\n";
  showSolution(elements);

  std::vector<float> center = gravityCenter(elements);
  std::cout << "Primer centro\n";
  for (int i = 0; i < center.size(); i++) {
      std::cout << center[i] << " ";
  }
  std::cout << "\n";

  do {
    std::cout << "Elemento mas alejado" << auxSol.size() << "\n";
    /***/
    std::vector<float> farElement = farElementOfCenter(elements, center); 
    /***/
    
    for (int i = 0; i < farElement.size(); i++) {
        std::cout << farElement[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Lo pongo en la solucion\n";
    
    /***/
    auxSol.push_back(farElement);
    /***/
    
    showSolution(auxSol);
    std::cout << "eliminando el mas alejado\n";
    
    /***/
    elements = deleteElement(elements, farElement);
    /***/
    
    showSolution(elements);
    
    /***/
    center = gravityCenter(auxSol);
    /***/
    
    std::cout << "Recalculo el centro\n";
    for (int i = 0; i < center.size(); i++) {
        std::cout << center[i] << " ";
    }
    std::cout << "\n";
    /***/
  } while (auxSol.size() < 3);

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
