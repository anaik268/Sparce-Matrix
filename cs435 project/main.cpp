//
//  main.cpp
//  cs435 project
//
//  Created by Abhishek Naik on 10/30/15.
//  Copyright (c) 2015 Abhishek Naik. All rights reserved.
//

#include <iostream>
#include <string>
#include "ArrayOfLists2DList.h"
#include "SparseMatrix.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ArrayOfLists2DList* something = new ArrayOfLists2DList(5);
    
//    something->insertValueAt(1,1,2);
//    something->insertValueAt(2,1,3);
//    something->insertValueAt(3,1,4);
//    something->insertValueAt(5,2,2);
//    something->insertValueAt(4,2,3);
//    something->insertValueAt(6,3,1);
//    something->insertValueAt(7,3,2);
//    something->insertValueAt(8,3,4);
//    something->insertValueAt(9,4,2);
//   
//    
//    
//    ListEntry* head2 = something->firstRowEntry(4);
//    
//    while (head2 != nullptr)
//    {
//        if(something->isLastEntryInRow(head2)){
//            cout  << "value: "<< head2->getValue()<< " row: " << head2->getRow() << " col: " << head2->getCol() << " -- last row" << endl;
//            head2 = something->nextRowEntry(head2);
//        }
//        else
//        {
//            cout  << "value: "<< head2->getValue()<< " row: " << head2->getRow() << " col: " << head2->getCol() << endl;
//            head2 = something->nextRowEntry(head2);
//        }
//
//    }
//
//    
//    cout << "\n\n now the column\n"<< endl;
//    ListEntry* head = something->firstColEntry(4);
//    
//    while (head != nullptr)
//    {
//        if(something->isLastEntryInCol(head)){
//            cout  << "value: "<< head->getValue()<< " row: " << head->getRow() << " col: " << head->getCol() << " -- last column" << endl;
//            head = something->nextColEntry(head);
//        }
//        else{
//            cout << "value: "<< head->getValue()<< " row: " << head->getRow() << " col: " << head->getCol() << endl;
//            head = something->nextColEntry(head);
//        }
//        
//    }
    
//    string sampleMatrix = "3r1c1,5r1c4,2r2c2,-7r2c3,5r3c1,-3r3c2,6r4c2,5r4c4";
//    string sampleMatrix2 = "3r1c1,5r1c4,2r2c2,-7r2c3,5r3c1,-3r3c2,6r4c2,5r4c4";
    
    
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
    
    
    matrixC->print();
    
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
    std::cout << "\nMatrix D:\n";
    matrixD->print();
    
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
    std::cout << "\nMatrix E:\n";
//    matrixE->print();
    
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
    std::cout << "\nMatrix F:\n";
//    matrixF->print();
    //formulating and inserting matrix G:
    //
//    for(int i = 1; i <= 30000; i++)
//    {
//        for(int j = 1; j <= 30000; j++){
//            if(random)%4 == 0)
//            {
//                matrixD->getList()->insertValueAt(i+j, i, j);
//            }
//        }
//    }
//    std::cout << "\nMatrix G:\n";
//    matrixG->print();
    

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

    
    return 0;
}
