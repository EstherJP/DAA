/**
 * @file constructiveGreedy.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de un algoritmo voraz constructivo
 * que resuelve el problema de máxima diverdidad
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/constructiveGreedy.hpp"

/**
 * @brief Construct a new cons Greedy::cons Greedy object
 */
consGreedy::consGreedy() {}

/**
 * @brief Construct a new cons Greedy::cons Greedy object
 * 
 * @param setData Datos del problema
 * @param solSize Tamaño de la solución 
 * @param maxIter Máximo número de iteraciones
 */
consGreedy::consGreedy(Data setData, int solSize, int maxIter) : 
  MaxDivProblem(setData, solSize, maxIter)
{}

/**
 * @brief Algoritmo voraz constructivo
 */
void consGreedy::searchSolution(void) {
  std::vector<std::vector<float>> elements = setData_.getData();
  std::vector<std::vector<float>> auxSol;

  std::vector<float> center = gravityCenter(elements);
  do {
    std::vector<float> farElement = farElementOfCenter(elements, center); 
    auxSol.push_back(farElement);
    elements = deleteElement(elements, farElement);
    center = gravityCenter(auxSol);
  } while (auxSol.size() < solutionSize_);
  noInSolution_ = elements;
  bestSolution_ = auxSol;
  bestDistance_ = totalDistance(bestSolution_);
}
