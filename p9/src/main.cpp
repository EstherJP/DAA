#include <iostream>

#include "../include/data.hpp"
#include "../include/constructiveGreedy.hpp"
#include "../include/destructiveGreedy.hpp"
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

    consGreedy* consgreedy = new consGreedy(setData);
    desGreedy* desgreedy = new desGreedy(setData);

    maxDivCalculator* interface = new maxDivCalculator(consgreedy);
    std::cout << "--- Constructivo voraz ---\n";
    interface->maxMeanInterface();

    std::cout << "\n--- Destruvtivo voraz ---\n";
    interface->setStrategy(desgreedy);
    interface->maxMeanInterface();



  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}