/**
 * @file tree.hpp
 * @author Esther Jorge Paramio (alu0101102498@ull.edu.es)
 * @brief Clase que representa el árbol ramificación y poda
 * @version 0.1
 * @date 2020-05-18
 */

#pragma once

#include <iostream>
#include "node.hpp"
#include "maxDiversityProblem.hpp"

/**
 * @brief Clase que representa un árbol de ramificación y poda
 */
class Tree {
  private:
    int totalNodes_;                                // Total nodos
    int currentDepth_;                              // Profundidad actual del árbol
    int solutionSize_;                              // Tamaño de la solución

    float lowerBound_;                              // Cota inferior

    std::vector<ExpansiveNode*> nodesToExpand_;     // Nodos a expandir
    std::vector<ExpansiveNode*> generateNodes_;     // Nodos generados
    std::vector<std::vector<float>> allNodes_;      // Total de nodos

    std::vector<std::vector<float>> solution_;      // Solución óptima

    int expandStrategy_;                            // Estrategia de expansión de nodos

  public:
    Tree();                                         // Contructor por defecto
    Tree(MaxDivProblem*, int);                      // Constructor
    ~Tree();                                        // Destructor

    std::vector<std::vector<float>> deleteNode(std::vector<std::vector<float>> nodes, std::vector<float> node); // Elimina un nodo de nu conjunto de nodos

    std::vector<ExpansiveNode*> getNodesToExpand();  // Devuelve los nodos a expandir
    std::vector<ExpansiveNode*> getGenerateNodes();  // Devuelve los nodos generados
    float getLowerBound();                           // Devuelve la cota inferior
    std::vector<std::vector<float>> getSolution();   // Devuelve la solución

    void bound(ExpansiveNode* node);                 // Poda un nodo del árbol

    void expandNode(ExpansiveNode* node);            // Expande un nodo
    void writeTree(void);                            // Escribe el árbol
    void initializeTree(void);                       // Inicializa el árbol expandiéndolo por primer vez

    ExpansiveNode* nodeToExpand();                   // Elige el nodo a expandir según la estrategia
    ExpansiveNode* expandNodeByLowerUpperBound();    // Elige el nodo a expandir por la cota superior más bajas
    ExpansiveNode* expandNodeByDepth();              // Elige el nodo a expandir por profundidad
    ExpansiveNode* expandBySecondBestNode();
};