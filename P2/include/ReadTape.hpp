#pragma once

#include <iostream>
#include <vector>

#include "tapeBase.hpp"

using namespace std;

class ReadTape : public TapeBase {
    public:
        ReadTape(char* filename);
        ~ReadTape();

        void readFile(void);
};