#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

class ListIterator {
private:
    Node* current;
public:
    ListIterator(Node* start);
    bool hasNext() const;
    bool hasPrev() const;
    int next();
    int prev();
    int get() const;
    void set(int val);
    Node* getCurrent() const;
};

#endif