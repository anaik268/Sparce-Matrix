#include "Array2DList.h"
#include <iostream>

Array2DList::Array2DList() {
	// TODO: init rowHeaders
    container = new ListEntry*[10]();
}

Array2DList::~Array2DList() {

}

bool Array2DList::rowEmpty(int i) {
    for(int k = 0; k < containerCount; k++)
    {
        if(container[k]->getRow() == i)
        {
            return false;
        }
    }
    
    return true;
}

bool Array2DList::colEmpty(int j) {
    for(int k = 0; k < containerCount; k++)
    {
        if(container[k]->getCol() == j)
        {
            return false;
        }
    }
    return true;
}

ListEntry* Array2DList::firstRowEntry(int i) {
    for(int k = 0; k < containerCount; k++)
    {
        if(container[k]->getRow() == i)
        {
            return container[k];
        }
    }
    return NULL;
}

ListEntry* Array2DList::firstColEntry(int j) {
    for(int k = 0; k < containerCount; k++)
    {
        if(container[k]->getCol() == j)
        {
            return container[k];
        }
    }
    return NULL;
}

ListEntry* Array2DList::nextRowEntry(ListEntry* e) {
    int curRow = e->getRow();
    int curCol = e->getCol();
    for(int k = 0; k < containerCount; k++)
    {
        if(container[k]->getRow() == curRow && container[k]->getCol() > curCol)
        {
            return container[k];
        }
    }
    return NULL;
    
}

ListEntry* Array2DList::nextColEntry(ListEntry* e) {
    int curCol = e->getCol();
    int curRow = e->getRow();
    for(int k = 0; k < containerCount; k++)
    {
        if(container[k]->getRow() > curRow && container[k]->getCol() == curCol)
        {
            return container[k];
        }
    }
    return NULL;
}

bool Array2DList::isLastEntryInRow(ListEntry* e) {
    if(nextRowEntry(e) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Array2DList::isLastEntryInCol(ListEntry* e) {
    if(nextColEntry(e) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
void Array2DList::insertValueAt(int value, int i, int j) {
    int row;
    int col;
    ListEntry* newEntry = new ListEntry(value, i, j);
    if(containerCount == containerCapacity)
    {
        increaseContainerSize();
    }
    if(containerCount == 0)
    {
        container[0] = newEntry;
    }
    else
    {
        for(int p = 0; p < containerCount; p++)
        {
            row = container[p]->getRow();
            col = container[p]->getCol();
            if(row == i)
            {
                if(col > j)
                {
                    for(int k = containerCount; k > p; k--)
                    {
                        container[k] = container[k-1];
                    }
                    container[p] = newEntry;
                }
                else
                {
                    continue;
                }
            }
            else if(row > i)
            {
                for(int k = containerCount; k > p; k--)
                {
                    container[k] = container[k-1];
                }
                container[p] = newEntry;
            }
            else
            {
                continue;
            }
        }
    }
    containerCount++;
    
}
*/
void Array2DList::insertValueAt(int value, int i, int j) {
    ListEntry* newEntry = new ListEntry(value, i, j);
    if(containerCount == containerCapacity)
    {
        increaseContainerSize();
    }
    container[containerCount] = newEntry;
    containerCount++;
    for(int p = 0; p < containerCount; p++)
    {
        if(container[p]->getRow() == i)
        {
            if(container[p]->getCol() > j)
            {
                for(int k = containerCount-1; k > p; k--)
                {
                    container[k] = container[k-1];
                }
                container[p] = newEntry;
            }
        }
        else if(container[p]->getRow() > i)
        {
            for(int k = containerCount-1; k > p; k--)
            {
                container[k] = container[k-1];
            }
            container[p] = newEntry;
        }
    }
}


void Array2DList::increaseContainerSize(){
    containerCapacity += 10;
    ListEntry** tempArray = container;
    container = new ListEntry*[containerCapacity]();
    for (int i = 0; i < containerCount; i++)
    {
        container[i] = tempArray[i];
    }
    delete [] tempArray;
}

void Array2DList::printArray(){
    for(int i = 0; i < containerCount; i++)
    {
        std::cout << "row: " << container[i]->getRow() << " col: " << container[i]->getCol()<< " value: " << container[i]->getValue() << std::endl;
    }
}