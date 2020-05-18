/**
 * @file constructiveGreedy.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de un algoritmo voraz constructivo
 * que resuelve el problema de máxima diverdidad
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"

/**
 * @brief Clase que contiene la implementación de un algoritmo voraz constructivo
 */
class consGreedy : public MaxDivProblem {
  public:
    consGreedy();                                         // Contructor por defecto
    consGreedy(Data setData, int solSize, int maxIter);   // Constructor
    ~consGreedy();                                        // Destructor por defecto

    void searchSolution(void);                            // Algoritmo voraz constructivo
};