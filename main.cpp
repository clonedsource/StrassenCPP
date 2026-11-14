#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m = {3, 3, new float[9]{0}};
    delete[] m.data;
    std::cout << "Hello\n";
    return 0;
}