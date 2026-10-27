#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

#include "Node.h"

class ListFactory {
public:
    static Node* createNode(int value);
};

#endif