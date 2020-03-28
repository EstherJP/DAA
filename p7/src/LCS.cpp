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

int** LCS::LCSLength() {
  int** table = new int*[firstSequence_.length() + 1];
  for (size_t i = 0; i < firstSequence_.length() + 1; i++) {
    table[i] = new int[secondSequence_.length() + 1];
  }

  // Inicializamos la primera columna 0
  for (size_t i = 0; i <= firstSequence_.length(); i++) {
    table[i][0] = 0;
  }
  // Inicializamos la primera fila 0
  for (size_t j = 0; j <= secondSequence_.length(); j++) {
    table[0][j] = 0;
  }

  // Creamos las subsecuencias
  for (size_t i = 1; i <= firstSequence_.length(); i++) {
    for (size_t j = 1; j <= secondSequence_.length(); j++) {
      if (firstSequence_[i - 1] == secondSequence_[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
          table[i][j] = max(table[i][j - 1], table[i - 1][j]);
      }
    }
  }

  subsequenceSize_ = table[firstSequence_.length()][secondSequence_.length()];
  backtrack(table, firstSequence_.length(), secondSequence_.length());
  return table;
}


string LCS::backtrack(int** table, int firstPos, int secondPos) {
  if (firstPos == 0 || secondPos == 0) { // Caso base: Ya no hay nada mas que comparar
    return "";
  } 
  else if (firstSequence_[firstPos - 1] == secondSequence_[secondPos - 1]) { // Si terminan igual
    result_.push_back(firstSequence_[firstPos - 1]);
    return backtrack(table, firstPos - 1, secondPos - 1) + firstSequence_[firstPos - 1];
  } 
  else { // no terminan igual
    if (table[firstPos][secondPos - 1] > table[firstPos - 1][secondPos]) { // le resto uno al mayor
      backtrack(table, firstPos, secondPos - 1);
    } 
    else {
      return backtrack(table, firstPos - 1, secondPos);
    }
  }
  return "";
}

void LCS::write(void) {
  cout << "SECUENCIA A: " << firstSequence_ << endl;
  cout << "SECUENCIA B: " << secondSequence_ << endl;
}

void LCS::writeTable(int** table) {
 // Escribimos la tabla
  cout << "TABLA:\n";
  for (size_t i = 0; i <= firstSequence_.length(); i++) {
    for (size_t j = 0; j <= secondSequence_.length(); j++) {
      cout << table[i][j] << "    ";
    }
    cout << endl;
  }
  cout << endl;
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



void LCS::showDiff(int** table, int firstPos, int secondPos) {
  if (firstPos > 0 && firstSequence_[firstPos - 1] == secondSequence_[secondPos - 1]) {
    showDiff(table, firstPos - 1, secondPos - 1);
    cout << " " << firstSequence_[firstPos];
  } else if (secondPos > 0 && (firstPos == 0 || table[firstPos][secondPos - 1] >= table[firstPos - 1][secondPos])) {
    showDiff(table, firstPos, secondPos - 1);
    cout << " + " << secondSequence_[secondPos];
  } else if (firstPos > 0 && (secondPos == 0 || table[firstPos][secondPos - 1] < table[firstPos - 1][secondPos])) {
    showDiff(table, firstPos - 1, secondPos);
    cout << " - " << firstSequence_[firstPos];
  } else {
    cout << "";
  }
}

string LCS::getResult(void) {
  return result_;
}

