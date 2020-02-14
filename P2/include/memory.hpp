#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Memory {
    private:
        vector<int> register_;
        // int dir_; // 0 directo, 1 indirecto, 2 inmediato

    public:
        Memory();
        ~Memory();

        void load(int i, int dir);
        void store(int i, int dir);
        void showMemory(void);
        // int read(int i, int dir); leo cinta store
};

