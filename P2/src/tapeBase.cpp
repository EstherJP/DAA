#include "tapeBase.hpp"

using namespace std;

TapeBase::TapeBase() {}

TapeBase::TapeBase(char* filename): filename_(filename) {
    int cabezal_ = 0;
}

TapeBase::~TapeBase() {}

char* TapeBase::getFilename(void) {
    return filename_;
}

int TapeBase::getCabezal(void) { 
    return cabezal_; 
}

int TapeBase::getValue(void) {
    return tape_[cabezal_];
}

void TapeBase::incrementCabezal(void) { 
    cabezal_ = cabezal_+1; 
}

vector<int> TapeBase::getTape(void) { 
    return tape_; 
}

void TapeBase::setTape(int t) { 
    tape_.push_back(t); 
}

void TapeBase::showTape(void) {
    for(int i = 0; i < tape_.size(); i++) {
        cout << tape_[i] << " ";
    }
    cout << endl;
}
