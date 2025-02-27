#include <iostream>
#include "Polynomial.h"
#include "Fraction.h"
#include "MatrixTemplate.h"

int main()
{
    std::cout << "Testing explicitly instantiated templates:" << std::endl;
    
    // Test int version
    std::cout << "\n--- Testing int version ---" << std::endl;
    int a_int = 1, b_int = 2, c_int = 3, x_int = 4;
    int result_int = quadratic<int>(a_int, b_int, c_int, x_int); // Explicitly call int version
    std::cout << "quadratic<int>(" << a_int << ", " << b_int << ", " << c_int << ", " << x_int << ") = " << result_int << std::endl;
    
    // Additional int test
    int n_int = 5;
    std::cout << "quadratic<int>(0, 2, 9, " << n_int << ") = " << quadratic<int>(0, 2, 9, n_int) << std::endl;
    
    // Test double version
    std::cout << "\n--- Testing double version ---" << std::endl;
    double a_double = 1.1, b_double = 2.2, c_double = 3.3, x_double = 4.4;
    double result_double = quadratic<double>(a_double, b_double, c_double, x_double); // Explicitly call double version
    std::cout << "quadratic<double>(" << a_double << ", " << b_double << ", " << c_double << ", " << x_double << ") = " << result_double << std::endl;
    
    // Additional double test
    double n_double = 5.0;
    std::cout << "quadratic<double>(0.0, 2.0, 9.0, " << n_double << ") = " << quadratic<double>(0.0, 2.0, 9.0, n_double) << std::endl;

    // Mixed type test (using double version)
    double d_quad = quadratic<double>(1.4, 2.0, 3.9, 0.1);
    std::cout << "\n--- Testing with mixed values (using double version) ---" << std::endl;
    std::cout << "quadratic<double>(1.4, 2.0, 3.9, 0.1) = " << d_quad << std::endl;

    // Test Fraction version
    std::cout << "\n--- Testing Fraction version ---" << std::endl;
    Fraction a_frac(1, 2);    // 1/2
    Fraction b_frac(3, 4);    // 3/4
    Fraction c_frac(1, 3);    // 1/3
    Fraction x_frac(2, 5);    // 2/5
    
    Fraction result_frac = quadratic(a_frac, b_frac, c_frac, x_frac);
    
    std::cout << "quadratic(" 
              << a_frac << ", " 
              << b_frac << ", " 
              << c_frac << ", " 
              << x_frac << ") = " 
              << result_frac << std::endl;
    
    // Another Fraction example with different values
    Fraction a2_frac(1, 1);   // 1/1 (or just 1)
    Fraction b2_frac(2, 3);   // 2/3
    Fraction c2_frac(5, 6);   // 5/6
    Fraction x2_frac(1, 2);   // 1/2
    
    Fraction result2_frac = quadratic(a2_frac, b2_frac, c2_frac, x2_frac);
    
    std::cout << "quadratic(" 
              << a2_frac << ", " 
              << b2_frac << ", " 
              << c2_frac << ", " 
              << x2_frac << ") = " 
              << result2_frac << std::endl;

    // Test Matrix template class
    std::cout << "\n--- Testing Matrix template class ---" << std::endl;
    
    // Integer matrix test
    std::cout << "\nTesting with int matrix:" << std::endl;
    Matrix<int> intMatrix(2, 3, 1); // 2x3 matrix filled with 1s
    std::cout << "Initial matrix:" << std::endl;
    intMatrix.print();
    
    // Modify some values
    intMatrix(0, 0) = 5;
    intMatrix(1, 1) = 7;
    intMatrix(0, 2) = 9;
    
    std::cout << "Modified matrix:" << std::endl;
    std::cout << intMatrix;
    
    // Double matrix test
    std::cout << "\nTesting with double matrix:" << std::endl;
    Matrix<double> doubleMatrix(2, 2, 2.5); // 2x2 matrix filled with 2.5
    std::cout << "Double matrix:" << std::endl;
    doubleMatrix.print();
    
    // Matrix addition
    std::cout << "\nTesting matrix addition:" << std::endl;
    Matrix<int> intMatrix2(2, 3, 2); // 2x3 matrix filled with 2s
    Matrix<int> sumMatrix = intMatrix + intMatrix2;
    std::cout << "Matrix 1:" << std::endl << intMatrix;
    std::cout << "Matrix 2:" << std::endl << intMatrix2;
    std::cout << "Sum:" << std::endl << sumMatrix;
    
    // Matrix multiplication
    std::cout << "\nTesting matrix multiplication:" << std::endl;
    Matrix<int> matA(2, 3, 1);
    matA(0, 0) = 1; matA(0, 1) = 2; matA(0, 2) = 3;
    matA(1, 0) = 4; matA(1, 1) = 5; matA(1, 2) = 6;
    
    Matrix<int> matB(3, 2, 1);
    matB(0, 0) = 7; matB(0, 1) = 8;
    matB(1, 0) = 9; matB(1, 1) = 10;
    matB(2, 0) = 11; matB(2, 1) = 12;
    
    Matrix<int> multResult = matA * matB;
    std::cout << "Matrix A (2x3):" << std::endl << matA;
    std::cout << "Matrix B (3x2):" << std::endl << matB;
    std::cout << "A * B (2x2):" << std::endl << multResult;
    
    // Fraction matrix test
    std::cout << "\nTesting with Fraction matrix:" << std::endl;
    Matrix<Fraction> fracMatrix(2, 2, Fraction(1, 2)); // 2x2 matrix filled with 1/2
    fracMatrix(0, 1) = Fraction(3, 4);
    fracMatrix(1, 0) = Fraction(1, 3);
    std::cout << "Fraction matrix:" << std::endl;
    std::cout << fracMatrix;
    
    // Scalar multiplication
    std::cout << "\nTesting scalar multiplication:" << std::endl;
    Matrix<int> scalarResult = matA * 2;
    std::cout << "Matrix A:" << std::endl << matA;
    std::cout << "A * 2:" << std::endl << scalarResult;
    
    // Left scalar multiplication
    Matrix<int> leftScalarResult = 3 * matA;
    std::cout << "3 * A:" << std::endl << leftScalarResult;

    return 0;
}