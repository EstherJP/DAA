#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class Graph {
  private:
    int numberOfVertex_;
    std::vector<float> adjancencyMatrix_;

    void buildGraph(char* filename);
    void setData(int pos, float data);

  public:
    Graph(char* filename);
    ~Graph();

    std::vector<float> getMatrix(void);
    int getNumberVertex(void);
    int pos(int i, int j);
    float getValue(int i, int j);
    void write(void);
};