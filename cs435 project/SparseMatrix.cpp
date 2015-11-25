#include "SparseMatrix.h"
#include "ListEntry.h"
#include <iostream>
#include <sstream>
#include <vector>

SparseMatrix::SparseMatrix(int m, int n) {
	this->list = new ArrayOfLists2DList(m);
    this->m = m;
    this->n = n;
    
}

SparseMatrix::SparseMatrix(const string& str) {
    std::vector<string> eachItem;
    std::istringstream ss(str);
    std::string token;
    std::string value;
    std::string row;
    std::string col;

    while(std::getline(ss, token, ',')) {
        eachItem.push_back(token);
        std::istringstream ss2(token);
        std::getline(ss2, value, 'r');
        std::getline(ss2, row, 'c');
        std::getline(ss2, col, ',');
        if(this->m < std::stoi(row))
        {
            this->m = std::stoi(row);
        }
        if(this->n < std::stoi(col))
        {
            this->n = std::stoi(col);
        }
    }
    this->list = new ArrayOfLists2DList(m);
    for (int i = 0; i < eachItem.size(); i++)
    {
        token = eachItem[i];
        std::istringstream ss2(token);
        std::getline(ss2, value, 'r');
        std::getline(ss2, row, 'c');
        std::getline(ss2, col, ',');
        this->list->insertValueAt(std::stoi(value), std::stoi(row), std::stoi(col));
    }
    
    std::cout << "\n";
}

SparseMatrix::~SparseMatrix() {
    delete this->list;
}

List2D* SparseMatrix::getList()
{
    return this->list;
}

int SparseMatrix::getM() const
{
    return this->m;
}

int SparseMatrix::getN() const
{
    return this->n;
}

int SparseMatrix::raiseTo(const int value, const int power) const
{
//    if(power == 1)
//    {
//        return 
//    }
    int result = 1;
    for (int i = 0; i < power; i++)
        result *= value;
    return result;
}
void SparseMatrix::printRowWise() {
    ListEntry* head;
    for(int i = 1; i <= m; i++)
    {
        if(m > 6 && i == 4)
        {
            i = m-3;
            continue;
        }
        std::cout << "Row" << i << ": ";
        head = this->list->firstRowEntry(i);
        while(head != NULL)
        {
            std::cout << head->getValue() << " ";
            head = this->list->nextRowEntry(head);
        }
        std::cout << std::endl;
    }
}
void SparseMatrix::print(){
    ListEntry* head;
    for(int i = 1; i <= m; i++)
    {
        if(m > 6 && i == 4)
        {
            std::cout << "    ......." << std::endl;
            i = m-3;
            continue;
        }
        int curCol = 1;
        head = this->list->firstRowEntry(i);
        std::cout << "|";
        //check first if row is empty
        if(this->list->rowEmpty(i))
        {
            while(curCol <= n)
            {
                if(n > 6 && curCol == 4)
                {
                    std::cout << " ...";
                    curCol = n-2;
                    continue;
                }
                else {
                    std::cout << " 0";
                    curCol++;
                }
                
            }
            std::cout << " |\n";
            continue;
        }
        while(head != NULL)
        {
            if(n > 6 && curCol == 4)
            {
                std::cout << " ...";
                curCol = n-2;
                continue;
            }
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
                while(curCol < head->getCol() && curCol != 3)
                {
                    std::cout << " 0";
                    curCol++;
                }
                if(curCol == 3)
                {
                    std::cout << " 0";
                    curCol++;
                    continue;
                }
                std::cout << " " << head->getValue();
                curCol++;
                head = this->list->nextRowEntry(head);
            }
            else if(curCol > head->getCol())
            {
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
    if(m != m2->getM() || n != m2->getN())
    {
        return false;
        
    }
    for(int i = 1; i <= m; i++)
    {
        ListEntry* head1 = this->list->firstRowEntry(i);
        ListEntry* head2 = m2->list->firstRowEntry(i);
        
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->getCol() > head2->getCol())
            {
                return false;
            }
            if(head1->getCol() < head2->getCol())
            {
                return false;
            }
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
        while(head != NULL)
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
            while(head2 != NULL)
            {
                tempMatrix->list->insertValueAt(head2->getValue(), head2->getRow(), head2->getCol());
                head2 = m2->list->nextRowEntry(head2);
            }
        }
        if(m2->list->rowEmpty(i))
        {
            while(head1 != NULL)
            {
                tempMatrix->list->insertValueAt(head1->getValue(), head1->getRow(), head1->getCol());
                head1 = this->list->nextRowEntry(head1);
            }
        }
        while(head1 != NULL)
        {
            if(head2 != NULL)
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
                while(head1 != NULL)
                {
                    tempMatrix->list->insertValueAt(head1->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                }
            }
        }
        
        while(head2 != NULL)
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
            while(head2 != NULL)
            {
                tempMatrix->list->insertValueAt(head2->getValue() * -1, head2->getRow(), head2->getCol());
                head2 = m2->list->nextRowEntry(head2);
            }
        }
        if(m2->list->rowEmpty(i))
        {
            while(head1 != NULL)
            {
                tempMatrix->list->insertValueAt(head1->getValue(), head1->getRow(), head1->getCol());
                head1 = this->list->nextRowEntry(head1);
            }
        }
        while(head1 != NULL)
        {
            if(head2 != NULL)
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
                while(head1 != NULL)
                {
                    tempMatrix->list->insertValueAt(head1->getValue(), i, head1->getCol());
                    head1 = this->list->nextRowEntry(head1);
                }
            }
        }
        
        while(head2 != NULL)
        {
            tempMatrix->list->insertValueAt(head2->getValue() * -1, i, head2->getCol());
            head2 = m2->list->nextRowEntry(head2);
        }
    }
    return tempMatrix;
}

SparseMatrix* SparseMatrix::multiply(const SparseMatrix* m2) const {
    SparseMatrix* tempMatrix = new SparseMatrix(m,m2->n);
    ListEntry* head1;
    ListEntry* head2;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m2->n; j++)
        {
            head1 = this->list->firstRowEntry(i);
            head2 = m2->list->firstColEntry(j);
            int sum = 0;
            
            while(head2 != NULL && head1 != NULL)
            {
                if(head1->getCol() == head2->getRow())
                {
                    sum += head1->getValue() * head2->getValue();
                    head2 = m2->list->nextColEntry(head2);
                    head1 = this->list->nextRowEntry(head1);
                }
                else if(head1->getCol() < head2->getRow())
                {
                    head1 = this->list->nextRowEntry(head1);
                }
                else if(head2->getRow() < head1->getCol())
                {
                    head2 = m2->list->nextColEntry(head2);
                }
            }
            if (sum != 0)
            {
                tempMatrix->list->insertValueAt(sum, i, j);
            }
            
        }
    }
    return tempMatrix;
}

SparseMatrix* SparseMatrix::power(const int p) const {
    SparseMatrix* tempMatrix = new SparseMatrix(m, n);
    ListEntry* head;
    for(int i = 1; i <= m; i++)
    {
        head = this->list->firstRowEntry(i);
        while(head != NULL)
        {
            int num = raiseTo(head->getValue(), p);
            tempMatrix->list->insertValueAt(num, head->getRow(), head->getCol());
            head = this->list->nextRowEntry(head);
        }
        
        
    }
    
    return tempMatrix;
}

SparseMatrix* SparseMatrix::transpose() const {
    SparseMatrix* tempMatrix = new SparseMatrix(n,m);
    ListEntry* head;
    for(int i = 1; i <= m; i++)
    {
        head = this->list->firstRowEntry(i);
        while(head != NULL)
        {
            tempMatrix->list->insertValueAt(head->getValue(), head->getCol(), head->getRow());
            head = this->list->nextRowEntry(head);
        }
        
    }
    
    return tempMatrix;
}

