#ifndef NODE_H
#define NODE_H



template <typename T>
class Node {
private:
    T data;
    Node* next;
    Node* prev;

public:
    
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}

    
    T getData() const { return data; }
    void setData(T val) { data = val; }

    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }

    Node* getPrev() const { return prev; }
    void setPrev(Node* p) { prev = p; }
};

#endif 