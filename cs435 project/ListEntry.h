#ifndef LISTENTRY_H
#define LISTENTRY_H

class ListEntry {

private:
    int value;
	int row;
	int col;

public:
    ListEntry(int, int, int);
    
    virtual ~ListEntry() { };
    
    void setValue(int value);
    void setRow(int row);
    void setCol(int col);
    int getValue();
    int getRow();
    int getCol();
};

#endif
