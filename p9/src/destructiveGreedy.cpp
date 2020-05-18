/**
 * @file destructiveGreedy.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de un algoritmo voraz destructivo
 * que resuelve el problema de máxima diverdidad
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/destructiveGreedy.hpp"

/**
 * @brief Construct a new des Greedy::des Greedy object
 */
desGreedy::desGreedy() {}

/**
 * @brief Construct a new des Greedy::des Greedy object
 * 
 * @param setData Datos del problema
 * @param solSize Tamaño de la solución
 * @param maxIter Número máximo de iteraciones
 */
desGreedy::desGreedy(Data setData, int solSize, int maxIter) : 
  MaxDivProblem(setData, solSize, maxIter)
{}

/**
 * @brief Calcula el subconjunto más cercano al centro de un subconjunto
 * 
 * @param elements Conjunto
 * @param center Centro
 * @return std::vector<float> Subconjunto más cercano
 */
std::vector<float> desGreedy::nearElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center) {
  float oldDistance = distanceTwoSets(elements[0], center);
  int nearIndex = 0;
  for (int i = 1; i < elements.size(); i++) {
    float newDistance = distanceTwoSets(elements[i], center);
    if (oldDistance > newDistance) {
      oldDistance = newDistance;
      nearIndex = i;
    }
  } 
  return elements[nearIndex];
}

/**
 * @brief Algoritmo voraz destructivo
 */
void desGreedy::searchSolution(void) {
  std::vector<std::vector<float>> auxSol = setData_.getData();
  std::vector<float> center = gravityCenter(auxSol);
  do {
    std::vector<float> nearElement = nearElementOfCenter(auxSol, center); 
    auxSol = deleteElement(auxSol, nearElement);
    noInSolution_.push_back(nearElement);
    center = gravityCenter(auxSol);
  } while (auxSol.size() > solutionSize_);
  bestSolution_ = auxSol;
}