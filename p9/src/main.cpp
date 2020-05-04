#include <iostream>

#include "../include/data.hpp"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    throw "Error: needs a file";
  } 

  try {
    char* filename = argv[1];
    std::cout << "File name: " << filename << std::endl;

    Data setData(filename);
    setData.write();

  } catch(char const* error) {
    std::cout << error << std::endl;
  }
}