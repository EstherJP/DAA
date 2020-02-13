#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "../include/matrix.hpp"
#include "../include/strategyBase.hpp"
#include "../include/strategy.hpp"
#include "../include/context.hpp"

using namespace std;

int main(void) {
    // Punteros a los contextos
    Context* context_r;
    Context* context_c;
    Context* context_t;

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
    context_t = new Context(new StrategyTras());

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

    start = chrono::system_clock::now();
    context_t->ContextInterface(a, b);
    end = chrono::system_clock::now();

    duration = end-start;
    cout << "Tiempo transcurrido: " << duration.count() << "ms" << endl << endl;

    delete context_c;
    delete context_r;
}


//MODIFICACION:  hacer un metodo c = axb en el que calcule b traspuesta y luego hacemos que c sea a x b traspuesta 
// no aceder nunca a columnas, fila x fila
// la trasponemos deberia ser mas eficiente


