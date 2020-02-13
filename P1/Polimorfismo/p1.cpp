#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

enum TYPESTRATEGY{R, C};


class Matrix {
    private:
        int row_;
        int col_;
        vector<int> m_;

    public:
        Matrix(int row, int col): col_(col), row_(row) {
            m_.resize(col_*row_);
        }

        Matrix(int row, int col, int s): row_(row), col_(col) {
            m_.resize(col_*row_);

            //crear m_
            srand(s);

            for(int i = 0; i < row_; i++) {
                for(int j = 0; j < col_; j++) {
                    m_[pos(i,j)] =  rand()%10;
                }
            }

            for(int i = 0; i < row_; i++) {
                for(int j = 0; j < col_; j++) {
                   cout << m_[pos(i,j)] << " ";
                }
                cout << endl;
            }

            cout << endl;
        }

        int get_row() { return row_; }
        int get_col() { return col_; }
        vector<int> get_m() { return m_; }

        int pos(int i, int j) { return (i*row_)+j; }
        int value(int i, int j) { return m_[(i*row_)+j]; }

        void write(void) {
             for(int i = 0; i < row_; i++) {
                for(int j = 0; j < col_; j++) {
                   cout << m_[pos(i,j)] << " ";
                }
                cout << endl;
            }
        }

        void set_m(int i, int j, int a, int b) {
         //   cout << i << j << ": " << a << " + " << m_[pos(i,j)] << endl;
            m_[pos(i,j)] += a*b;
         //   cout << "r: " << m_[pos(i,j)] << endl;
        }
};

//Clase abstracta estrategia
class Strategy {
    public: 
        virtual void MatrixProduct(Matrix& a, Matrix& b) = 0;
};

//Clase estrategia por filas
class StrategyRow : public Strategy {
    public:
        void MatrixProduct(Matrix& a, Matrix& b) {
            cout << "StrategyRow" << endl;
            if(a.get_col() == b.get_row()) {
                Matrix c(a.get_row(), b.get_col());

                for(int i = 0; i < a.get_row(); i++) {
                    for(int j = 0; j < b.get_col(); j++) {
                        for(int k = 0; k < a.get_col(); k++) {
                          //  cout << a.value(i,k) << " * " << b.value(k,j) << endl;
                            c.set_m(i,j,a.value(i,k), b.value(k,j));
                        }
                    }
                }
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
            cout << "StrategyColumn" << endl;
            if(a.get_col() == b.get_row()) {
                Matrix c(a.get_row(), b.get_col());

                for(int i = 0; i < a.get_row(); i++) {
                    for(int j = 0; j < b.get_col(); j++) {
                        for(int k = 0; k < a.get_col(); k++) {
                          //  cout << a.value(i,k) << " * " << b.value(k,j) << endl;
                            c.set_m(j,i,a.value(i,k), b.value(k,j));
                        }
                    }
                }
                c.write();
            }
            
            else {
                cout << "No se puede" << endl;
            }

        }
};

class Context {
    private:
        Strategy* strategy_;

    public:
        //Constructor por defecto
        Context(): strategy_(NULL) {}
        //Contructor
        Context(Strategy* strategy): strategy_(strategy) {}

        // void setstrategy(TYPESTRATEGY type, Matrix a, Matrix b) {
	    //     delete strategy_;

        //     if (type == R)
        //         strategy_ = new StrategyRow();

        //     else if (type == C)
        //         strategy_ = new StrategyColumn();
    
        //     cout << "ERROR: Stratey not known" << endl; 
        //  }

        // void setstrategy(Strategy *strategy ) {
	    //     delete strategy_;
	    //     strategy_ = strategy;
        // }

        void ContextInterface(Matrix& a, Matrix& b) {
            if(strategy_)
                strategy_->MatrixProduct(a, b);
            else
		        cout << "ERROR: Strategy not set" << endl;
        }
};

int main(void) {
    // Context context;
    Context* context_r;
    Context* context_c;

    int r, c, rr, cc, s=12;

    cout << "Numero filas matriz a: ";
    cin >> r;
    cout << endl;

    cout << "Numero columnas matriz a: ";
    cin >> c;
    cout << endl << endl;

    cout << "Numero filas matriz b: ";
    cin >> rr;
    cout << endl;

    cout << "Numero columnas matriz b: ";
    cin >> cc;
    cout << endl;


    //por la cara con las combinaciones de 4/3 me peta :)
    Matrix a(r, c, s+45);
    Matrix b(rr, cc, s);

    
    context_c = new Context(new StrategyRow());
    context_c->ContextInterface(a, b);

    cout << endl;

    context_r = new Context(new StrategyColumn());
    context_r->ContextInterface(a, b);
}

