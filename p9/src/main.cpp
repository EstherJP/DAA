#include <iostream>

#include "../include/data.hpp"
#include "../include/constructiveGreedy.hpp"
#include "../include/maxDiversityCalculator.hpp"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    throw "Error: needs a file";
  } 

  try {
    char* filename = argv[1];
    std::cout << "File name: " << filename << std::endl;

    Data setData(filename);
    // setData.write();

    std::cout << "--- Constructivo voraz ---\n";
    consGreedy* consgreedy = new consGreedy(setData);

    maxDivCalculator* interface = new maxDivCalculator(consgreedy);
    interface->maxMeanInterface();
    

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}