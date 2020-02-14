#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class TapeBase {
    private:
        char* filename_;    // Nombre del fichero para leer o escribir
        int cabezal_;       // Cabezal de la cinta de escritura o de lectura
        vector<int> tape_;  // Cinta representada como un vector que albergará los valores por orden del fichero de entrada cuyo índice será el cabezal

    public:
        TapeBase();                 // Constructor por defecto
        TapeBase(char* filename);   // Contructor al que le llega el nombre del fichero e inicializa el cabzal a 0
        ~TapeBase();                // Destructor por defecto

        char* getFilename(void);    

        int getCabezal(void);
        int getValue(void);         // Get el valor de la cinta a la que apunta el cabezal

        void incrementCabezal(void);    // Incrementa el cabezal en uno

        vector<int> getTape(void);
        void setTape(int t);

        void showTape(void);
};