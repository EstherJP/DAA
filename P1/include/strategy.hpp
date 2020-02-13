#pragma once

#include <iostream>

#include "matrix.hpp"
#include "strategyBase.hpp"

using namespace std;

//Clase estrategia por filas
class StrategyRow : public Strategy {
    public:
        void MatrixProduct(Matrix& a, Matrix& b) {
            cout << "-----StrategyRow-----" << endl;
    
            if(a.get_col() == b.get_row()) {
                Matrix c(a.get_row(), b.get_col());
                int acc = 0;

                for(int i = 0; i < a.get_row(); i++) {
                    for(int j = 0; j < b.get_col(); j++) {
                        for(int k = 0; k < a.get_col(); k++) {
                            acc += a.get_value(i, k)*b.get_value(k, j);
                        }
                        c.set_value(i, j, acc);
                        acc = 0;
                    }
                }
                cout << "matriz c row" << endl;
                c.write();
            }
            
            else {
                cout << "No se puede" << endl;
            }
        }
};

//Clase estrategia por columnas
class StrategyColumn : public Strategy {
    public:     
        void MatrixProduct(Matrix& a, Matrix& b) {
            cout << "-----StrategyColumn-----" << endl;

            if(a.get_col() == b.get_row()) {
                Matrix c(a.get_row(), b.get_col());
                int acc = 0;

                for(int i = 0; i < b.get_col(); i++) {  
                    for(int j = 0; j < a.get_row(); j++) {   
                        for(int k = 0; k < a.get_col(); k++) {
                            acc += a.get_value(j, k)*b.get_value(k, i);
                        }
                        c.set_value(j, i, acc);
                        acc = 0;
                    }
                }
                cout << "matriz c col" << endl;
                c.write();
            }
            
            else {
                cout << "No se puede" << endl;
            }

        }
};

//Clase estrategia por columnas
class StrategyTras : public Strategy {
    public:     
        void MatrixProduct(Matrix& a, Matrix& b) {
            cout << "-----StrategyTras-----" << endl;
            
            if(a.get_row() == b.get_row() && a.get_col() == b.get_col()) {
                Matrix c(a.get_row(), b.get_row());
                int acc = 0;
                for(int i = 0; i < a.get_row(); i++) {  
                    for(int j = 0; j < b.get_row(); j++) {   
                        for(int k = 0; k < a.get_col(); k++) {
                            acc += a.get_value(i, k)*b.get_value_t(j, k);
                        }
                        c.set_value(i, j, acc);
                        acc = 0;
                    }
                }
                cout << "matriz c tras" << endl;
                c.write();
            }
            
            else {
                cout << "No se puede" << endl;
            }

    }
};
