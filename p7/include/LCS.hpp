#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class LCS {
  private:
    string firstSequence_;
    string secondSequence_;

    string result_;
    int subsequenceSize_;

  public:
    LCS();
    LCS(size_t firstSize, size_t secondSize);
    LCS(string first, string second);

    ~LCS();

    int getSubSize(void);
    void reverseResult(void);
    string getResult(void);

    int** LCSLength();
    string backtrack(int** table, int firstPos, int secondPos);

    void showDiff(int** table, int firstPos, int secondPos);

    void build(void);
    void write(void);
    void writeTable(int** table);
};