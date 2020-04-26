/**
 * @file graph.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase grafo
 * @version 0.1
 * @date 2020-04-26
 */

#include "../include/graph.hpp"

/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param filename Nombre del fichero a leer
 */
Graph::Graph(char* filename) {
  buildGraph(filename);
}

/**
 * @brief Destroy the Graph:: Graph object
 */
Graph::~Graph() {}

/**
 * @brief Lee el fichero y va creado la matriz de adyaciencia
 * 
 * @param filename 
 */
void Graph::buildGraph(char* filename) {
  std::ifstream file(filename);

  if (!file) {
    throw "Error: Can't open file";
  } 

  file >> numberOfVertex_;
  adjancencyMatrix_.resize(numberOfVertex_ * numberOfVertex_, 0);
  for (int i = 0; i < numberOfVertex_; i++) {
    setData(pos(i, i), -1.0);
  }

  float data;
  int i = 0;
  int j = 1;
  while (!file.eof() && i < numberOfVertex_) {
    file >> data;
    while (adjancencyMatrix_[pos(i, j)] != 0) {
      j++;
    }
    if (adjancencyMatrix_[pos(i, j)] == 0) {
      setData(pos(i, j), data);
      setData(pos(j, i), data);
      j++;
    }
    if (j == numberOfVertex_) {
      i++;
      j = 0;
    }
  }
}

/**
 * @brief Calcula la posición del vector a partir de i y j
 * 
 * @param i Fila
 * @param j Columna
 * @return int Posición en el vector
 */
int Graph::pos(int i, int j) {
  return  i * numberOfVertex_ + j;
}

/**
 * @brief Devuelve el valor de la matriz en esa posición
 * 
 * @param i Fila
 * @param j Columna
 * @return float Valor
 */
float Graph::getValue(int i, int j) {
  return adjancencyMatrix_[pos(i, j)];
}

/**
 * @brief Modifica el dato de la matriz dada una posición
 * 
 * @param pos Posición a modificar en el vector
 * @param data Valor a sustituir
 */
void Graph::setData(int pos, float data) {
  if ((size_t)pos >= adjancencyMatrix_.size()) {
    throw "Error: Matrix position doesn't exist";
  }
  adjancencyMatrix_[pos] = data;
}

/**
 * @brief Devuelve la matriz entera
 * 
 * @return std::vector<float> Matriz de adyaciencia
 */
std::vector<float> Graph::getMatrix(void) {
  return adjancencyMatrix_;
}

/**
 * @brief Devuelve el número de nodos
 * 
 * @return int Número de nodos
 */
int Graph::getNumberVertex(void) {
  return numberOfVertex_;
}

/**
 * @brief Escribe la matriz por pantalla
 */
void Graph::write(void) {
  std::cout << "Adjancency Matrix" << std::endl;
  for (int i = 0; i < numberOfVertex_; i++) {
    for (int j = 0; j < numberOfVertex_; j++) {
      std::cout << adjancencyMatrix_[pos(i, j)] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}