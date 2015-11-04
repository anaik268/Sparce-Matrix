#include "ArrayOfLists2DList.h"
#include "ListEntry.h"

ArrayOfLists2DList::ArrayOfLists2DList(int rows) {

}

ArrayOfLists2DList::~ArrayOfLists2DList() {
    
}

void ArrayOfLists2DList::setRowHeaders(SLLListEntry* newHeader) {
    this->rowHeaders = newHeader;
}
SLLListEntry* ArrayOfLists2DList::getRowHeaders(){
    return this->rowHeaders;
}

bool ArrayOfLists2DList::rowEmpty(int i) {
    
    return false;
}

bool ArrayOfLists2DList::colEmpty(int j) {
    return false;
}

ListEntry* ArrayOfLists2DList::firstRowEntry(int i) {
    return nullptr;
}

ListEntry* ArrayOfLists2DList::firstColEntry(int j) {
    return nullptr;
}

ListEntry* ArrayOfLists2DList::nextRowEntry(ListEntry* e) {
    SLLListEntry * entry = dynamic_cast<SLLListEntry*>(e);
    return nullptr;
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
    SLLListEntry* curPointer = rowHeaders;

}



