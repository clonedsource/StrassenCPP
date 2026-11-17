#include "matrix_methods.h"
// Holy naive.
Matrix naive_multiplication(const Matrix& ma, const Matrix& mb) {
    // (mxn)(qxr) where n = q is required for multiplication.
    if (ma.dim1 != mb.dim0) {
        throw std::runtime_error("column size of matrix a does not match row size of matrix b!");
    };
    // Copies the dimension, makes matrix c (filled with all 0 entries).
    Matrix mc(ma.dim0, mb.dim1);
    // c_ij = a_i1*b1_j + a_i2+b2_j + ... + a_in*b_nj
    // Reordering may be needed for cache hit/miss efficiency reasons.
    for (size_t m = 1; m <= mc.dim0; m++) {
        for (size_t n = 1; n <= mc.dim1; n++) {
            size_t main_index = mc.index(m,n);
            for (size_t k = 1; k <= ma.dim1; k++) {
              mc.data[main_index] += ma.data[ma.index(m,k)] * mb.data[mb.index(k,n)];  
            };
        };
    };
};
// Chad O(n^log2(7)) time complexity.
Matrix strassen_multiplication(const Matrix& ma, const Matrix& mb) {
    // (mxn)(qxr) where n = q is required for multiplication.
    if (ma.dim1 != mb.dim0) {
        throw std::runtime_error("column size of matrix a does not match row size of matrix b!");
    };
    // Pad the matrix.
    // Do recursion.
    // Recombine.
    // Return.
};

