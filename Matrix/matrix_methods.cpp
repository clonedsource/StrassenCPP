#include "matrix_methods.h"

// Holy naive.
Matrix naive_multiplication(const Matrix& ma, const Matrix& mb) {
    // (mxn)(qxr) where n = q is required for multiplication.
    if (ma.dim1 != mb.dim0) {
        throw std::runtime_error("column size of matrix a does not match row size of matrix b!");
    };
};
void endtimes() {

};


