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
    std::cout << "\n--- Constructivo voraz ---\n";
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Constructivo voraz con búsqueda local ---\n";
    startTime = std::chrono::system_clock::now();
    interface->greedySearch();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Destructivo voraz ---\n";
    interface->setStrategy(desgreedy);
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Destructivo voraz con búsqueda local ---\n";
    startTime = std::chrono::system_clock::now();
    interface->greedySearch();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Grasp ---\n";
    interface->setStrategy(grasp);
    startTime = std::chrono::system_clock::now();
    interface->maxMeanInterface();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    // delete consgreedy;
    // delete desgreedy;
    // delete grasp;
    // delete interface;

    std::cout << "\n--- Ramificación y poda con constructivo voraz expandiendo la cota más pequeña ---\n";
    consgreedy = new consGreedy(setData, solutionSize, maxIter);
    consgreedy->searchSolution();
    BranchBound* branchBound = new BranchBound(consgreedy, 0);
    startTime = std::chrono::system_clock::now();
    branchBound->branchBound();
    branchBound->showSolution();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;
    
    std::cout << "\n--- Ramificación y poda con destructivo voraz expandiendo la cota más pequeña ---\n";
    desgreedy = new desGreedy(setData, solutionSize, maxIter);
    desgreedy->searchSolution();
    branchBound = new BranchBound(desgreedy, 0);
    startTime = std::chrono::system_clock::now();
    branchBound->branchBound();
    branchBound->showSolution();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Ramificación y poda con grasp expandiendo la cota más pequeña ---\n";
    grasp = new Grasp(setData, solutionSize, maxIter, cardinality);
    grasp->searchSolution();
    branchBound = new BranchBound(grasp, 0);
    startTime = std::chrono::system_clock::now();
    branchBound->branchBound();
    branchBound->showSolution();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\n--- Ramificación y poda con constructivo voraz expandiendo por profundidad ---\n";
    consgreedy = new consGreedy(setData, solutionSize, maxIter);
    consgreedy->searchSolution();
    branchBound = new BranchBound(consgreedy, 1);
    startTime = std::chrono::system_clock::now();
    branchBound->branchBound();
    branchBound->showSolution();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;
    
    std::cout << "\n--- Ramificación y poda con destructivo voraz expandiendo por profundidad ---\n";
    desgreedy = new desGreedy(setData, solutionSize, maxIter);
    desgreedy->searchSolution();
    branchBound = new BranchBound(desgreedy, 1);
    startTime = std::chrono::system_clock::now();
    branchBound->branchBound();
    branchBound->showSolution();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;

    std::cout << "\n--- Ramificación y poda con grasp expandiendo por profundidad ---\n";
    grasp = new Grasp(setData, solutionSize, maxIter, cardinality);
    grasp->searchSolution();
    branchBound = new BranchBound(grasp, 1);
    startTime = std::chrono::system_clock::now();
    branchBound->branchBound();
    branchBound->showSolution();
    endTime = std::chrono::system_clock::now();
    duration = endTime - startTime;
    std::cout << "Tiempo transcurrido: " << duration.count() << "ms" << std::endl;
  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}