#include "ListEntry.h"

ListEntry::ListEntry(int value, int row, int col) {
    this->value = value;
	this->row = row;
	this->col = col;
}

void ListEntry::setValue(int value){
    this->value = value;
}

void ListEntry::setRow(int row)
{
    this->row = row;
}

void ListEntry::setCol(int col){
    this->col = col;
}

int ListEntry::getValue(){
    return this->value;
}

int ListEntry::getRow(){
    return this->row;
}

int ListEntry::getCol(){
    return this->col;
}

ListEntry* ListEntry::getEntry(){
    return this;
}

