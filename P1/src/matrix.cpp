#include "../include/matrix.hpp"

using namespace std;

Matrix::Matrix(int row, int col): col_(col), row_(row) {
    m_ = new int* [row_];
    for(int i = 0; i < row_; i++) {
        m_[i] = new int[col_];
        for(int j = 0; j < col_; j++) {
            m_[i][j] = 0;
        } 
    }
    t_ = new int*[col_];

    for(int i=0; i < col_; i++){
        t_[i]= new int[row_];
    }
    trasponer();
}

Matrix::Matrix(int row, int col, int s): row_(row), col_(col) {
    m_ = new int* [row_];
    for(int i=0; i < row_; i++) {
        m_[i] = new int[col_];
    }

    t_ = new int*[col_];

    for(int i=0; i < col_; i++){
        t_[i]= new int[row_];
    }
    build_matrix(s);
    trasponer();
}

Matrix::~Matrix() {
    for(int i = 0; i < row_; i++) {
        delete[] m_[i];
    }
    delete[] m_;
}

void Matrix::build_matrix(int s) {
    srand(s);
    for(int i = 0; i < row_; i++) {
        for(int j = 0; j < col_; j++) {
            m_[i][j] = rand()%10;
        }
    }
}

int Matrix::get_row(void) { return row_; }
int Matrix::get_col(void) { return col_; }
int** Matrix::get_m(void) { return m_; }
int Matrix::get_value(int i, int j) { return m_[i][j]; }

int** Matrix::get_t(void) { 
    return t_;
}
int Matrix::get_value_t(int i, int j) {
    return t_[i][j];
}

void Matrix::set_value(int i, int j, int a) {
    m_[i][j]  = a;
}

void Matrix::write(void) {
    for(int i = 0; i < row_; i++) {
        for(int j = 0; j < col_; j++) {
            cout << m_[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::trasponer(void){
      
    for(int i=0; i < col_; i++){
        for(int j=0; j < row_; j++){
            t_[i][j]= m_[j][i];
        }
    }
}

void Matrix::write_t(void) {
    trasponer();
    for(int i=0; i < col_; i++){
        for(int j=0; j < row_; j++){
            cout << t_[i][j]<< " ";
        }
        cout << endl;
    }
}