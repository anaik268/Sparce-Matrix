#include "SparseMatrix.h"
#include "ListEntry.h"
#include <iostream>

SparseMatrix::SparseMatrix(int m, int n) {
	this->list = new ArrayOfLists2DList(m);
    
}

SparseMatrix::SparseMatrix(const string& str) {
	int m = 0; // TODO: determine m, n based on inputs in str

	this->list = new ArrayOfLists2DList(m);
}

SparseMatrix::~SparseMatrix() {
    delete this->list;
}

void SparseMatrix::print(){
    ListEntry* head;
    for(int i = 1; i < m; i++)
    {
        head = this->list->firstRowEntry(i);
        std::cout << "| ";
        for(int j = 1; j < n; j++)
        {
            if(head->getCol() == j)
            {
                std::cout << head->getCol() << " ";
            }
            else
            {
                if(head->getCol() > j)
                {
                    while (head->getCol() != j) {
                        std::cout << "0 ";
                        j++;
                    }
                }
            }
            head = this->list->nextRowEntry(head);
        }
        std::cout << "|" << std::endl;
    }
}

bool SparseMatrix::equals(const SparseMatrix* m) const {
    return false;
}

SparseMatrix* SparseMatrix::scalarMultiply(const int c) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::add(const SparseMatrix* m) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::subtract(const SparseMatrix* m) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::multiply(const SparseMatrix* m) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::power(const int p) const {
    return nullptr;
}

SparseMatrix* SparseMatrix::transpose() const {
    return nullptr;
}
