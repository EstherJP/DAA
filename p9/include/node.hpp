/**
 * @file node.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene el código de un nodo del árbol
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>
#include <vector>
#include <math.h>

/**
 * @brief Clase que represente el nodo del árbol del problema
 */
class ExpansiveNode {
  private:
    std::vector<float> node_;                         // Nodo
    int vectorId_;                                    // Posición del vector del nodo

    std::vector<std::vector<float>> noInSolution_;    // Nodos que no se encuentran en la solución hasta ahora
    std::vector<std::vector<float>> partialSolution_; // Solución parcial

    float upperBound_ = 0;                            // Cota superior
    float dispersion_ = 0;                            // Distancia de la solución parcial
    int depth_;                                       // Profundidad del nodo

  public:
    ExpansiveNode();                                  // Constructor por defecto
    ExpansiveNode(std::vector<float> node, int vectorId, int depth, std::vector<std::vector<float>> noInSolution, 
        std::vector<std::vector<float>> partialSol, float dispersion); // Constructor
    ~ExpansiveNode();                                 // Destructor

    int getId();                                      // Devuelve la posición del nodo del vector
    std::vector<std::vector<float>> getNoInSolution(); // Devuelve los nodos que no se encuentran en la solución
    std::vector<std::vector<float>> getPartialSolution(); // Devuelve la solución parcial
    float getUpperBound();                             // Devuelve la cota superior
    float getBestDistance();                           // Devuelve la mejor distancia
    std::vector<float> getNode(void);                  // Devuelve el nodo
    float getDispersion(void);                         // Devuelve la dispersión del nodo
    int getDepth(void);                                // Devuelve la profundidad del nodo

    float distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet); // Devuelve la distancia entre dos subconuntos
    float addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance); // Balancea la distancia al añadir un nodo
    void upperBound(int solSize);                       // Calcula la cota superior

    void writeNode(void);                               // Escribe el nodo
};