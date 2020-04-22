#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class Graph {
  private:
    int numberOfVertex_;
    std::vector<float> adjancencyMatrix_;

    void buildGraph(char* filename);

  public:
    Graph(char* filename);
    ~Graph();

    int pos(int i, int j);
    void setData(int pos, float data);

    void write(void);
};