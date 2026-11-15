#include <cstdint>
#include <stdexcept>
#include <string>

// Order prevents padding, saving space.
struct Matrix {
    uint32_t dim0; // 4 Bytes
    uint32_t dim1; // 4 Bytes
    double* data; // 8/4 Bytes (System Dependent.)

    // Default Constructor.
    Matrix (uint32_t dim0_, uint32_t dim1_) : dim0(dim0_), dim1(dim1_), data(new double[dim0_ * dim1_]{0.0}) {};
    
    // Construct by Reference Constructor.
    Matrix (const Matrix& m) : dim0(m.dim0), dim1(m.dim1) {
        // Important to do this because we want to own the memory of this value.
        this->data = new double[this->dim0 * this->dim1]{0.0};
        // Copy into new matrix.
        std::memcpy(this->data, m.data, sizeof(double) * this->size());
    };
    // Epic Constructor (!WARNING! unsafe because code trusts sufficient sized array is passed in.)
    Matrix (uint32_t dim0_, uint32_t dim1_, double* data_) : dim0(dim0_), dim1(dim1_), data(data_) {};

    // Number of elements in the matrix.
    const size_t size() const {return this->dim0 * this->dim1;};
    // Size of matrix in memory.
    const size_t size_mem() const {
        // 8 Bytes for the dimensions.
        // 8/4 Bytes (System Dependent) for pointer to data.
        // 8n Bytes for data.
        return 8 + sizeof(double*) + (sizeof(double) * this->size());
    };
    // (row, col) => index.
    const size_t index(size_t row, size_t col) const {
        return (row - 1) * this->dim1 + col - 1;
    };
    // index => (row, col).
    const size_t* position(size_t index) const {
        size_t positions[2] = {index / this->dim1, index % this->dim1};
        return positions;
    };
    const std::string format() {
        std::string matrix_str = "";
        for (size_t row = 1; row <= dim0; row++) {
            matrix_str.append("[");
            for (size_t col = 1; col <= dim1; col++) {
                double value = data[index(row, col)];
                matrix_str.append(std::to_string(value));
                if (col == dim1) {continue;};
                matrix_str.append(", ");
            };
            matrix_str.append("]\n");
        };
        return matrix_str;
    };
    // Destructor (Cleans memory up without explicitly requiring a free to be used).
    ~Matrix() {delete[] this->data;};
}; // 16/12 Bytes Total.

// Overloads multiplication operators.
Matrix operator* (const Matrix& m, const double& c) {
    // Creates a copy of Matrix m.
    Matrix m_cpy(m);
    // Multiples all entries by the constant c.
    for (size_t i = 0; i < m.size();i++) {m_cpy.data[i] *= c;};
    // Returns.
    return m_cpy;
};
Matrix operator*= (Matrix& m, const double& c) {
    // Multiples all entries by the constant c.
    for (size_t i = 0; i < m.size();i++) {m.data[i] *= c;};
    return m;
};

// Overloads division operators.
Matrix operator/ (const Matrix& m, const double& c) {
    // Creates a copy of Matrix m.
    Matrix m_cpy(m);
    // Divides all entries by the constant c.
    for (size_t i = 0; i < m.size();i++) {m_cpy.data[i] /= c;};
    // Returns.
    return m_cpy;
};
Matrix operator/= (Matrix& m, const double& c) {
    // Divides all entries by the constant c.
    for (size_t i = 0; i < m.size();i++) {m.data[i] /= c;};
    return m;
};

// Overloads addition operators.
Matrix operator+ (const Matrix& m1, const Matrix& m2) {
    // Make sure dimensions match, otherwise throw error.
    if (m1.dim0 != m2.dim0 || m1.dim1 != m2.dim1) {
        throw std::runtime_error("Dimensions of matrices do not match!");
    };

    // Creates a copy of Matrix m.
    Matrix m_cpy(m1);
    // Adds entries to entries.
    for (size_t i = 0; i < m1.size(); i++) {m_cpy.data[i] += m2.data[i];};
    // Returns.
    return m_cpy;
};
Matrix operator+= (Matrix& m1, const Matrix& m2) {
    // Make sure dimensions match, otherwise throw error.
    if (m1.dim0 != m2.dim0 || m1.dim1 != m2.dim1) {
        throw std::runtime_error("Dimensions of matrices do not match!");
    };

    // Adds entries to entries.
    for (size_t i = 0; i < m1.size(); i++) {m1.data[i] += m2.data[i];};
    return m1;
};
// Overloads subtraction operators.
Matrix operator- (const Matrix& m1, const Matrix& m2) {
    // Make sure dimensions match, otherwise throw error.
    if (m1.dim0 != m2.dim0 || m1.dim1 != m2.dim1) {
        throw std::runtime_error("Dimensions of matrices do not match!");
    };

    // Creates a copy of Matrix m.
    Matrix m_cpy(m1);
    // Subtracts entries from entries.
    for (size_t i = 0; i < m1.size(); i++) {m_cpy.data[i] -= m2.data[i];};
    // Returns.
    return m_cpy;
};
Matrix operator-= (Matrix& m1, const Matrix& m2) {
    // Make sure dimensions match, otherwise throw error.
    if (m1.dim0 != m2.dim0 || m1.dim1 != m2.dim1) {
        throw std::runtime_error("Dimensions of matrices do not match!");
    };

    // Subtracts entries from entries.
    for (size_t i = 0; i < m1.size(); i++) {m1.data[i] -= m2.data[i];};
    return m1;
};
