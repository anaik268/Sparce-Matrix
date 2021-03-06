//
//  main.cpp
//  cs435 project
//
//  Created by Abhishek Naik on 10/30/15.
//  Copyright (c) 2015 Abhishek Naik. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include "ArrayOfLists2DList.h"
#include "Array2DList.h"
#include "SparseMatrix.h"

using namespace std;

int main(int argc, const char * argv[]) {
    //Initialization of sparseMatrix and their strings respective of the requirements set forth in instructions
    //
    string matrixAString = "3r1c1,5r1c4,2r2c2,-7r2c3,5r3c1,-3r3c2,6r4c2,-5r4c4";
    string matrixBString = "1r1c1,1r1c5,1r2c2,1r2c6,1r3c3,1r4c1,1r4c4";
    
    SparseMatrix* matrixA = new SparseMatrix(matrixAString);
    SparseMatrix* matrixB = new SparseMatrix(matrixBString);
    SparseMatrix* matrixC = new SparseMatrix(5,6);
    SparseMatrix* matrixD = new SparseMatrix(6,5);
    SparseMatrix* matrixE = new SparseMatrix(200, 200);
    SparseMatrix* matrixF = new SparseMatrix(200,1);
    SparseMatrix* matrixG = new SparseMatrix(30000,30000);
    
    //Fomulating and inserting matrix C
    
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 6; j++){
            if((i+j)%2 == 0)
            {
                matrixC->getList()->insertValueAt(i*j, i, j);
            }
        }
    }
    
    //formulating and inserting matrix D:
    //
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <= 5; j++){
            if((i*j)%4 == 0)
            {
                matrixD->getList()->insertValueAt(i+j, i, j);
            }
        }
    }
    
    //formulating and inserting matrix D:
    //
    for(int i = 1; i <= 200; i++)
    {
        for(int j = 1; j <= 200; j++){
            if(i%10 == 0)
            {
                matrixE->getList()->insertValueAt(i+2*j, i, j);
            }
        }
    }
    
    //formulating and inserting matrix F:
    //
    for(int i = 1; i <= 200; i++)
    {
        for(int j = 1; j <= 1; j++){
            if(i%5 == 0)
            {
                matrixF->getList()->insertValueAt(5*i, i, j);
            }
        }
    }

    //formulating and inserting matrix G:
    //
    for(int i = 1; i <= 30000; i++)
    {
        srand(time(0)); // use current time as seed for random generator
        int randomNum = std::rand();
        for(int j = 1; j <= 30000; j++){
            if(randomNum % 100 == 0)
            {
                matrixG->getList()->insertValueAt(i+j, i, j);
            }
        }
    }
    
    
    //Performing the tests:
    //
    //TEST 1: print each value rowWise
    clock_t printTimeBegin = clock();
    cout << "Matrix A Row wise:" << endl;
    matrixA->printRowWise();
    cout << "\nMatrix B Row wise:" << endl;
    matrixB->printRowWise();
    cout << "\nMatrix C Row wise:" << endl;
    matrixC->printRowWise();
    cout << "\nMatrix D Row wise:" << endl;
    matrixD->printRowWise();
    cout << "\nMatrix E Row wise:" << endl;
    matrixE->printRowWise();
    cout << "\nMatrix F Row wise:" << endl;
    matrixF->printRowWise();
    cout << "\nMatrix G Row wise:" << endl;
    matrixG->printRowWise();
    clock_t printTimeEnd = clock();
    
    clock_t printMatrixTimeBegin = clock();
    //TEST 2: print each matrix itself.
    cout << "Matrix A:" << endl;
    matrixA->print();
    cout << "\nMatrix B:" << endl;
    matrixB->print();
    cout << "\nMatrix C:" << endl;
    matrixC->print();
    cout << "\nMatrix D:" << endl;
    matrixD->print();
    cout << "\nMatrix E:" << endl;
    matrixE->print();
    cout << "\nMatrix F:" << endl;
    matrixF->print();
    cout << "\nMatrix G:" << endl;
    matrixG->print();
    clock_t printMatrixTimeEnd = clock();
    
    
    clock_t scalarMultiplyBegin = clock();
    //test 3: Scalar multiply each matrix by 5
    cout << "Matrix A multiplied by 5:" << endl;
    matrixA->scalarMultiply(5)->print();
    cout << "\nMatrix B multiplied by 5" << endl;
    matrixB->scalarMultiply(5)->print();
    cout << "\nMatrix C multiplied by 5:" << endl;
    matrixC->scalarMultiply(5)->print();
    cout << "\nMatrix D multiplied by 5:" << endl;
    matrixD->scalarMultiply(5)->print();
    cout << "\nMatrix E multiplied by 5:" << endl;
    matrixE->scalarMultiply(5)->print();
    cout << "\nMatrix F multiplied by 5:" << endl;
    matrixF->scalarMultiply(5)->print();
    cout << "\nMatrix G multiplied by 5:" << endl;
    matrixG->scalarMultiply(5)->print();
    clock_t scalarMultiplyEnd = clock();
    
    clock_t equalsMethodBegin = clock();
    //TEST 4: Apply equals pairwise matrix A-g
    cout << "Matrix A equals Matrix A: " << matrixA->equals(matrixA) << endl;
    cout << "Matrix A equals Matrix B: " << matrixA->equals(matrixB) << endl;
    cout << "Matrix A equals Matrix C: " << matrixA->equals(matrixC) << endl;
    cout << "Matrix A equals Matrix D: " << matrixA->equals(matrixD) << endl;
    cout << "Matrix A equals Matrix E: " << matrixA->equals(matrixE) << endl;
    cout << "Matrix A equals Matrix F: " << matrixA->equals(matrixF) << endl;
    cout << "Matrix A equals Matrix G: " << matrixA->equals(matrixG) << endl;
    
    cout << "Matrix B equals Matrix B: " << matrixB->equals(matrixB) << endl;
    cout << "Matrix B equals Matrix C: " << matrixB->equals(matrixC) << endl;
    cout << "Matrix B equals Matrix D: " << matrixB->equals(matrixD) << endl;
    cout << "Matrix B equals Matrix E: " << matrixB->equals(matrixE) << endl;
    cout << "Matrix B equals Matrix F: " << matrixB->equals(matrixF) << endl;
    cout << "Matrix B equals Matrix G: " << matrixB->equals(matrixG) << endl;
    
    cout << "Matrix C equals Matrix C: " << matrixC->equals(matrixC) << endl;
    cout << "Matrix C equals Matrix D: " << matrixC->equals(matrixD) << endl;
    cout << "Matrix C equals Matrix E: " << matrixC->equals(matrixE) << endl;
    cout << "Matrix C equals Matrix F: " << matrixC->equals(matrixF) << endl;
    cout << "Matrix C equals Matrix G: " << matrixC->equals(matrixG) << endl;
    
    cout << "Matrix D equals Matrix D: " << matrixD->equals(matrixD) << endl;
    cout << "Matrix D equals Matrix E: " << matrixD->equals(matrixE) << endl;
    cout << "Matrix D equals Matrix F: " << matrixD->equals(matrixF) << endl;
    cout << "Matrix D equals Matrix G: " << matrixD->equals(matrixG) << endl;
    
    cout << "Matrix E equals Matrix E: " << matrixE->equals(matrixE) << endl;
    cout << "Matrix E equals Matrix F: " << matrixE->equals(matrixF) << endl;
    cout << "Matrix E equals Matrix G: " << matrixE->equals(matrixG) << endl;
    
    cout << "Matrix F equals Matrix F: " << matrixF->equals(matrixF) << endl;
    cout << "Matrix F equals Matrix G: " << matrixF->equals(matrixG) << endl;
    
    cout << "Matrix G equals Matrix G: " << matrixG->equals(matrixG) << endl;
    clock_t equalsMethodEnd = clock();
    
    clock_t addMatrixBegin = clock();
    //TEST 4: Add each matrix itself.
    cout << "Matrix A added to itself:" << endl;
    matrixA->add(matrixA)->print();
    cout << "\nMatrix B added to itself:" << endl;
    matrixB->add(matrixB)->print();
    cout << "\nMatrix C added to itself:" << endl;
    matrixC->add(matrixC)->print();
    cout << "\nMatrix D added to itself:" << endl;
    matrixD->add(matrixD)->print();
    cout << "\nMatrix E added to itself:" << endl;
    matrixE->add(matrixE)->print();
    cout << "\nMatrix F added to itself:" << endl;
    matrixF->add(matrixF)->print();
    cout << "\nMatrix G added to itself:" << endl;
    matrixG->add(matrixG)->print();
    clock_t addMatrixEnd = clock();
    
    clock_t subtractMatrixBegin = clock();
    //TEST 5: subtract each matrix itself.
    cout << "Matrix A subtracted to itself:" << endl;
    matrixA->subtract(matrixA)->print();
    cout << "\nMatrix B subtracted to itself:" << endl;
    matrixB->subtract(matrixB)->print();
    cout << "\nMatrix C subtracted to itself:" << endl;
    matrixC->subtract(matrixC)->print();
    cout << "\nMatrix D subtracted to itself:" << endl;
    matrixD->subtract(matrixD)->print();
    cout << "\nMatrix E subtracted to itself:" << endl;
    matrixE->subtract(matrixE)->print();
    cout << "\nMatrix F subtracted to itself:" << endl;
    matrixF->subtract(matrixF)->print();
    cout << "\nMatrix G subtracted to itself:" << endl;
    matrixG->subtract(matrixG)->print();
    clock_t subtractMatrixEnd = clock();
    
    clock_t scalarMultiplyMinus5Begin = clock();
    //test 6: Scalar multiply each matrix by 5 and subtract itself
    cout << "Matrix A subtracted from itself multiplied by 5:" << endl;
    matrixA->scalarMultiply(5)->subtract(matrixA)->print();
    cout << "\nMatrix B subtracted from itself multiplied by 5" << endl;
    matrixB->scalarMultiply(5)->subtract(matrixB)->print();
    cout << "\nMatrix C subtracted from itself multiplied by 5:" << endl;
    matrixC->scalarMultiply(5)->subtract(matrixC)->print();
    cout << "\nMatrix D subtracted from itself multiplied by 5:" << endl;
    matrixD->scalarMultiply(5)->subtract(matrixD)->print();
    cout << "\nMatrix E subtracted from itself multiplied by 5:" << endl;
    matrixE->scalarMultiply(5)->subtract(matrixE)->print();
    cout << "\nMatrix F subtracted from itself multiplied by 5:" << endl;
    matrixF->scalarMultiply(5)->subtract(matrixF)->print();
    cout << "\nMatrix G subtracted from itself multiplied by 5:" << endl;
    matrixG->scalarMultiply(5)->subtract(matrixG)->print();
    cout << endl;
    clock_t scalarMultiplyMinus5End = clock();
    
    clock_t multiplyTestBegin = clock();
//    Multiply Matrix A with itself, Matrix E with itself, and Matrix G with itself.
    cout << "Multiply matrix A with itself:" << endl;
    matrixA->multiply(matrixA)->print();
    cout << "Multiply matrix E with itself:" << endl;
    matrixE->multiply(matrixE)->print();
//    cout << "Multiply matrix G with itself:" << endl;
//    matrixG->multiply(matrixG)->print();
    clock_t multiplyTestEnd = clock();
    
    clock_t powerTestBegin = clock();
//    For Matrices A, E, and G raise each matrix to the power of 5, 25, 100 using power(). Print the result for each.
    cout << "Matrix A raised to power 5:" << endl;
    matrixA->power(5)->print();
    cout << "Matrix E raised to power 5:" << endl;
    matrixE->power(5)->print();
//    cout << "Matrix G raised to power 5:" << endl;
//    matrixG->power(5)->print();
    cout << "Matrix A raised to power 25:" << endl;
    matrixA->power(25)->print();
    cout << "Matrix E raised to power 25:" << endl;
    matrixE->power(25)->print();
//    cout << "Matrix G raised to power 25:" << endl;
//    matrixG->power(25)->print();
    cout << "Matrix A raised to power 100:" << endl;
    matrixA->power(100)->print();
//    cout << "Matrix E raised to power 100:" << endl;
//    matrixE->power(100)->print();
//    cout << "Matrix G raised to power 100:" << endl;
//    matrixG->power(100)->print();
    clock_t powerTestEnd = clock();
    
    clock_t transposeTestBegin = clock();
//   Compute the transpose of each matrix and print the result.
    cout << "Matrix A transposed:" << endl;
    matrixA->transpose()->print();
    cout << "Matrix B transposed:" << endl;
    matrixB->transpose()->print();
    cout << "Matrix C transposed:" << endl;
    matrixC->transpose()->print();
    cout << "Matrix D transposed:" << endl;
    matrixD->transpose()->print();
    cout << "Matrix E transposed:" << endl;
    matrixE->transpose()->print();
    cout << "Matrix F transposed:" << endl;
    matrixF->transpose()->print();
    cout << "Matrix G transposed:" << endl;
    matrixG->transpose()->print();
    cout << endl;
    clock_t transposeTestEnd = clock();
    
    clock_t transposeMultiplyBegin = clock();
//    Multiply each matrix with its transpose and its transpose with itself. Print the result for each.
    cout << "Matrix A transposed and multiplied with itself:" << endl;
    matrixA->multiply(matrixA->transpose())->print();
    cout << "Matrix B transposed and multiplied with itself:" << endl;
    matrixB->multiply(matrixB->transpose())->print();
    cout << "Matrix C transposed and multiplied with itself:" << endl;
    matrixC->multiply(matrixC->transpose())->print();
    cout << "Matrix D transposed and multiplied with itself:" << endl;
    matrixD->multiply(matrixD->transpose())->print();
    cout << "Matrix E transposed and multiplied with itself:" << endl;
    matrixE->multiply(matrixE->transpose())->print();
    cout << "Matrix F transposed and multiplied with itself:" << endl;
    matrixF->multiply(matrixF->transpose())->print();
    clock_t transposeMultiplyEnd = clock();
    
    cout << "Run times using Singly linked list datastructure: " << endl;
    
    cout << "Print Row Wise test: " << (double)(printTimeEnd - printTimeBegin) << endl;
    cout << "Print each matrix: " << (double)(printMatrixTimeEnd - printMatrixTimeBegin) << endl;
    cout << "Scalar multiply by 5 test: " << (double)(scalarMultiplyEnd - scalarMultiplyBegin) << endl;
    cout << "Equals method test: " << (double)(equalsMethodEnd - equalsMethodBegin) << endl;
    cout << "add matrix test: " << (double)(addMatrixEnd - addMatrixBegin) << endl;
    cout << "subtract matrix test: " << (double)(subtractMatrixEnd - subtractMatrixBegin) << endl;
    cout << "scalar multiply minus 5 test: " << (double)(scalarMultiplyMinus5End - scalarMultiplyMinus5Begin) << endl;
    cout << "power function test: " << (double)(powerTestEnd - powerTestBegin) << endl;
    cout << "Transpose test: " << (double)(transposeTestEnd - transposeTestBegin) << endl;
    cout << "transpose multiply test begin: " << (double)(transposeMultiplyEnd - transposeMultiplyBegin) << endl;
    return 0;
}
