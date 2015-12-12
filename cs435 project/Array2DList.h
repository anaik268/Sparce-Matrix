#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List2D.h"
#include "ListEntry.h"

class Array2DList : public List2D {

private:
    ListEntry* rowHeaders;

public:
    Array2DList();
    ~Array2DList();

    bool rowEmpty(int);
	bool colEmpty(int);
	
	ListEntry* firstRowEntry(int);
	ListEntry* firstColEntry(int);
	
	ListEntry* nextRowEntry(const ListEntry*);
	ListEntry* nextColEntry(const ListEntry*);
	
	bool isLastEntryInRow(const ListEntry*);
	bool isLastEntryInCol(const ListEntry*);
	
	void insertValueAt(int, int, int);
};

#endif
