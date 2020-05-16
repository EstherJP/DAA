/**
 * @file maxMeanStrategyBase.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase base que contiene la solución base al problema max-mean
 * @version 0.1
 * @date 2020-04-26
 */

#include "../include/maxMeanProblem.hpp"

/**
 * @brief Construct a new Max Mean:: Max Mean object
 */
MaxMean::MaxMean(void) {} 

/**
 * @brief Construct a new Max Mean:: Max Mean object
 * 
 * @param affinities Objeto con la matriz de afinidades
 */
MaxMean::MaxMean(Graph affinities): 
  affinities_(affinities)
{}

/**
 * @brief Destroy the Max Mean:: Max Mean object
 * 
 */
MaxMean::~MaxMean() {}

/**
 * @brief Inicializa la solución actual con todos los todos
 */
void MaxMean::initializeAll(void) {
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    bestSolution_.push_back(i);
  }
}

/**
 * @brief Inicializa la mejor solución con los dos nodos cuya función objetivo es máxima
 * 
 * @return float Media de los nodos calculados
 */
float MaxMean::initializeBestSolution(void) {
  bestSolution_.clear();
  float max = FLT_MIN;
  int iMax;
  int jMax;
  for (int i = 0; i < affinities_.getNumberVertex(); i++) {
    for (int j = i; j < affinities_.getNumberVertex(); j++) {
      if (affinities_.getValue(i, j) > max) {
        max = affinities_.getValue(i, j);
        iMax = i;
        jMax = j;
      } else if (affinities_.getValue(i, j) == max) {
        int random = rand() % 2;
        if (random == 1) {
          max = affinities_.getValue(i, j);
          iMax = i;
          jMax = j;
        }
      }
    }
  }
  bestSolution_.push_back(iMax);
  bestSolution_.push_back(jMax);
  return max / 2.0;
}

/**
 * @brief Actualiza la solución si lo mandado por parámetro es mejor
 * 
 * @param currentSolution Nodos a comprobar si es mejor
 * @param currentMean Media a comprobar si es mejor
 */
void MaxMean::updateSolution(std::vector<int> currentSolution, float currentMean) {
  if (bestMean_ < currentMean) {
    bestMean_ = currentMean;
    numberIterWithoutImprove_ = 0;
  } else {
    bestSolution_ = currentSolution;
    numberIterWithoutImprove_++;
  }
}

/**
 * @brief Devuelve la mejor solución  
 * 
 * @return std::vector<int> Nodos con la mejor solución encontrada
 */
std::vector<int> MaxMean::getBestSolution(void) {
  return bestSolution_;
}

/**
 * @brief Devuelve la mejor media
 * 
 * @return float 
 */
float MaxMean::getBestMean(void) {
  return bestMean_;
}

/**
 * @brief Comprueba si un nodo se encuentra en la solución actual
 * 
 * @param node Nodo a buscar
 * @return true Si se encuentra
 * @return false Si no se encuentra
 */
bool MaxMean::isInSolution(int node, std::vector<int> solution) {
  for (size_t i = 0; i < solution.size(); i++) {
    if (solution[i] == node) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Genera una solución aleatoria
 */
void MaxMean::generateRandomSolution(void) {
  bestSolution_.clear();
  int randomSize = 2 + rand() % (affinities_.getNumberVertex() - 2);
  for (int i = 0; i < randomSize; i++) {
    int randomNode = rand() %  affinities_.getNumberVertex();
    if (!isInSolution(randomNode, bestSolution_)) {
      bestSolution_.push_back(randomNode);
    }
  }
  bestMean_ = meanDispersion(bestSolution_);
}


/**
 * @brief Calcula la media a partir de un conjunto de nodos
 * 
 * @param nodes Nodos 
 * @return float Media calculada de esos nodos
 */
float MaxMean::meanDispersion(std::vector<int> nodes) {
  float sum = 0;
  int iterNodeI = 0;
  for (size_t i = iterNodeI; i < nodes.size(); i++) {
    for (size_t j = i + 1; j < nodes.size(); j++) {
      sum += affinities_.getValue(nodes[i], nodes[j]);
    }
  }
  return (sum / nodes.size());
}

/**
 * @brief Recalcula la función objetivo en función de la mejor media actual en caso de añadir un nuevo nodo
 * 
 * @param node Nodo a añadir a la solución  
 * @param currentMean Media actual
 * @param nodes Solución con el nodo ya añadido
 * @return float Nueva media
 */
float MaxMean::meanDispersionAdd(int node, float currentMean, std::vector<int> nodes) {
  float costNode = 0;
  for (int i = 0; i < nodes.size(); i++) {
    costNode += affinities_.getValue(nodes[i], node);
  }
  costNode++;
  return ((currentMean * (nodes.size() - 1) + costNode) / nodes.size());
}

/**
 * @brief Recalcula la función objetivo en función de la mejor media actual en caso de eliminar un nodo
 * 
 * @param node Nodo a quitar de la solución  
 * @param currentMean Media actual
 * @param nodes Solución con el nodo ya eliminado
 * @return float Nueva media
 */
float MaxMean::meanDispersionSub(int node, float currentMean, std::vector<int> nodes) {
  float costNode = 0;
  for (int i = 0; i < nodes.size(); i++) {
    costNode += affinities_.getValue(nodes[i], node);
  }
  return ((currentMean * (nodes.size() + 1) - costNode) / (nodes.size()));
}

/**
 * @brief Muestra la solución hasta el momento
 */
void MaxMean::showSolution(void) {
  std::cout << "\nMejor media: " << bestMean_ << std::endl;
  std::cout << "Conjunto de nodos: " << std::endl;
  for (size_t i = 0; i < bestSolution_.size(); i++) {
    std::cout << bestSolution_[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

/**
 * @brief Elige el criterio de parada según el atributo stopCriteria_
 * 
 * @param nIterations Número de iteraciones totales que ha realizado la búsqueda
 * @return true Si ha realizado más que el máximo de iteraciones
 * @return false Si no ha superado el máximo de iteraciones
 */
bool MaxMean::stopCriteria(void) {
  switch (stopCriteria_)  {
  case 1:
    return numberIterations_ < MAXITERATIONS;
    break;
  
  case 2:
    return numberIterWithoutImprove_ < MAXITERATIONS;
    break;
  
  default:
    throw "Error: You need to set the stop criteria";
    break;
  }
}

/**
 * @brief Búsqueda local greedy
 */
void MaxMean::localGreedySearch(void) {
  float currentMean = bestMean_;
  std::vector<int> currentSolution_;

  float neightbourdMean;
  std::vector<int> neightbourdSolution;
  bool keepSearchingBest;
  
  do {
    keepSearchingBest = false;
    for (int node = 0; node < affinities_.getNumberVertex(); node++) {
      neightbourdSolution = generateNeightbourd(node);
      neightbourdMean = meanDispersion(neightbourdSolution);

      if (neightbourdMean > bestMean_) {
        currentSolution_ = neightbourdSolution;
        currentMean = neightbourdMean;
        keepSearchingBest = true;
      } 
    }
    bestSolution_ = currentSolution_;
    bestMean_ = currentMean;
  } while (keepSearchingBest);
}


/**
 * @brief Búsqueda local ansiosa
 */
void MaxMean::localAnxiousSearch(void) {
  float currentMean = bestMean_;
  for (int node = 0; node < affinities_.getNumberVertex(); node++) {
    std::vector<int> neightbourdSolution = generateNeightbourd(node);
    float neightbourdMean = meanDispersion(neightbourdSolution);
  
    if (neightbourdMean > bestMean_) {
      bestSolution_ = neightbourdSolution;
      bestMean_ = neightbourdMean;
      break;
    } 
  }
}

/**
 * @brief Elige la búsuqeda local según el atributo searchCriteria_
 */
void MaxMean::postProcessing(void) {
  switch (searchCriteria_) {
  case 1:
    localAnxiousSearch();
    break;
  
  case 2:
    localGreedySearch();
    break;
  
  default:
    throw "Error: You need to set a local search";
    break;
  }
}

/**
 * @brief Genera una solución vecina dependiento del movimiento seleccionado
 * 
 * @param node Nodo a realizar el movimiento
 * @return std::vector<int> Solución vecina
 */
std::vector<int> MaxMean::generateNeightbourd(int node) {
  std::vector<int> neightbourd = bestSolution_;
  
  switch (environmentCriteria_) {
  case 1: // Apertura
    if (!isInSolution(node, bestSolution_)) {
      neightbourd.push_back(node);
      return neightbourd;
    }
    break;
  
  case 2: // Cierre
    if (isInSolution(node, bestSolution_)) {
      for (auto iter = neightbourd.begin(); iter != neightbourd.end(); iter++) {
        if (*iter == node) {
          neightbourd.erase(iter);
          break;
        }
      }
    }

  default:
    throw "Error: You need to set an environment criteria";
    break;
  }
}
