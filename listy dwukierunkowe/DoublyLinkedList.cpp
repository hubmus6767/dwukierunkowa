#include "DoublyLinkedList.h"
#include "ListFactor.h"
#include <iostream>
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::pushFront(int value) {
    Node* newNode = ListFactory::createNode(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::pushBack(int value) {
    Node* newNode = ListFactory::createNode(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::insertAt(size_t index, int value) {
    if (index > size) throw std::out_of_range("Indeks poza zakresem.");
    if (index == 0) {
        pushFront(value);
        return;
    }
    if (index == size) {
        pushBack(value);
        return;
    }

    Node* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    Node* newNode = ListFactory::createNode(value);
    Node* prevNode = current->prev;

    prevNode->next = newNode;
    newNode->prev = prevNode;

    newNode->next = current;
    current->prev = newNode;

    size++;
}

void DoublyLinkedList::popFront() {
    if (!head) throw std::underflow_error("Lista jest pusta."); 
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::popBack() {
    if (!tail) throw std::underflow_error("Lista jest pusta.");
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::removeAt(size_t index) {
    if (index >= size) throw std::out_of_range("Indeks poza zakresem.");
    if (index == 0) {
        popFront();
        return;
    }
    if (index == size - 1) {
        popBack();
        return;
    }

    Node* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

void DoublyLinkedList::displayForward() const {
    Node* current = head;
    std::cout << "Lista (przod): ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::displayBackward() const {
    Node* current = tail;
    std::cout << "Lista (tyl): ";
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

size_t DoublyLinkedList::getSize() const {
    return size;
}

ListIterator DoublyLinkedList::getIterator() const {
    return ListIterator(head);
}

ListIterator DoublyLinkedList::getReverseIterator() const {
    return ListIterator(tail);
}