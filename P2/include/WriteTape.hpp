#pragma once

#include <iostream>
#include <vector>

#include "tapeBase.hpp"

using namespace std;

class WriteTape : public TapeBase {
    public:
        WriteTape(char* filename);
        ~WriteTape();

        void writeFile(void);
};