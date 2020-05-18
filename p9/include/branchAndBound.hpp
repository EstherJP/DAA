/**
 * @file branchAndBound.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene el código de ramificación y poda que resulve el
 * problema de máxima diversidad
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>

#include "maxDiversityProblem.hpp"
#include "node.hpp"
#include "tree.hpp"

/**
 * @brief Clase que contiene la implementación de ramificación y poda
 */
class BranchBound {
  private:
    MaxDivProblem* LBSolution_;                           // Objeto problema que nos da la cota inferior
    float LB_;                                            // Cota inferior
    Tree* tree_;                                          // Árbol de nodos  
  
  public:
    BranchBound();                                        // Constructor por defecto
    BranchBound(MaxDivProblem* LBSolution, int str);      // Constructor de la clase ramificación
    void showSolution();                                  // Método que muestra la solución óptima    

    void branchBound(void);                               // Método de ramificación y poda
};