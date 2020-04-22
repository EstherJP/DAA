#include "../include/graph.hpp"

Graph::Graph(char* filename) {
  buildGraph(filename);
}

Graph::~Graph() {}

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

int Graph::pos(int i, int j) {
  return  i * numberOfVertex_ + j;
}

float Graph::getValue(int i, int j) {
  return adjancencyMatrix_[pos(i, j)];
}

void Graph::setData(int pos, float data) {
  if ((size_t)pos >= adjancencyMatrix_.size()) {
    throw "Error: Matrix position doesn't exist";
  }

  adjancencyMatrix_[pos] = data;
}

std::vector<float> Graph::getMatrix(void) {
  return adjancencyMatrix_;
}

int Graph::getNumberVertex(void) {
  return numberOfVertex_;
}

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