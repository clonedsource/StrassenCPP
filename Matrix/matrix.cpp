#include <cstdint>

// Order prevents padding, saving space.
struct Matrix {
    uint32_t dim0; // 4 Bytes
    uint32_t dim1; // 4 Bytes
    float* data; // 8 Bytes
}; // 16 Bytes Total.