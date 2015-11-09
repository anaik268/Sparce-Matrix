#include "SparseMatrix.h"
#include "ListEntry.h"
#include <iostream>
#include <sstream>

SparseMatrix::SparseMatrix(int m, int n) {
	this->list = new ArrayOfLists2DList(m);
    this->m = m;
    this-> n = n;
    
}

SparseMatrix::SparseMatrix(const string& str) {
    this->m = 4; // TODO: determine m, n based on inputs in str
    this->n = 4;
    std::istringstream ss(str);
    std::string token;
    std::string value;
    std::string row;
    std::string col;
    int testRow = 0;
    int testCol = 0;
    this->list = new ArrayOfLists2DList(m);
    while(std::getline(ss, token, ',')) {
        std::istringstream ss2(token);
        std::getline(ss2, value, 'r');
        std::getline(ss2, row, 'c');
        std::getline(ss2, col, ',');
//        std::cout << token << '\n';
        std::cout << "value: " << std::stoi(value) << " row: " << std::stoi(row) << " col: " << std::stoi(col) << std::endl;
        if(testRow < std::stoi(row))
        {
            testRow = std::stoi(row);
        }
        if(testCol < std::stoi(col))
        {
            testCol = std::stoi(col);
        }
        this->list->insertValueAt(std::stoi(value), std::stoi(row), std::stoi(col));
    }
    std::cout << "testRow: " << testRow  << " testCol: " << testCol << std::endl;
    this->n = testCol;
}

SparseMatrix::~SparseMatrix() {
    delete this->list;
}

void SparseMatrix::print(){
    ListEntry* head;
    for(int i = 1; i <= m; i++)
    {
        int curCol = 1;
        head = this->list->firstRowEntry(i);
        std::cout << "|";
        //check first if row is empty
        if(this->list->rowEmpty(i))
        {
            while(curCol <= n)
            {
                std::cout << " 0";
            }
            std::cout << " |\n";
            continue;
        }
        while(head != nullptr)
        {
            if(this->list->isLastEntryInRow(head))
            {
                while(curCol < head->getCol())
                {
                    std::cout << " 0";
                    curCol++;
                }
                std::cout << " " << head->getValue();
                curCol++;
                while(curCol <= n)
                {
                    std::cout << " 0";
                    curCol++;
                }
                head = this->list->nextRowEntry(head);
            }
            else if(curCol < head->getCol())
            {
                while(curCol < head->getCol())
                {
                    std::cout << " 0";
                    curCol++;
                }
                std::cout << " " << head->getValue();
                curCol++;
                head = this->list->nextRowEntry(head);
            }
            else
            {
                std::cout << " " << head->getValue();
                curCol++;
                head = this->list->nextRowEntry(head);
            }
        }

        std::cout << " |" << std::endl;
    }
}

bool SparseMatrix::equals(const SparseMatrix* m2) const {
    for(int i = 1; i <= m; i++)
    {
        ListEntry* head1 = this->list->firstRowEntry(i);
        ListEntry* head2 = m2->list->firstRowEntry(i);
        
        while(head1 != nullptr && head2 != nullptr)
        {
            if (head1->getValue() == head2->getValue() && head1->getCol() == head2->getCol()) {
                head1 = this->list->nextRowEntry(head1);
                head2 = this->list->nextRowEntry(head2);
            }
            else{
                return false;
            }
        }
    }
    return true;
}

SparseMatrix* SparseMatrix::scalarMultiply(const int c) const {
    SparseMatrix* tempMatrix = new SparseMatrix(m, n);
    for(int i = 1; i <= m; i++)
    {
        ListEntry* head = this->list->firstRowEntry(i);
        while(head != nullptr)
        {
            tempMatrix->list->insertValueAt(head->getValue() * c, i, head->getCol());
            head = this->list->nextRowEntry(head);
        }
    }
    return tempMatrix;
}

SparseMatrix* SparseMatrix::add(const SparseMatrix* m2) const {
    SparseMatrix* tempMatrix = new SparseMatrix(m,n);
    for(int i = 1; i <= m; i++)
    {
        ListEntry* head1 = this->list->firstRowEntry(i);
        ListEntry* head2 = m2->list->firstRowEntry(i);
        if(this->list->rowEmpty(i))
        {
            while(head2 != nullptr)
            {
                tempMatrix->list->insertValueAt(head2->getValue(), head2->getRow(), head2->getCol());
                head2 = m2->list->nextRowEntry(head2);
            }
        }
        if(m2->list->rowEmpty(i))
        {
            while(head1 != nullptr)
            {
                tempMatrix->list->insertValueAt(head1->getValue(), head1->getRow(), head1->getCol());
                head1 = this->list->nextRowEntry(head1);
            }
        }
        while(head1 != nullptr)
        {
            if(head2 != nullptr)
            {
                if(head2->getCol() == head1->getCol())
                {
                    tempMatrix->list->insertValueAt(head1->getValue() + head2->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                    head2 = m2->list->nextRowEntry(head2);
                }
                else if(head2->getCol() < head1->getCol())
                {
                    while(head2->getCol() < head1->getCol())
                    {
                        tempMatrix->list->insertValueAt(head2->getValue(), i, head2->getCol());
                        head2 = m2->list->nextRowEntry(head2);
                    }
                }
                else
                {
                    tempMatrix->list->insertValueAt(head1->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                }
            }
            else {
                while(head1 != nullptr)
                {
                    tempMatrix->list->insertValueAt(head1->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                }
            }
        }
        
        while(head2 != nullptr)
        {
            tempMatrix->list->insertValueAt(head2->getValue(), i, head2->getCol());
            head2 = m2->list->nextRowEntry(head2);
        }
    }
    return tempMatrix;
}

SparseMatrix* SparseMatrix::subtract(const SparseMatrix* m2) const {
    SparseMatrix* tempMatrix = new SparseMatrix(m,n);
    for(int i = 1; i <= m; i++)
    {
        ListEntry* head1 = this->list->firstRowEntry(i);
        ListEntry* head2 = m2->list->firstRowEntry(i);
        if(this->list->rowEmpty(i))
        {
            while(head2 != nullptr)
            {
                tempMatrix->list->insertValueAt(head2->getValue() * -1, head2->getRow(), head2->getCol());
                head2 = m2->list->nextRowEntry(head2);
            }
        }
        if(m2->list->rowEmpty(i))
        {
            while(head1 != nullptr)
            {
                tempMatrix->list->insertValueAt(head1->getValue(), head1->getRow(), head1->getCol());
                head1 = this->list->nextRowEntry(head1);
            }
        }
        while(head1 != nullptr)
        {
            if(head2 != nullptr)
            {
                if(head2->getCol() == head1->getCol())
                {
                    tempMatrix->list->insertValueAt(head1->getValue() - head2->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                    head2 = m2->list->nextRowEntry(head2);
                }
                else if(head2->getCol() < head1->getCol())
                {
                    while(head2->getCol() < head1->getCol())
                    {
                        tempMatrix->list->insertValueAt(head2->getValue() * -1, i, head2->getCol());
                        head2 = m2->list->nextRowEntry(head2);
                    }
                }
                else
                {
                    tempMatrix->list->insertValueAt(head1->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                }
            }
            else {
                while(head1 != nullptr)
                {
                    tempMatrix->list->insertValueAt(head1->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                }
            }
        }
        
        while(head2 != nullptr)
        {
            tempMatrix->list->insertValueAt(head2->getValue() * -1, i, head2->getCol());
            head2 = m2->list->nextRowEntry(head2);
        }
    }
    return nullptr;
}

SparseMatrix* SparseMatrix::multiply(const SparseMatrix* m2) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::power(const int p) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::transpose() const {
    return nullptr;
}

