#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

template <typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    std::vector<std::vector<T>> data; // Using vector of vectors for memory safety

public:
    // Default constructor - creates an empty 0x0 matrix
    Matrix() : rows(0), cols(0), data() {}

    // Constructor with dimensions - creates an NxM matrix initialized with default values
    Matrix(size_t numRows, size_t numCols) : rows(numRows), cols(numCols) {
        data.resize(rows);
        for (size_t i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }
    }

    // Constructor with dimensions and initial value - creates an NxM matrix filled with the given value
    Matrix(size_t numRows, size_t numCols, const T& initialValue) : rows(numRows), cols(numCols) {
        data.resize(rows);
        for (size_t i = 0; i < rows; ++i) {
            data[i].resize(cols, initialValue);
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // Element access with bounds checking
    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[row][col];
    }

    // Const element access with bounds checking
    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[row][col];
    }

    // Operator () for simpler element access (with bounds checking)
    T& operator()(size_t row, size_t col) {
        return at(row, col);
    }

    // Const operator () for simpler element access
    const T& operator()(size_t row, size_t col) const {
        return at(row, col);
    }

    // Dimensions getters
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Matrix addition
    Matrix operator+(const Matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    // Matrix subtraction
    Matrix operator-(const Matrix& rhs) const {
        if (rows != rhs.rows || cols != rhs.cols) {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - rhs.data[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& rhs) const {
        if (cols != rhs.rows) {
            throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
        }

        Matrix result(rows, rhs.cols, T()); // Initialize with default-constructed T
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < rhs.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
                }
            }
        }
        return result;
    }

    // Scalar multiplication
    Matrix operator*(const T& scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    // Check if matrices are equal
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            return false;
            
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (data[i][j] != other.data[i][j])
                    return false;
            }
        }
        return true;
    }

    // Print the matrix
    void print(std::ostream& os = std::cout, int width = 8) const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                os << std::setw(width) << data[i][j] << " ";
            }
            os << std::endl;
        }
    }
};

// Non-member function to print a matrix
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    matrix.print(os);
    return os;
}

// Non-member function for scalar multiplication (scalar on left)
template<typename T>
Matrix<T> operator*(const T& scalar, const Matrix<T>& matrix) {
    return matrix * scalar; // Reuse the member function
}
