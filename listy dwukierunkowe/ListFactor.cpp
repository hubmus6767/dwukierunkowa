#include "ListFactor.h"

Node* ListFactory::createNode(int value) {
    return new Node(value); 
}