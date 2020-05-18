/**
 * @file maxDiversityProblem.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase base que contiene la solución la problema de maximun dispersity
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/maxDiversityProblem.hpp"

/**
 * @brief Construct a new Max Div Problem:: Max Div Problem object
 */
MaxDivProblem::MaxDivProblem() {}

/**
 * @brief Construct a new Max Div Problem:: Max Div Problem object
 * 
 * @param setData Datos del problema
 * @param solSize Tamaño de la solución
 * @param maxIter Número máximo de iteraciones
 */
MaxDivProblem::MaxDivProblem(Data setData, int solSize, int maxIter) :
  setData_(setData),
  solutionSize_(solSize),
  maxIter_(maxIter_)
{
  srand(time(NULL));
}

/**
 * @brief Destroy the Max Div Problem:: Max Div Problem object
 */
MaxDivProblem::~MaxDivProblem() {}

/**
 * @brief Devuelve la mejor solución
 * 
 * @return std::vector<std::vector<float>> Mejor solución
 */
std::vector<std::vector<float>> MaxDivProblem::getBestSolution(void) {
  return bestSolution_;
}

/**
 * @brief Calcula la distancia entre dos subconjuntos
 * 
 * @param firstSet Primer subconjunto
 * @param secondSet Segundo subconjunto
 * @return float Distancia entre los dos subconjuntos
 */
float MaxDivProblem::distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet) {
  float sum = 0;
  for (int i = 0; i < setData_.getElementsSize(); i++) {
    float sub = firstSet[i] - secondSet[i];
    sub = pow(sub, 2);
    sum += sub;
  }
  return sqrt(sum);
}

/**
 * @brief Devuelve el tamaño de la solución
 * 
 * @return int Tamaño de la solución
 */
int MaxDivProblem::getSolutionSize(void) {
  return solutionSize_;
}

/**
 * @brief Devuelve el conjunto total
 * 
 * @return std::vector<std::vector<float>> Conjunto que contiene todos los subconjuntos
 */
std::vector<std::vector<float>> MaxDivProblem::getAllNodes(void) {
  return setData_.getData();
}

/**
 * @brief Calcula el subconjunto más alejado del centro
 * 
 * @param elements Conjunto de elementos
 * @param center Centro
 * @return std::vector<float> Subconjunto más alejado 
 */
std::vector<float> MaxDivProblem::farElementOfCenter(std::vector<std::vector<float>> elements, std::vector<float> center) {
  float oldDistance = distanceTwoSets(elements[0], center);
  int farIndex = 0;
  for (int i = 1; i < elements.size(); i++) {
    float newDistance = distanceTwoSets(elements[i], center);
    if (oldDistance < newDistance) {
      oldDistance = newDistance;
      farIndex = i;
    }
  } 
  return elements[farIndex];
}

/**
 * @brief Calcula la distancia total de un conjunto de elementos
 * 
 * @param auxSol Conjunto 
 * @return float Distancia total
 */
float MaxDivProblem::totalDistance(std::vector<std::vector<float>> auxSol) {
  float auxDistance = 0;
  for (int i = 0; i < auxSol.size() - 1; i++) {
    for (int j = i + 1; j < auxSol.size(); j++) {
      auxDistance += distanceTwoSets(auxSol[j], auxSol[i]);
    }
  }
  return auxDistance;
}

/**
 * @brief Elimina un subconjunto de un conjunto
 * 
 * @param elements Conjunto
 * @param deleted Subconjunto a eliminar
 * @return std::vector<std::vector<float>> Nuevo conjunto
 */
std::vector<std::vector<float>> MaxDivProblem::deleteElement(std::vector<std::vector<float>> elements, std::vector<float> deleted) {
  for (auto iter = elements.begin(); iter < elements.end(); iter++) {
    if (*iter == deleted) {
      elements.erase(iter);
    }
  }
  return elements;
}

/**
 * @brief Compueba si un subconjunto se encuentra en un conjunto
 * 
 * @param auxSol Conjunto
 * @param element Subconjunto
 * @return true Si se encuentra contenido
 * @return false Si no se encuentra contenido
 */
bool MaxDivProblem::isInSolution(std::vector<std::vector<float>> auxSol, std::vector<float> element) {
  for (int i = 0; i < auxSol.size(); i++) {
    if (auxSol[i] == element) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Balancea la distancia cuando se produce un movimiento de intercambio en el conjunto
 * 
 * @param newSol Conjunto con el nodo ya intercambiado
 * @param added Subconjunto añadido
 * @param swapped Conjunto que se sustituyó
 * @param currentDistance Distancia actual
 * @return float Nueva distancia
 */
float MaxDivProblem::swapDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, std::vector<float> swapped, float currentDistance) {
  for (int i = 0; i < newSol.size(); i++) {
    if (newSol[i] != added) {
      currentDistance += distanceTwoSets(newSol[i], added);
      currentDistance -= distanceTwoSets(newSol[i], swapped);
    } 
  }
  return currentDistance;
}

/**
 * @brief Balancea la distancia cuando se añade un nuevo subconjunto
 * 
 * @param newSol Solución con el subconjunto añadido
 * @param added Subconjunto añadido
 * @param currentDistance Distancia actual
 * @return float Nueva distancia
 */
float MaxDivProblem::addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance) {
  currentDistance *= newSol.size() - 1;
  for (int i = 0; i < newSol.size(); i++) {
    if (newSol[i] != added) {
      currentDistance += distanceTwoSets(newSol[i], added);
    } 
  }
  return currentDistance / newSol.size();
}

/**
 * @brief Genera una solución vecina mediente un movimiento de intercambio
 * 
 * @param currentSol Solución actual
 * @param element Elemento a intercambiar
 * @param swapNumber Posición del subconjunto que va a ser sustituido
 * @return std::vector<std::vector<float>> Nueva solución vecina
 */
std::vector<std::vector<float>> MaxDivProblem::generateNeightbour(std::vector<std::vector<float>> currentSol, std::vector<float> element, int swapNumber) {
  currentSol[swapNumber] = element;
  return currentSol;
}

/**
 * @brief Genera una solución aleatoria
 */
void MaxDivProblem::generateRandomSolution(void) {
  while (bestSolution_.size() != solutionSize_) {
    int random = rand() % solutionSize_;
    if (!isInSolution(bestSolution_, setData_.getData()[random])) {
      bestSolution_.push_back(setData_.getData()[random]);
    }
  }
  bestDistance_ = totalDistance(bestSolution_);
}

/**
 * @brief Devuelve la mejor distancia
 * 
 * @return float Mejor distancia
 */
float MaxDivProblem::getBestDistance(void) {
  return bestDistance_;
}

/**
 * @brief Realiza una búsqueda local greedy realizando un movimiento de intercambio
 * 
 * @param currentSol Solución actual
 * @param currentDistance Distancia actual
 */
void MaxDivProblem::localGreedySearch(std::vector<std::vector<float>> currentSol, float currentDistance) {
  std::vector<std::vector<float>> neightbour;
  float neightbourDistance;
  std::vector<std::vector<float>> auxSol = currentSol;
  float auxDistance = currentDistance;
  bool keepSearching;
  std::vector<float> added;
  std::vector<float> deleted;
  do {
    keepSearching = false;
    for (int i = 0; i < currentSol.size(); i++) {
      for (int j = 0; j < noInSolution_.size(); j++) {
        neightbour = generateNeightbour(currentSol, noInSolution_[j], i);
        neightbourDistance = swapDistance(neightbour, noInSolution_[j], currentSol[i], currentDistance);
        if (auxDistance < neightbourDistance) {
          auxSol = neightbour;
          auxDistance = neightbourDistance;
          deleted = noInSolution_[j];
          added = currentSol[i];
          keepSearching = true;
        }
      }
    }
    noInSolution_ = deleteElement(noInSolution_, deleted);
    noInSolution_.push_back(added);
    currentSol = auxSol;
    currentDistance = auxDistance;
  } while (keepSearching);
  bestSolution_ = auxSol;
  bestDistance_ = auxDistance;
}

/**
 * @brief Calcula el centro de gravedad de un conjunto de subconjuntos
 * 
 * @param auxSol Conjunto a calcular el centro
 * @return std::vector<float> Centro de gravedad
 * 
 */
std::vector<float> MaxDivProblem::gravityCenter(std::vector<std::vector<float>> auxSol) {
  std::vector<float> center;
  for (int i = 0; i < setData_.getElementsSize(); i++) {
    float sum = 0;
    for (int j = 0; j < auxSol.size(); j++) {
      sum += auxSol[j][i];
    }
    center.push_back(sum / auxSol.size());
    sum = 0;
  } 
  return center;
}

/**
 * @brief Realiza la búsqueda local solicitada
 */
void MaxDivProblem::postProcessing(void) {
  localGreedySearch(bestSolution_, bestDistance_);
  showSolution(bestSolution_);
}

/**
 * @brief Muestra la solución
 * 
 * @param sol Solución
 */
void MaxDivProblem::showSolution(std::vector<std::vector<float>> sol) {
  bestDistance_ = totalDistance(sol);
  std::cout << "Distancia máxima: " << bestDistance_<< std::endl;
  for (int i = 0; i < sol.size(); i++) {
    std::cout << "Conjunto " << i + 1 << ":  ";
    for (int j = 0; j < sol[i].size(); j++) {
      std::cout << sol[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
