#include "ArrayOfLists2DList.h"
#include "ListEntry.h"

ArrayOfLists2DList::ArrayOfLists2DList(int rows) {
    rowHeaders = new SLLListEntry*[rows]();
//    for (int i = 0; i < rows; i++)
//    {
//        rowHeaders[i] = nullptr;
//    }
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
    if(rowHeaders[i-1] == nullptr)
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
    SLLListEntry* head = rowHeaders[0];
    while(head->getEntry()->getCol() != j && head->getNext() != nullptr)
    {
        head = head->getNext();
    }
    if(head->getEntry()->getCol() != j)
    {
        return nullptr;
    }
    else {
        return head;
    }
   
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
    SLLListEntry * head = rowHeaders[entry->getRow()];
    while(head->getNext() != nullptr && head->getCol() < entry->getCol())
    {
        head = head->getNext();
    }
    if(head->getCol() == entry->getCol())
    {
        return head->getEntry();
    }
    else
    {
        return (new ListEntry(0, entry->getRow()+1, entry->getCol()+1));
    }
}

bool ArrayOfLists2DList::isLastEntryInRow(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    if(entry->getNext() == nullptr)
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
//    SLLListEntry * nextEntry = dynamic_cast<SLLListEntry*>(nextColEntry(e));
    return false;
}
void ArrayOfLists2DList::insertValueAt(int value, int i, int j) {
    SLLListEntry* newEntry = new SLLListEntry(value, i, j, nullptr);
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
        while(head->getNext() != nullptr && head->getNext()->getCol() < j)
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
        if(head->getNext() == nullptr)
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



