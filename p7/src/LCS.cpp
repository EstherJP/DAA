#include "../include/LCS.hpp"

using namespace std;

LCS::LCS() {}

LCS::LCS(size_t firstSize, size_t secondSize) {
  firstSequence_.resize(firstSize);
  secondSequence_.resize(secondSize);

  build();
}

LCS::~LCS() {}

void LCS::build(void) {
  // Creamos la primera subsecuencia
  for (size_t i = 0; i < firstSequence_.length(); i++) {
    firstSequence_[i] = 'A' + rand() % 26;
  }

  // Creamos la primera subsecuencia
  for (size_t i = 0; i < secondSequence_.length(); i++) {
    secondSequence_[i] = 'A' + rand() % 26;
  }
}

void LCS::write(void) {
  cout << "SECUENCIA A: ";
  for (size_t i = 0; i < firstSequence_.length(); i++) {
    cout << firstSequence_[i] << " ";
  }
  cout << endl;

  cout << "SECUENCIA B: ";
  for (size_t i = 0; i < secondSequence_.length(); i++) {
    cout << secondSequence_[i] << " ";
  }
  cout << endl;
}