/**
 * @file grasp.cpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de manejo de datos del problema
 * @version 0.1
 * @date 2020-05-18
 */

#include "../include/data.hpp"

/**
 * @brief Construct a new Data:: Data object
 */
Data::Data() {}

/**
 * @brief Construct a new Data:: Data object
 * 
 * @param filename Nombre del fichero que contiene los datos
 */
Data::Data(char* filename) {
  build(filename);
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data() {}

/**
 * @brief Lee el fichero e inicializa los datos
 * 
 * @param filename Nombre del fichero
 */
void Data::build(char* filename) {
  std::ifstream file(filename);

  if (!file) {
    throw "Error: Can't open file";
  } 
  file >> dataSize_;
  file >> dataElementsSize_;

  std::vector<float> auxElements;
  int iterSize = 0;
  float tempData;
  while (!file.eof() && iterSize < dataSize_) {
    for (int j = 0; j < dataElementsSize_; j++) {
      file >> tempData;
      auxElements.push_back(tempData);
      if (auxElements.size() == dataElementsSize_) {
        setData_.push_back(auxElements);
        auxElements.clear();
      }
    }
    iterSize++;
  }
}

/**
 * @brief Devuelve el conjunto de subconjuntos
 * 
 * @return std::vector<std::vector<float>> Conjuntos de subconjuntos
 */
std::vector<std::vector<float>> Data::getData(void) {
  return setData_;
}

/**
 * @brief Muestra los datos del problema
 */
void Data::write(void) {
  std::cout << "\nTamaño del conjunto: " << dataSize_ << "\n";
  std::cout << "Tamaño de los elementos: " << dataElementsSize_ << "\n"; 
  std::cout << "--- CONJUNTO DE DATOS ---\n";
  for (int i = 0; i < dataSize_; i++) {
    std::cout << "Conjunto " << i + 1 << ":  ";
    for (int j = 0; j < dataElementsSize_; j++) {
      std::cout << setData_[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

/**
 * @brief Devuelve el tamaño del conjunto
 * 
 * @return size_t Tamaño del conjunto
 */
size_t Data::getDataSize() {
  return dataSize_;
}

/**
 * @brief Devuelve el tamaño de los subconjuntos
 * 
 * @return size_t Tamaño de los subconjuntos
 */
size_t Data::getElementsSize() {
  return dataElementsSize_;
}
