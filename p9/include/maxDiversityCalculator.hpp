#pragma once

#include <iostream>
#include "../include/maxDiversityProblem.hpp"

class maxDivCalculator {
  private:
    MaxDivProblem* calculateMaxDiv_;

  public:
    //Constructor por defecto
    maxDivCalculator(): calculateMaxDiv_(NULL) {}

    //Contructor con puntero a la estrategia querida
    maxDivCalculator(MaxDivProblem* calculateMaxDiv): 
      calculateMaxDiv_(calculateMaxDiv) 
    {}

    void setStrategy(MaxDivProblem* calculateMaxDiv) {
      calculateMaxDiv_ = calculateMaxDiv;
    }

    // Llamada a la estrategia según el contexto
    void maxMeanInterface(void) {
      if(calculateMaxDiv_) {
        calculateMaxDiv_->searchSolution();
        // calculateMaxDiv_->showSolution();
      }
      else {
        throw "Error: Strategy not set";
      }
    }

    void greedySearch(void) {
      if(calculateMaxDiv_) {
        calculateMaxDiv_->postProcessing();
        // calculateMaxDiv_->showSolution();
      }
      else {
        throw "Error: Strategy not set";
      }
    }

    void greedySearchRandom(void) {
      if(calculateMaxDiv_) {
        calculateMaxDiv_ -> generateRandomSolution();
        calculateMaxDiv_->postProcessing();
        // calculateMaxDiv_->showSolution();
      }
      else {
        throw "Error: Strategy not set";
      }
    }
};