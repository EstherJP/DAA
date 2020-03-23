#include "../include/matrix.hpp"

using namespace std;

Matrix::Matrix() {}

Matrix::Matrix(int size): row_(size), col_(size - 1) {
  m_ = new int* [row_];
  for(int i = 0; i < row_; i++) {
    m_[i] = new int[col_];
    for(int j = 0; j < col_; j++) {
      m_[i][j] = 0;
    } 
  }
}

Matrix::~Matrix() {
/*  for(int i = 0; i < row_; i++) {
    delete[] m_[i];
  }
  delete[] m_; */
}

void Matrix::write(void) {
  for(int i = 0; i < row_; i++) {
    cout << i + 1 << ": ";
    for(int j = 0; j < col_; j++) {
      cout << m_[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int** Matrix::getMatrix(void) {
  return m_;
}

int Matrix::getValue(int i, int j) {
  return m_[i][j];
}

void Matrix::setValue(int i, int j, int value) {
  m_[i][j] = value;
}

int Matrix::getRow() {
  return row_;
}
