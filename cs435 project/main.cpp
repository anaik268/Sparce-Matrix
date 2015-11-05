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
    ArrayOfLists2DList* something = new ArrayOfLists2DList(5);
    something->insertValueAt(2, 1, 1);
    something->insertValueAt(5, 1, 4);
    something->insertValueAt(9, 1, 2);
    something->insertValueAt(3, 2, 2);
    something->insertValueAt(4, 1, 3);
    ListEntry* head = something->firstRowEntry(1);
    
    while (something->nextRowEntry(head) != nullptr)
    {
        cout << "row: " << head->getRow() << " col: " << head->getCol() << " value: "<< head->getValue() << endl;
        head = something->nextRowEntry(head);
    }
    
    cout << "row: " << head->getRow() << " col: " << head->getCol() << " value: "<< head->getValue() << endl;
    std::string sampleMatrix = "3r1c1, 5r1c4, 2r2c2, -7r2c3, 5r3c1, -3r3c2, 6r4c2, -5r4c4";
    
    return 0;
}
