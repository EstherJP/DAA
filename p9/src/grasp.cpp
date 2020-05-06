#include "../include/grasp.hpp"
    
Grasp::Grasp() {}

Grasp::Grasp(Data setData) :
  MaxDivProblem(setData)
{}

Grasp::~Grasp() {}

void Grasp::searchSolution(void) {
  std::vector<std::vector<float>> elements = setData_.getData();
  float dis = totalDistance(elements);

}



    // noInSolution_.push_back(elements[0]);
    // elements = deleteElement(elements, elements[0]);

    // noInSolution_.push_back(elements[0]);
    // elements = deleteElement(elements, elements[0]);

    // std::cout << "Sol" << std::endl;
    // showSolution(elements);

    // std::cout << "No Sol" << std::endl;
    // showSolution(noInSolution_);

    // dis = totalDistance(elements);

    // std::cout << "Solucion final " << std::endl;
    // localGreedySearch(elements, dis);
    // showSolution(elements);
    // dis = totalDistance(elements);

  // std::cout << "Dis " << dis << std::endl;
/** TESTS CUTRES **/
// std::vector<std::vector<float>> elements = setData_.getData();

// std::vector<float> element = elements[0];

// std::cout << isInSolution(elements, element) << std::endl;
// elements = deleteElement(elements, element);
// std::cout << isInSolution(elements, element) << std::endl;
// std::cout << isInSolution(elements, elements[3]) << std::endl;