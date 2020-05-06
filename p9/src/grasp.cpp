#include "../include/grasp.hpp"
    
Grasp::Grasp() {}

Grasp::Grasp(Data setData) :
  MaxDivProblem(setData)
{}

Grasp::~Grasp() {}

void Grasp::searchSolution(void) {


}

/** TESTS CUTRES **/
// std::vector<std::vector<float>> elements = setData_.getData();

// std::vector<float> element = elements[0];

// std::cout << isInSolution(elements, element) << std::endl;
// elements = deleteElement(elements, element);
// std::cout << isInSolution(elements, element) << std::endl;
// std::cout << isInSolution(elements, elements[3]) << std::endl;