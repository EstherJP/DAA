/**
 * @file maxDiversityProblem.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase base que contiene la solución la problema de maximun dispersity
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>
#include <math.h>
#include "data.hpp"

/**
 * @brief Clase base que contiene la implementación del código para resolver el problema
 * de maximun diversity
 */
class MaxDivProblem {
  protected:
    Data setData_;                                      // Clase Data que contiene la información de los datos del problema
    std::vector<std::vector<float>> bestSolution_;      // Mejor Solución encontrada
    std::vector<std::vector<float>> noInSolution_;      // Conjuntos que no se encuentran en la solución actual
    float bestDistance_;                                // Mejor distancia encontrada

    int solutionSize_;                                  // Tamaño de solución 
    int maxIter_;                                       // Número máximo de iteraciones

  public:
    MaxDivProblem();                                          // Contructor por defecto
    MaxDivProblem(Data setData, int solSize, int maxIter);    // Constructor de la clase
    ~MaxDivProblem();                                         // Destructor por defecto

    std::vector<std::vector<float>> getBestSolution(void);    // Devuelve la mejor solución
    float getBestDistance(void);                              // Devuelve la mejor distancia
    int getSolutionSize(void);                                // Devuelve el tamaño de la solución
    std::vector<std::vector<float>> getAllNodes(void);        // Devuelve el conjunto de todos los subconjuntos  

    std::vector<float> gravityCenter(std::vector<std::vector<float>> auxSol); // Calcula el centro de gravedad de un conjunto de subconjuntos

    float distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet); // Calcula la distancia entre dos conjuntos
    float totalDistance(std::vector<std::vector<float>> auxSol);                      // Calcula la distancia total entre un conjunto de subconjuntos
    float swapDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, std::vector<float> swapped, float currentDistance); // Balancea la función objetivo cuando ocurre un intercambio de nodos
    float addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance); // Balancea la función objetivo cuando se añade un subconjunto a la solución

    std::vector<std::vector<float>> deleteElement(std::vector<std::vector<float>> elements, std::vector<float> deleted); // Elimina un sunconjunto de un conjunto de subconjuntos
    std::vector<float> farElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center);          // Calcula el subconjunto más alejado del centro de gravedad

    std::vector<std::vector<float>> generateNeightbour(std::vector<std::vector<float>> elements, std::vector<float> element, int swapNumber); // Genera una vecina de una solución
    void localGreedySearch(std::vector<std::vector<float>> elements, float currentDistance);                              // Búsqueda local ansiosa
    void postProcessing(void);                                                                                            // Método que llama a la búsqueda local correspondiente

    void generateRandomSolution(void);                                                                                    // Genera una solución aleatoria
    bool isInSolution(std::vector<std::vector<float>> auxSol, std::vector<float> element);                                // Comprueba si un subconjunto se encuentra en un conjunto
    virtual void searchSolution(void) = 0;                                                                                // Método abstracto que realiza la búsqueda de la solución
    void showSolution(std::vector<std::vector<float>> sol);                                                               // Muestra la solución
};