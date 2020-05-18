/**
 * @file grasp.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que contiene la implementación de manejo de datos del problema
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

/**
 * @brief Clase que contiene el código que maneja un conjunto de subconjuntos
 */
class Data {
  private:
    size_t dataSize_;                               // Tamaño del conjunto
    size_t dataElementsSize_;                       // Tamaño de los subconjuntos
    std::vector<std::vector<float>> setData_;       // Conjunto de subconjuntos

    void build(char* filename);                     // Lee el fichero y crea los datos

  public:
    Data();                                         // Constructor por defecto
    Data(char* filename);                           // Constructor
    ~Data();                                        // Destructor

    size_t getDataSize();                           // Devuelve el tamaño del conjunto
    size_t getElementsSize();                       // Devuelve el tamaño de los subconjuntos
    std::vector<std::vector<float>> getData(void);  // Devuelve el conjunto de subconjuntos
    void write(void);                               // Escribe los datos
};