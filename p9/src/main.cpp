#include <iostream>
#include <ctime>
#include <chrono>

#include "../include/data.hpp"
#include "../include/constructiveGreedy.hpp"
#include "../include/destructiveGreedy.hpp"
#include "../include/maxDiversityCalculator.hpp"
#include "../include/grasp.hpp"
#include "../include/branchAndBound.hpp"

using namespace std;

// LINEA DE COMANDOS: fichero m iter lrc
int main(int argc, char* argv[]) {
  if (argc <= 1) {
    throw "Error: needs a file";
  } 

  try {
    char* filename = argv[1];
    std::cout << "File name: " << filename << std::endl;
    int solutionSize = atoi(argv[2]);
    int maxIter = atoi(argv[3]);
    int cardinality = atoi(argv[4]);

    Data setData(filename);
    // setData.write();

    consGreedy* consgreedy = new consGreedy(setData, solutionSize, maxIter);
    desGreedy* desgreedy = new desGreedy(setData, solutionSize, maxIter);
    Grasp* grasp = new Grasp(setData, solutionSize, maxIter, cardinality);
    maxDivCalculator* interface = new maxDivCalculator(consgreedy);

    std::chrono::time_point<chrono::system_clock> startTime, endTime;
    std::chrono::duration<float, std::milli> duration; 
    std::cout << "--- Constructivo voraz ---\n";
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    // std::cout << "--- Constructivo voraz con búsqueda local ---\n";
    // startTime = std::chrono::system_clock::now();
    // interface->greedySearch();
    // endTime = std::chrono::system_clock::now();
    // duration = endTime - startTime;
    // std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    // std::cout << "\n--- Destructivo voraz ---\n";
    // interface->setStrategy(desgreedy);
    // startTime = std::chrono::system_clock::now();
    // interface->maxMeanInterface();
    // endTime = std::chrono::system_clock::now();
    // duration = endTime - startTime;
    // std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    // std::cout << "--- Destructivo voraz con búsqueda local ---\n";
    // startTime = std::chrono::system_clock::now();
    // interface->greedySearch();
    // endTime = std::chrono::system_clock::now();
    // duration = endTime - startTime;
    // std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    // std::cout << "\n--- Grasp ---\n";
    // interface->setStrategy(grasp);
    // startTime = std::chrono::system_clock::now();
    // interface->maxMeanInterface();
    // endTime = std::chrono::system_clock::now();
    // duration = endTime - startTime;
    // std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Ramificación y poda ---\n";
    BranchBound* bb = new BranchBound(consgreedy);
    bb->branchBound();
    bb->showSolution();
    

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}