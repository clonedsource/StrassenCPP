#include <cstdint>
#include <string>

// Order prevents padding, saving space.
struct Matrix {
    uint32_t dim0; // 4 Bytes
    uint32_t dim1; // 4 Bytes
    double* data; // 8/4 Bytes (System Dependent.)

    // Default Constructor.
    Matrix (uint32_t dim0_, uint32_t dim1_) : dim0(dim0_), dim1(dim1_), data(new double[dim0_ * dim1_]{0}) {};
    // Epic Constructor.
    Matrix (uint32_t dim0_, uint32_t dim1_, double* data_) : dim0(dim0_), dim1(dim1_), data(data_) {};
    
    // Destructor (Cleans memory up without explicitly requiring a free to be used).
    ~Matrix() {delete[] this->data;};

    // Number of elements in the matrix.
    size_t size() {return this->dim0 * this->dim1;};
    // Size of matrix in memory.
    size_t size_mem() {
        // 8 Bytes for the dimensions.
        // 8/4 Bytes (System Dependent) for pointer to data.
        // 8n Bytes for data.
        return 8 + sizeof(double*) + (sizeof(double) * this->size());
    }
}; // 16/12 Bytes Total.

/*
    Passing in a const Matrix pointer is preferable because for large matrices a pass by value
    copies all of the matrices original data into another location in memory.
    This is not good because it takes time to copy that memory, also because it is a 
    huge waste of memory.
*/
std::string matrix_format(const Matrix* m) {
    return "lord verity";
}
