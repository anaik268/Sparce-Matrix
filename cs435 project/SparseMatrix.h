#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <String>
#include "ArrayOfLists2DList.h"

using std::string;

class SparseMatrix {

private:
    List2D * list;

public:
	SparseMatrix(int, int);
    SparseMatrix(const string&);
    ~SparseMatrix();

    void print();

	bool equals(const SparseMatrix*) const;
	SparseMatrix* scalarMultiply(const int) const;
    SparseMatrix* add(const SparseMatrix*) const;
    SparseMatrix* subtract(const SparseMatrix*) const;
    SparseMatrix* multiply(const SparseMatrix*) const;
    SparseMatrix* power(const int) const;
	SparseMatrix* transpose() const;
};

#endif
