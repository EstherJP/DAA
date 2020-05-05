#include "../include/constructiveGreedy.hpp"

consGreedy::consGreedy() {}

consGreedy::consGreedy(Data setData) : 
  MaxDivProblem(setData)
{}

void consGreedy::searchSolution(void) {
  std::cout << "distancia dos sets\n";
  std::cout << distanceTwoSets(setData_.getData()[0], setData_.getData()[1]) << std::endl;
}
