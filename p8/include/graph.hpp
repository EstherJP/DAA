/**
 * @file graph.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase grafo
 * @version 0.1
 * @date 2020-04-26
 */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief clase grafo
 */
class Graph {
  private:
    int numberOfVertex_;                      // Número de nodos o vértices del grafo
    std::vector<float> adjancencyMatrix_;     // Matriz de adyaciencia

    void buildGraph(char* filename);          // Lee el fichero y construye el grafo a partir de él
    void setData(int pos, float data);        // Modifica los datos de la matriz

  public:
    Graph(char* filename);                    // Constructor
    ~Graph();                                 // Destructor

    std::vector<float> getMatrix(void);       // Devuelve la matriz entera de adayciencia
    int getNumberVertex(void);                // Devuelve el número de nodos
    int pos(int i, int j);                    // Posición del vector a partir de dos puntos
    float getValue(int i, int j);             // Devuelve el valor de la matroz en la posición (i, j)
    void write(void);                         // Escribe la matriz de adyaciencia
};