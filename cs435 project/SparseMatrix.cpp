#include "SparseMatrix.h"

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
