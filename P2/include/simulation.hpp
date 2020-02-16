#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>
#include <utility>
#include "../include/instruction.hpp"
#include "../include/memory.hpp"
#include "../include/ReadTape.hpp"
#include "../include/WriteTape.hpp"

using namespace std;

class Simulation {
    private:
        char* filename_;                    // nombre fichero del programa
        vector<string> program_;            // programa sin chequear
        vector<Instruction> legalProgram_;  // memoria de instruccciones programa con el que voy a trabajar

        int PC_= 0;
        int totalInstr_ = 0;

        vector<pair<string, int>> tags_;

        Memory reg_;
        ReadTape read_;
        WriteTape write_;

    public:
        Simulation(char* filename, ReadTape& read, WriteTape& write);
        ~Simulation();

        void readFile(void);
        void createProgram(void);

        Memory getReg(void);
        ReadTape getRTape(void);
        WriteTape getWTape(void);
        int getTotalInstr(void);

        void ejecutar(int t = 0);

        void showProgram(void);

};