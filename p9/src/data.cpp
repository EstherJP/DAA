#include "../include/data.hpp"

Data::Data(char* filename) {
  build(filename);
}

Data::~Data() {}

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

std::vector<std::vector<float>> Data::getData(void) {
  return setData_;
}

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
