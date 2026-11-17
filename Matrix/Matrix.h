#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
// Order prevents padding, saving space.
struct Matrix {
    uint32_t dim0; // 4 Bytes
    uint32_t dim1; // 4 Bytes
    double* data; // 8/4 Bytes (System Dependent.)

    // Default Constructor.
    Matrix (uint32_t dim0_, uint32_t dim1_);
    // Construct by Reference Constructor.
    Matrix (const Matrix& m);
    // Epic Constructor (!WARNING! unsafe because code trusts sufficient sized array is passed in.)
    Matrix (uint32_t dim0_, uint32_t dim1_, double* data_);
    
    const size_t size() const; // Number of elements in the matrix.
    const size_t size_mem() const; // Size of matrix in memory.
    const size_t index(size_t row, size_t col) const; // (row, col) => index.
    const size_t* position(size_t index) const; // index => (row, col).
    const std::string format();

    // Destructor (Cleans memory up without explicitly requiring a free to be used).
    ~Matrix();
}; // 16/12 Bytes Total.

// Overloads multiplication operators.
Matrix operator* (const Matrix& m, const double& c);
Matrix operator*= (Matrix& m, const double& c);
// Overloads division operators.
Matrix operator/ (const Matrix& m, const double& c);
Matrix operator/= (Matrix& m, const double& c);
// Overloads addition operators.
Matrix operator+ (const Matrix& m1, const Matrix& m2);
Matrix operator+= (Matrix& m1, const Matrix& m2);
// Overloads subtraction operators.
Matrix operator- (const Matrix& m1, const Matrix& m2);
Matrix operator-= (Matrix& m1, const Matrix& m2);
// Fun implements
Matrix random_matrix_int(const size_t dim0, const size_t dim1, const int range_min, const int range_max);
#endif