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
    Data();
    Data(char* filename);
    ~Data();

    size_t getDataSize();
    size_t getElementsSize();
    std::vector<std::vector<float>> getData(void);
    void write(void);
};