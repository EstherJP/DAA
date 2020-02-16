#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Memory {
    private:
        vector<int> register_;

    public:
        Memory();
        ~Memory();

        void load(int i, int dir);
        void store(int i, int dir);

        int getAcc(void);
        void setAcc(int d);
        int getReg(int i);

        void read(int i, int d);

        void showMemory(void);
};

