#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>
#include "Node.h"
#include "ListIterator.h"

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void pushFront(int value);
    void pushBack(int value);
    void insertAt(size_t index, int value);
    
    void popFront();
    void popBack();
    void removeAt(size_t index);
    
    void displayForward() const;
    void displayBackward() const;
    
    void clear();
    size_t getSize() const; 

    ListIterator getIterator() const;
    ListIterator getReverseIterator() const;
};

#endif