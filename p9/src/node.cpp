/**
 * @file node.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene el código de un nodo del árbol
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/node.hpp"

/**
 * @brief Construct a new Expansive Node:: Expansive Node object
 */
ExpansiveNode::ExpansiveNode(void) {}

/**
 * @brief Construct a new Expansive Node:: Expansive Node object
 * 
 * @param node Nodo
 * @param vectorId Posición en el vector
 * @param depth Profundidad del nodo
 * @param noInSolution Conjunto de subconjuntos que no se encuentran en la solución
 * @param partialSol Solución parcial
 * @param dispersion Dispersión
 */
ExpansiveNode::ExpansiveNode(std::vector<float> node, int vectorId, int depth, std::vector<std::vector<float>> noInSolution, 
    std::vector<std::vector<float>> partialSol, float dispersion) : 
  node_(node),
  vectorId_(vectorId),
  depth_(depth),
  noInSolution_(noInSolution),
  partialSolution_(partialSol),
  dispersion_(dispersion)
{}

/**
 * @brief Destroy the Expansive Node:: Expansive Node object
 */
ExpansiveNode::~ExpansiveNode() {}

/**
 * @brief Devuelve el nodo
 * 
 * @return std::vector<float> Nodo
 */
std::vector<float> ExpansiveNode::getNode(void) {
  return node_;
}

/**
 * @brief Devuelve la dispersión
 * 
 * @return float Dispersión de la solución parcial
 */
float ExpansiveNode::getDispersion(void) {
  return dispersion_;
}

/**
 * @brief Devuelve la profundidad
 * 
 * @return int Profundidad
 */
int ExpansiveNode::getDepth(void) {
  return depth_;
}

/**
 * @brief Calcula la distancia entre dos subconjuntos
 * 
 * @param firstSet Primer subconjunto
 * @param secondSet Segundo subconjunto
 * @return float Distancia
 */
float ExpansiveNode::distanceTwoSets(std::vector<float> firstSet, std::vector<float> secondSet) {
  float sum = 0;
  for (int i = 0; i < firstSet.size(); i++) {
    float sub = firstSet[i] - secondSet[i];
    sub = pow(sub, 2);
    sum += sub;
  }
  return sqrt(sum);
}

/**
 * @brief Balancea la distancia al añadir un subconjunto a un conjunto
 * 
 * @param newSol Nueva solución con el nodo ya añdido
 * @param added Nodo añadido
 * @param currentDistance Distancia actual
 * @return float Nueva distancia
 */
float ExpansiveNode::addDistance(std::vector<std::vector<float>> newSol, std::vector<float> added, float currentDistance) {
  float newDistance = currentDistance;
  for (int i = 0; i < newSol.size(); i++) {
    if (newSol[i] != added)
      newDistance += distanceTwoSets(newSol[i], added);
  }
  return newDistance;
}

/**
 * @brief Devuelve la posición del nodo
 * 
 * @return int Posición del nodo
 */
int ExpansiveNode::getId() {
  return vectorId_;
}

/**
 * @brief Devuelve la solución parcial
 * 
 * @return std::vector<std::vector<float>> Solución parcial
 */
std::vector<std::vector<float>> ExpansiveNode::getPartialSolution() {
  return partialSolution_;
}

/**
 * @brief Devuelve la cota superior
 * 
 * @return float Cota superior
 */
float ExpansiveNode::getUpperBound() {
  return upperBound_;
}

/**
 * @brief Calcula la cota superior
 * 
 * @param solSize Tamaño de solución
 */
void ExpansiveNode::upperBound(int solSize) {
  int numberNodes = solSize - depth_;
  dispersion_ = addDistance(partialSolution_, node_, dispersion_);
  float maxDist = getBestDistance();
  int numberEdges = partialSolution_.size() * (solSize - partialSolution_.size());
  numberEdges += ((solSize - partialSolution_.size()) * (solSize - partialSolution_.size() - 1 )) / 2;
  upperBound_ = (maxDist * numberEdges) + dispersion_;
}

float ExpansiveNode::getBestDistance() {
  float auxDistanceOut = -1;
  for (int i = 0; i < noInSolution_.size(); i++) {
    for (int j = i + 1; j < noInSolution_.size(); j++) {
      float currentDistance = distanceTwoSets(noInSolution_[i], noInSolution_[j]);
      if (currentDistance > auxDistanceOut) {
        auxDistanceOut = currentDistance;
      }
    }
  }
  float auxDistanceBetween = -1;
  for (int i = 0; i < partialSolution_.size(); i++) {
    for (int j = 0; j < noInSolution_.size(); j++) {
      float currentDistance = distanceTwoSets(partialSolution_[i], noInSolution_[j]);
      if (currentDistance > auxDistanceBetween) {
        auxDistanceBetween = currentDistance;
      } 
    }
  }
  if (auxDistanceBetween > auxDistanceOut) {
    return auxDistanceBetween;
  } else{
    return auxDistanceOut;
  }
}

/**
 * @brief Devuelve el conjunto de subconjuntos que no se encuentran en la solución parcial
 * 
 * @return std::vector<std::vector<float>> Conjunto de subconjuntos que no se encuentran en la solución parcial
 */
std::vector<std::vector<float>> ExpansiveNode::getNoInSolution() {
  return noInSolution_;
}

/**
 * @brief Muestra la información del nodo
 */
void ExpansiveNode::writeNode(void) {
  std::cout << "\nNodo: ";
  for (int i = 0; i < node_.size(); i++) {
    std::cout << node_[i] << " ";
  }
  std::cout << "\n";
  std::cout << "Id Node: " << vectorId_ << "\n";
  std::cout << "Profundidad: " << depth_ << "\n";
  std::cout << "UpperBound: " << upperBound_ << "\n";
  std::cout << "Dispersion: " << dispersion_ << "\n";
  std::cout << "Rama: \n";
    for (int i = 0; i < partialSolution_.size(); i++) {
    std::cout << "S" << i + 1 << ":  ";
    for (int j = 0; j < partialSolution_[i].size(); j++) {
      std::cout << partialSolution_[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
