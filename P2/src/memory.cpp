#include "memory.hpp"

using namespace std;

Memory::Memory() {
    register_.resize(16);
}

Memory::~Memory() {}

// STORE
void Memory::store(int i, int dir) {
    if(dir == 0) {
        register_[i] = register_[0];
    }

    else if(dir == 1) {
        int aux = register_[i];
        register_[aux] = register_[0];
    }

    else if(dir > 1) {
        cout << "Error: no existe este direccionamiento\n";
        return;
    }

    else if(i > 16) {
        cout << "Error: overflow register\n";
        return;
    }
}

// LOAD
void Memory::load(int i, int dir) {
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
        cout << "Error: no existe este direccionamiento\n";
        return;
    }

    else if(i > 16) {
        cout << "Error: overflow register\n";
        return;
    }

}

void Memory::showMemory(void) {
    for(int i = 0; i < register_.size(); i++) {
        cout << i << ": " << register_[i] << endl;
    }
    cout << endl;
}
