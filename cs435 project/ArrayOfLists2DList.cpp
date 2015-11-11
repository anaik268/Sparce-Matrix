#include "ArrayOfLists2DList.h"
#include "ListEntry.h"
#include <iostream>

ArrayOfLists2DList::ArrayOfLists2DList(int rows) {
    rowHeaders = new SLLListEntry*[rows]();
    rowHeadersSize = rows;
}

ArrayOfLists2DList::~ArrayOfLists2DList() {
    
}

bool ArrayOfLists2DList::rowEmpty(int i) {
    if(rowHeaders[i-1] == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ArrayOfLists2DList::colEmpty(int j) {
    if(firstColEntry(j) != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }

}

ListEntry* ArrayOfLists2DList::firstRowEntry(int i) {
    SLLListEntry* head = rowHeaders[i-1];
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        return head->getEntry();
    }
}

ListEntry* ArrayOfLists2DList::firstColEntry(int j) {
    
    for (int i = 0; i < rowHeadersSize; i++)
    {
        if(rowEmpty(i+1))
        {
            continue;
        }
        SLLListEntry* head = rowHeaders[i];
        while(head != NULL && head->getCol() < j)
        {
            head = head->getNext();
        }
        if(head == NULL || head->getCol() > j)
        {
            continue;
        }
        if(head->getCol() == j)
        {
            return head;
        }
    }
    return NULL;
   
}

ListEntry* ArrayOfLists2DList::nextRowEntry(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    if(entry->getNext() != NULL)
    {
        return entry->getNext()->getEntry();
    }
    else
    {
        return NULL;
    }
}

ListEntry* ArrayOfLists2DList::nextColEntry(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    
    for (int i = entry->getRow(); i < rowHeadersSize; i++)
    {
        if(rowEmpty(i+1))
        {
            continue;
        }
        SLLListEntry* head = rowHeaders[i];
        while(head != NULL && head->getCol() < entry->getCol())
        {
            head = head->getNext();
        }
        if(head == NULL || head->getCol() > entry->getCol())
        {
            continue;
        }
        if(head->getCol() == entry->getCol())
        {
            return head;
        }
    }
    return NULL;
    
}

bool ArrayOfLists2DList::isLastEntryInRow(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    if(entry->getNext() == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ArrayOfLists2DList::isLastEntryInCol(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    if(nextColEntry(e) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ArrayOfLists2DList::insertValueAt(int value, int i, int j) {
    SLLListEntry* newEntry = new SLLListEntry(value, i, j, NULL);
    SLLListEntry* head = rowHeaders[i-1];
    if(rowEmpty(i))
    {
        rowHeaders[i-1] = newEntry;
    }
    else if(head->getCol() > j)
    {
        newEntry->setNext(head);
        rowHeaders[i-1] = newEntry;
    }
    else
    {
        while(head->getNext() != NULL && head->getNext()->getCol() < j)
        {
            if(head->getCol() < j)
            {
                head = head->getNext();
            }
            else
            {
                break;
            }
        }
        if(head->getNext() == NULL)
        {
            head->setNext(newEntry);
        }
        else if(head->getNext()->getCol() > j)
        {
            newEntry->setNext(head->getNext());
            head->setNext(newEntry);
        }
    }
}



