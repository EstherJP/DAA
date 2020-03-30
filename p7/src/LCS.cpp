#include "../include/LCS.hpp"

using namespace std;

LCS::LCS() {}

LCS::LCS(string first, string second) {
  firstSequence_ = first;
  secondSequence_ = second;
}

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

void LCS::LCSLength() {
  tableLength_.build(firstSequence_.length() + 1, secondSequence_.length() + 1);

  // Inicializamos la primera columna 0
  for (size_t i = 0; i <= firstSequence_.length(); i++) {
    tableLength_.setValue(i, 0, 0);
  }
  // Inicializamos la primera fila 0
  for (size_t j = 0; j <= secondSequence_.length(); j++) {
    tableLength_.setValue(0, j, 0);
  }

  // Creamos las subsecuencias
  for (size_t i = 1; i <= firstSequence_.length(); i++) {
    for (size_t j = 1; j <= secondSequence_.length(); j++) {
      if (firstSequence_[i - 1] == secondSequence_[j - 1]) {
        tableLength_.setValue(i, j, tableLength_.getValue(i - 1, j - 1) + 1);
      } else {
          tableLength_.setValue(i, j, max(tableLength_.getValue(i, j - 1), tableLength_.getValue(i - 1, j)));
      }
    }
  }

  subsequenceSize_ = tableLength_.getValue(firstSequence_.length(), secondSequence_.length());
  backtrack(firstSequence_.length(), secondSequence_.length());
}

string LCS::backtrack(int firstPos, int secondPos) {
  if (firstPos == 0 || secondPos == 0) { // Caso base: Ya no hay nada mas que comparar
    return "";
  } 
  else if (firstSequence_[firstPos - 1] == secondSequence_[secondPos - 1]) { // Si terminan igual
    result_.push_back(firstSequence_[firstPos - 1]);
    return backtrack(firstPos - 1, secondPos - 1) + firstSequence_[firstPos - 1];
  } 
  else { // no terminan igual
    if (tableLength_.getValue(firstPos, secondPos - 1) > tableLength_.getValue(firstPos - 1, secondPos)) { // le resto uno al mayor
      backtrack(firstPos, secondPos - 1);
    } 
    else {
      return backtrack(firstPos - 1, secondPos);
    }
  }
  return "";
}

void LCS::write(void) {
  cout << "Primera secuencia: " << firstSequence_ << endl;
  cout << "Segunda secuencia: " << secondSequence_ << endl;
}

void LCS::reverseResult(void) {
  string aux;
  for (int i = result_.length() - 1; i >= 0; i--) {
    aux.push_back(result_[i]);
  }
  result_ = aux;
}

int LCS::getSubSize(void) {
  return subsequenceSize_;
}

string LCS::getResult(void) {
  return result_;
}

bool LCS::checkResult() {
  size_t iterResult = 0;
  // Comprobamos que la subcadena existe en la primera
  for (size_t i = 0; i < firstSequence_.length(); i++) {
    if (firstSequence_[i] == result_[iterResult]) {
      iterResult++;
    }
  }
  if (iterResult != result_.length()) {
    return false;
  }
  // Comprobamos que la subcadena existe en la segunda
  iterResult = 0;
  for (size_t i = 0; i < secondSequence_.length(); i++) {
    if (secondSequence_[i] == result_[iterResult]) {
      iterResult++;
    }
  }
  if (iterResult != result_.length()) {
    return false;
  }
  return true;
}

