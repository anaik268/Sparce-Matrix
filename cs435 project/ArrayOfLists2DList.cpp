#include "ArrayOfLists2DList.h"
#include "ListEntry.h"

ArrayOfLists2DList::ArrayOfLists2DList(int rows) {
    rowHeaders = new SLLListEntry*[rows];
}

ArrayOfLists2DList::~ArrayOfLists2DList() {
    
}

//void ArrayOfLists2DList::setRowHeaders(SLLListEntry* newHeader) {
//    this->rowHeaders = newHeader;
//}
//SLLListEntry* ArrayOfLists2DList::getRowHeaders(){
//    return this->rowHeaders;
//}

bool ArrayOfLists2DList::rowEmpty(int i) {
    SLLListEntry* head = rowHeaders[i-1];
    if(head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ArrayOfLists2DList::colEmpty(int j) {
    return false;
}

ListEntry* ArrayOfLists2DList::firstRowEntry(int i) {
    SLLListEntry* head = rowHeaders[i-1];
    if(head == nullptr)
    {
        return nullptr;
    }
    else
    {
        return head->getEntry();
    }
}

ListEntry* ArrayOfLists2DList::firstColEntry(int j) {
    return nullptr;
}

ListEntry* ArrayOfLists2DList::nextRowEntry(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    if(entry->getNext() != nullptr)
    {
        return entry->getNext()->getEntry();
    }
    else
    {
        return nullptr;
    }
}

ListEntry* ArrayOfLists2DList::nextColEntry(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    return nullptr;
}

bool ArrayOfLists2DList::isLastEntryInRow(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    return false;
}

bool ArrayOfLists2DList::isLastEntryInCol(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    return false;
}

void ArrayOfLists2DList::insertValueAt(int value, int i, int j) {
    SLLListEntry* head = rowHeaders[i-1];
    
    if(head == nullptr)
    {
        rowHeaders[i-1] = new SLLListEntry(value, i, j, nullptr);
    }
    else
    {
        SLLListEntry* newEntry = new SLLListEntry(value, i, j, nullptr);
        
        while(head->getNext() != nullptr && head->getNext()->getCol() < j)
        {
            head = head->getNext();
        }
        
        if(head->getNext() != nullptr)
        {
            newEntry->setNext(head->getNext());
            head->setNext(newEntry);
        }
        else
        {
            head->setNext(newEntry);
        }
    }
}



