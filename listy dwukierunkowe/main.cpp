#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList list;

    std::cout << "--- TESTOWANIE LISTY DWUKIERUNKOWEJ ---" << std::endl;
    
    
    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(5);
    list.displayForward(); 

   
    list.insertAt(1, 7);
    list.displayForward(); 

    
    list.displayBackward(); 

    
    list.popFront();
    list.displayForward(); 

    list.popBack();
    list.displayForward(); 

    list.pushBack(30);
    list.pushBack(40);
    list.displayForward(); 

    list.removeAt(2);
    list.displayForward(); 

    
    std::cout << "\n--- TEST ITERATORA ---" << std::endl;
    ListIterator it = list.getIterator();
    std::cout << "Aktualny (poczatek): " << it.get() << std::endl;
    if (it.hasNext()) {
        std::cout << "Nastepny: " << it.next() << std::endl;
    }
    if (it.hasPrev()) {
        std::cout << "Poprzedni: " << it.prev() << std::endl;
    }

    
    list.clear();
    std::cout << "Po wyczyszczeniu:" << std::endl;
    list.displayForward();

    return 0;
}