#include "../include/memory.hpp"

using namespace std;

Memory::Memory() {
    register_.resize(16);
}

Memory::~Memory() {}

// STORE
void Memory::store(int i, int dir) {
    string err;
    if(dir == 0) {
        register_[i] = register_[0];
    }

    else if(dir == 1) {
        int aux = register_[i];
        register_[aux] = register_[0];
    }

    else if(dir == 2){
        err = "Error: STORE cant't has inmediate direct";
        throw err;
    }
    else if(dir > 1) {
        err = "Error: direct doesn't exist";
        throw err;
    }

    else if(i >= 16) {
        err = "Error: overflow register";
        throw err;
    }
}

// LOAD
void Memory::load(int i, int dir) {
    string err;
    if(dir == 0) {
        register_[0] = register_[i];
    }

    if(dir == 1) {
        int aux = register_[i];
        register_[0] = register_[aux];
    }

    if(dir == 2) {
        register_[0] = i;
    }

    else if(dir > 2) {
        err = "Error: direct doesn't exist";
        throw err;
    }

    else if(i > 16){
        err = "Error: overflow register";
        throw err;
    } 
}

// READ
void Memory::read(int i, int d) {
    register_[i] = d;
}


int Memory::getAcc(void) {
    return register_[0];
}


void Memory::showMemory(void) {
    for(int i = 0; i < register_.size(); i++) {
        cout << i << ": " << register_[i] << endl;
    }
    cout << endl;
}

void Memory::setAcc(int d) {
    register_[0] = d;
}

int Memory::getReg(int i) {
    return register_[i];
}
