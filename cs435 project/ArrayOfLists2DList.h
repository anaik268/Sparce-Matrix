#ifndef DLLPROJECTLIST_H
#define DLLPROJECTLIST_H

#include "List2D.h"
#include "SLLListEntry.h"

class ArrayOfLists2DList : public List2D {

private:
    SLLListEntry** rowHeaders;
public:
    ArrayOfLists2DList(int);
    ~ArrayOfLists2DList();
    
    void setRowHeaders(SLLListEntry*);
    SLLListEntry* getRowHeaders();
    
    bool rowEmpty(int);
	bool colEmpty(int);

	ListEntry* firstRowEntry(int);
	ListEntry* firstColEntry(int);

	ListEntry* nextRowEntry(ListEntry*);
	ListEntry* nextColEntry(ListEntry*);

	bool isLastEntryInRow(ListEntry*);
	bool isLastEntryInCol(ListEntry*);

	void insertValueAt(int, int, int);
};

#endif
