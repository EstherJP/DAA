#pragma once

#include <iostream>
#include "../include/maxMeanStrategyBase.hpp"

class maxMeanCalculator {
  private:
    MaxMean* calculateMaxMean_;

  public:
    //Constructor por defecto
    maxMeanCalculator(): calculateMaxMean_(NULL) {}

    //Contructor con puntero a la estrategia querida
    maxMeanCalculator(MaxMean* calculateMaxMean): 
      calculateMaxMean_(calculateMaxMean) 
    {}

    void setStrategy(MaxMean* calculateMaxMean) {
      calculateMaxMean_ = calculateMaxMean;
    }

    // Llamada a la estrategia según el contexto
    void maxMeanInterface(void) {
      if(calculateMaxMean_) {
        calculateMaxMean_->searchSolution();
        calculateMaxMean_->showSolution();
      }
      else {
        throw "Error: Strategy not set";
      }
    }
};