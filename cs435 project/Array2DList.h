#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List2D.h"
#include "ListEntry.h"

class Array2DList : public List2D {

private:
    ListEntry** container;
    int containerCount = 0;
    int containerCapacity = 10;

public:
    Array2DList();
    ~Array2DList();

    bool rowEmpty(int);
	bool colEmpty(int);
	
	ListEntry* firstRowEntry(int);
	ListEntry* firstColEntry(int);
	
	ListEntry* nextRowEntry(ListEntry*);
	ListEntry* nextColEntry(ListEntry*);
	
	bool isLastEntryInRow(ListEntry*);
	bool isLastEntryInCol(ListEntry*);
	
	void insertValueAt(int, int, int);
    void increaseContainerSize();
};

#endif
