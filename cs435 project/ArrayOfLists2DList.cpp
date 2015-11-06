#include "ArrayOfLists2DList.h"
#include "ListEntry.h"
#include <iostream>

ArrayOfLists2DList::ArrayOfLists2DList(int rows) {
    rowHeaders = new SLLListEntry*[rows]();
    rowHeadersSize = rows;
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
    if(firstColEntry(j) != nullptr)
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
    
    for (int i = 0; i < rowHeadersSize; i++)
    {
        if(rowEmpty(i+1))
        {
            continue;
        }
        SLLListEntry* head = rowHeaders[i];
        while(head != nullptr && head->getCol() < j)
        {
            head = head->getNext();
        }
        if(head == nullptr || head->getCol() > j)
        {
            continue;
        }
        if(head->getCol() == j)
        {
            return head;
        }
    }
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
    
    for (int i = entry->getRow(); i < rowHeadersSize; i++)
    {
//        std::cout << i << " rowHeadersSize: " << rowHeadersSize << std::endl;
        if(rowEmpty(i+1))
        {
            continue;
        }
        SLLListEntry* head = rowHeaders[i];
        while(head != nullptr && head->getCol() < entry->getCol())
        {
            head = head->getNext();
        }
        if(head == nullptr || head->getCol() > entry->getCol())
        {
            continue;
        }
        if(head->getCol() == entry->getCol())
        {
//            std::cout << "row: " << head->getRow() << " col: " << head->getCol() << " value: "<< head->getValue() << std::endl;
            return head;
        }
    }
    return nullptr;
    
}
//ListEntry* ArrayOfLists2DList::nextColEntry(ListEntry* e) {
//    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
//    if(e->getRow() == rowHeadersSize-1)
//    {
//        return nullptr;
//    }
//    SLLListEntry * head = rowHeaders[entry->getRow()];
//    
//    while(head != nullptr && head->getCol() < entry->getCol())
//    {
//        head = head->getNext();
//    }
//    if(head->getCol() == entry->getCol())
//    {
//        return head->getEntry();
//    }
//    else if(head->getCol() > entry->getCol())
//    {
//        return nextColEntry(new ListEntry(0, entry->getRow()+1, entry->getCol()+1));
//    }
//    else
//    {
//        return nullptr;
//    }
//}

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
    if(entry->getRow() == rowHeadersSize-1)
    {
        return true;
    }
    else
    {
        return false;
    }
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



