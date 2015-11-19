#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <string>
#include "ArrayOfLists2DList.h"
#include "ListEntry.h"

using std::string;

class SparseMatrix {

private:
    List2D * list;
    int m;
    int n;

public:
	SparseMatrix(int, int);
    SparseMatrix(const string&);
    ~SparseMatrix();

    void print();
    void printRowWise();
    int getM();
    int getN();
    void setM(int);
    void setN(int);
    
    
	bool equals(const SparseMatrix*) const;
	SparseMatrix* scalarMultiply(const int) const;
    SparseMatrix* add(const SparseMatrix*) const;
    SparseMatrix* subtract(const SparseMatrix*) const;
    SparseMatrix* multiply(const SparseMatrix*) const;
    SparseMatrix* power(const int) const;
	SparseMatrix* transpose() const;
    int raiseTo(const int, const int) const;
    List2D* getList();
};

#endif
