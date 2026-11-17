// Make sure we don't have duplicate defines.
#ifndef MATRIX_METHODS_H
#define MATRIX_METHODS_H
#include "Matrix.h"
#include <cstdlib>
#include <ctime>
Matrix random_matrix_int(const size_t dim0, const size_t dim1, const int range_min, const int range_max);
Matrix naive_multiplication(const Matrix& ma, const Matrix& mb);
Matrix strassen_multiplication(const Matrix& ma, const Matrix& mb);
#endif