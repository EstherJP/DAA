#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

#include "matrix.hpp"

using namespace std;

class LCS {
  private:
    string firstSequence_;
    string secondSequence_;

    Matrix tableLength_;

    string result_;
    int subsequenceSize_;

  public:
    LCS();
    LCS(size_t firstSize, size_t secondSize);
    LCS(string first, string second);

    ~LCS();

    void build(void);

    int getSubSize(void);
    void reverseResult(void);
    string getResult(void);

    void LCSLength();
    string backtrack( int firstPos, int secondPos);

    bool checkResult();

    void write(void);
};