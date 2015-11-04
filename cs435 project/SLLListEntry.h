#ifndef SLLLISTENTRY_H
#define SLLLISTENTRY_H

#include "ListEntry.h"

class SLLListEntry : public ListEntry {

private:
    SLLListEntry * next;

public:
    SLLListEntry(int, int, int, SLLListEntry*);
    void setNext(SLLListEntry* next);
    SLLListEntry* getNext();
    ListEntry* getEntry();
};

#endif


