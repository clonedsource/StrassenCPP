#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m = {3, 3, new float[9]{1}};
    std::cout << "Hello\n";
    std::cout << m.data[0] << std::endl;
    delete[] m.data;
    return 0;
}