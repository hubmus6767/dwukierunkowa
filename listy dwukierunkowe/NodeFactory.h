#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "Node.h"



template <typename T>
class NodeFactory {
public:
    
    static Node<T>* createNode(T val) {
        return new Node<T>(val);
    }
};

#endif 