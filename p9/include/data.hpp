#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Data {
  private:
    size_t dataSize_;
    size_t dataElementsSize_;
    std::vector<std::vector<float>> setData_;

    void build(char* filename);

  public:
    Data(char* filename);
    ~Data();

    std::vector<std::vector<float>> getData(void);
    void write(void);
};