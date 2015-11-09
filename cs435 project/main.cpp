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
    
    string sampleMatrix = "3r1c1,5r1c4,2r2c2,-7r2c3,5r3c1,-3r3c2,6r4c2,5r4c4";
    string sampleMatrix2 = "3r1c1,5r1c4,2r2c2,-7r2c3,5r3c1,-3r3c2,6r4c2,5r4c4";
    SparseMatrix* test = new SparseMatrix(sampleMatrix);
    test->print();
    SparseMatrix* equalsTest = new SparseMatrix(sampleMatrix2);
    equalsTest->print();
    cout << "They are equal: " << test->equals(equalsTest) << endl;
    SparseMatrix* scalarMultiplyTest = test->scalarMultiply(4);
    scalarMultiplyTest->print();
    cout << "\nthis is a add test:\n";
    SparseMatrix* addTest = test->add(equalsTest);
    addTest->print();
    
    cout << "\nthis is a subtract test:\n";
    SparseMatrix* subtractTest = test->subtract(equalsTest);
    subtractTest->print();
    
    
    return 0;
}
