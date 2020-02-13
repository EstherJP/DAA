#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

// Clase matriz
class Matrix {
    private:
        int row_;
        int col_;
        int** m_;

    public:
        // Constructor matriz vacía
        Matrix(int row, int col): col_(col), row_(row) {
            m_ = new int* [row_];
            for(int i = 0; i < row_; i++) {
                m_[i] = new int[col_];
                for(int j = 0; j < col_; j++) {
                    m_[i][j] = 0;
                } 
            }
        }
        // Constructor matriz aleatoria
        Matrix(int row, int col, int s): row_(row), col_(col) {
            m_ = new int* [row_];
            for(int i=0; i < row_; i++) {
                m_[i] = new int[col_];
            }

            build_matrix(s);
            // write();
        }
        // Destructor
        ~Matrix() {
            for(int i = 0; i < row_; i++) {
                delete[] m_[i];
            }
            delete[] m_;
        }
        // Rellenar la matriz con numerso aleatorios
        void build_matrix(int s) {
            srand(s);
            for(int i = 0; i < row_; i++) {
                for(int j = 0; j < col_; j++) {
                    m_[i][j] = rand()%10;
                }
            }
        }
        // Gettes y settes
        int get_row() { return row_; }
        int get_col() { return col_; }
        int** get_m() { return m_; }
        int get_value(int i, int j) { return m_[i][j]; }

        void set_value(int i, int j, int a) {
            m_[i][j]  = a;
        }
        // Escribir matriz
        void write(void) {
             for(int i = 0; i < row_; i++) {
                for(int j = 0; j < col_; j++) {
                    cout << m_[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
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

                for(int i = 0; i < b.get_col(); i++) {  //bc
                    for(int j = 0; j < a.get_row(); j++) {   //ar
                        for(int k = 0; k < a.get_col(); k++) {
                            acc += a.get_value(j, k)*b.get_value(k, i);
                        }
                        c.set_value(j, i, acc);
                        acc = 0;
                    }
                }
            }
            
            else {
                cout << "No se puede" << endl;
            }

        }
};

// Clase contexto
class Context {
    private:
        Strategy* strategy_;

    public:
        //Constructor por defecto
        Context(): strategy_(NULL) {}

        //Contructor
        Context(Strategy* strategy): strategy_(strategy) {}

        // Llamada a la estrategia según el contexto
        void ContextInterface(Matrix& a, Matrix& b) {
            if(strategy_)
                strategy_->MatrixProduct(a, b);
            else
		        cout << "ERROR: Strategy not set" << endl;
        }
};

int main(void) {
    // Punteros a los contextos
    Context* context_r;
    Context* context_c;

    // Variables filas y columnas de ambas matrices y semilla
    int ar, ac, br, bc, s=12;

    cout << "Numero filas matriz a: ";
    cin >> ar;
    cout << "Numero columnas matriz a: ";
    cin >> ac;
    cout << endl;

    cout << "Numero filas matriz b: ";
    cin >> br;
    cout << "Numero columnas matriz b: ";
    cin >> bc;
    cout << endl << endl;

    // Creación de matrices
    Matrix a(ar, br, s);
    Matrix b(br, bc, s+12);

    // Creación de los punteros a las estrategias según el contexto
    context_c = new Context(new StrategyRow());
    context_r = new Context(new StrategyColumn());

    // Llamadas a las estrategias y cálculo del tiempo de ejecución
    chrono::time_point<chrono::system_clock> start, end;

    start = chrono::system_clock::now();
    context_c->ContextInterface(a, b);
    end = chrono::system_clock::now();

    chrono::duration<float, milli> duration = end-start;
    cout << "Tiempo transcurrido: " << duration.count() << "ms" << endl << endl;

    start = chrono::system_clock::now();
    context_r->ContextInterface(a, b);
    end = chrono::system_clock::now();

    duration = end-start;
    cout << "Tiempo transcurrido: " << duration.count() << "ms" << endl << endl;

    delete context_c;
    delete context_r;
}


