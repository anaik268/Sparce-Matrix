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
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Abhishek!\n";
    ArrayOfLists2DList* something = new ArrayOfLists2DList(6);
    
    something->insertValueAt(1, 1, 1);
    something->insertValueAt(2, 1, 2);
    something->insertValueAt(3, 1, 3);
    something->insertValueAt(4, 2, 3);
    something->insertValueAt(5, 2, 2);
    something->insertValueAt(6, 2, 1);
    something->insertValueAt(7, 3, 2);
    something->insertValueAt(8, 3, 3);
    something->insertValueAt(4, 4, 3);
    something->insertValueAt(7, 4, 4);
    something->insertValueAt(2, 3, 4);
//    something->insertValueAt(4, 2, 4);
//    something->insertValueAt(2, 4, 3);
//    something->insertValueAt(6, 5, 4);
//    something->insertValueAt(9, 5, 2);
//    something->insertValueAt(2, 5, 1);
//    something->insertValueAt(1, 5, 3);
    something->insertValueAt(9, 6, 3);
    
    
//    ListEntry* head = something->firstRowEntry(2);
//    
//    while (head != nullptr)
//    {
//        cout  << "value: "<< head->getValue()<< " row: " << head->getRow() << " col: " << head->getCol() << endl;
//        head = something->nextRowEntry(head);
//    }

    ListEntry* head = something->firstColEntry(4);
    
    while (head != nullptr)
    {
        cout << "row: " << head->getRow() << " col: " << head->getCol() << " value: "<< head->getValue() << endl;
        head = something->nextColEntry(head);
    }
    
    if(head != nullptr){
        cout << "row: " << head->getRow() << " col: " << head->getCol() << " value: "<< head->getValue() << endl;
    }
    
    std::string sampleMatrix = "3r1c1, 5r1c4, 2r2c2, -7r2c3, 5r3c1, -3r3c2, 6r4c2, -5r4c4";
    
    return 0;
}
