#include "SLLListEntry.h"

SLLListEntry::SLLListEntry(int value, int row, int col, SLLListEntry * next) : ListEntry(value, row, col) {
	this->next = next;
}

void SLLListEntry::setNext(SLLListEntry* next){
    this->next = next;
}

SLLListEntry* SLLListEntry::getNext(){
    return this->next;
}

ListEntry* SLLListEntry::getEntry(){
    return ListEntry::getEntry();
}

