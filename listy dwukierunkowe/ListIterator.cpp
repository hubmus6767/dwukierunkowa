#include "ListIterator.h"
#include <stdexcept>

ListIterator::ListIterator(Node* start) : current(start) {}

bool ListIterator::hasNext() const {
    return current != nullptr && current->next != nullptr;
}

bool ListIterator::hasPrev() const {
    return current != nullptr && current->prev != nullptr;
}

int ListIterator::next() {
    if (!hasNext()) throw std::out_of_range("Brak nastepnego elementu.");
    current = current->next;
    return current->data;
}

int ListIterator::prev() {
    if (!hasPrev()) throw std::out_of_range("Brak poprzedniego elementu.");
    current = current->prev;
    return current->data;
}

int ListIterator::get() const {
    if (!current) throw std::runtime_error("Iterator wskazuje na nullptr.");
    return current->data;
}

void ListIterator::set(int val) {
    if (!current) throw std::runtime_error("Iterator wskazuje na nullptr.");
    current->data = val;
}

Node* ListIterator::getCurrent() const {
    return current;
}