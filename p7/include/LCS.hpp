#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class LCS {
  private:
    string firstSequence_;
    string secondSequence_;
    string subsequence_;

    int subsequenceSice_;

  public:
    LCS();
    LCS(size_t firstSize, size_t secondSize);
    ~LCS();

    void build(void);
    void write(void);
};