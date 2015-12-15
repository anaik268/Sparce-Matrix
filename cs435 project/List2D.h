#ifndef LIST2D_H
#define LIST2D_H

#include "ListEntry.h"

class List2D {

public:

    virtual ~List2D() { }

	virtual bool rowEmpty(int) = 0;
	virtual bool colEmpty(int) = 0;

	virtual ListEntry* firstRowEntry(int) = 0;
	virtual ListEntry* firstColEntry(int) = 0;

	virtual ListEntry* nextRowEntry(ListEntry*) = 0;
	virtual ListEntry* nextColEntry(ListEntry*) = 0;

	virtual bool isLastEntryInRow(ListEntry*) = 0;
	virtual bool isLastEntryInCol(ListEntry*) = 0;

	virtual void insertValueAt(int, int, int) = 0;
    virtual void printArray() = 0;
};

#endif
