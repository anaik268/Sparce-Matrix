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
                matrixD->getList()->insertValueAt(i+j, i, j);
            }
        }
    }
    

    //Performing the tests:
    //
    //TEST 1: print each value rowWise
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
//    matrixG->printRowWise();
    
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
//    matrixG->print();
    
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
//    matrixG->scalarMultiply(5)->print();

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
//    matrixG->add(matrixG)->print();
    
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
//    matrixG->subtract(matrixG)->print();
    
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
//    matrixG->scalarMultiply(5)->subtract(matrixG)->print();
    

    
    
    return 0;
}
