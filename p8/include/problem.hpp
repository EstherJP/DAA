/**
 * @file problem.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase abstracta que crea una interfaz común para los problemas
 * de maximización o minimización
 * @version 0.1
 * @date 2020-04-27
 */

#include <iostream>
#include <vector>
#include "graph.hpp"

class Problem {
  protected:
    std::vector<int> bestSolution_;
    float bestValue_;
    bool maxProblem_ = false;
    Graph affinities_;
    int numberIterWithoutImprove_ = 0;             // Número de iteraciones sin mejora
    int numberIterations = 0;
    int stopCriteria_;          // Criterio de parada (por defecto de inicializa a un número máximo de iteraciones)
    int searchCriteria_;         // Criterio de bísqueda local (por defecto de inicializa a la búsqueda ansiosa)
    int environmentCriteria_;       // Criterio de entorno (por defecto de inicializa a movimiento de apertura)

    virtual bool isInSolution(int node, std::vector<int> solution) = 0;
    virtual bool isMaxProblem(void) = 0;

    virtual void generateRandomSolution(void) = 0;
    virtual float initializeSolution(void) = 0;
    virtual void updateSolution(void) = 0;

    virtual std::vector<int> getBestSolution(void) = 0;
    virtual float getBestValue(void) = 0;

    virtual float objectiveFunction(std::vector<int> solution) = 0;
    virtual float objectiveFunctionAdd(int value, float currentValue, std::vector<int> solution) = 0;
    virtual float objectiveFunctionSub(int value, float currentValue, std::vector<int> solution) = 0;

    virtual void showSolution(void) = 0;

    virtual void searchSolution(void) = 0;

    virtual bool stopCriteria(void) = 0;

    virtual void localGreedySearch(void) = 0;
    virtual void localAnxiousSearch(void) = 0;
    virtual void postProcessing(void) = 0;
    virtual std::vector<int> generateNeightbourd(int value) = 0;
};