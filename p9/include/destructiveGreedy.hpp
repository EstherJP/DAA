/**
 * @file destructiveGreedy.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de un algoritmo voraz destructivo
 * que resuelve el problema de máxima diverdidad
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>
#include "maxDiversityProblem.hpp"

/**
 * @brief Clase que contiene la implementación de un algoritmo voraz destructivo que
 * resuelve el problema de máxima dispersión 
 */
class desGreedy : public MaxDivProblem {
  public:
    desGreedy();                                          // Constructor por defecto
    desGreedy(Data setData, int solSize, int maxIter);    // Constructor
    ~desGreedy();                                         // Destructor

    std::vector<float> nearElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center); // Calcula el elemento más cercano al centro
    void searchSolution(void);  // Algoritmo voraz destructivo
};