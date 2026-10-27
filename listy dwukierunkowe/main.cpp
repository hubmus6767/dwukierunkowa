#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList list;

    std::cout << "--- TESTOWANIE LISTY DWUKIERUNKOWEJ ---" << std::endl;
    
    // 1. Dodawanie elementów
    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(5);
    list.displayForward();

    // 2. Dodawanie pod indeks
    list.insertAt(1, 7);
    list.displayForward(); // Oczekiwane: 5 7 10 20

    // 3. Wyświetlanie wstecz
    list.displayBackward(); // Oczekiwane: 20 10 7 5

    // 4. Usuwanie elementów
    list.popFront();
    list.displayForward(); // Oczekiwane: 7 10 20

    list.popBack();
    list.displayForward(); // Oczekiwane: 7 10

    list.pushBack(30);
    list.pushBack(40);
    list.displayForward(); // Oczekiwane: 7 10 30 40

    list.removeAt(2); // Usuwa element '30'
    list.displayForward(); // Oczekiwane: 7 10 40

    // 5. Testowanie iteratora (wyświetlanie następnego / poprzedniego elementu)
    std::cout << "\n--- TEST ITERATORA ---" << std::endl;
    ListIterator it = list.getIterator();
    std::cout << "Aktualny (poczatek): " << it.get() << std::endl;
    if (it.hasNext()) {
        std::cout << "Nastepny: " << it.next() << std::endl;
    }
    if (it.hasPrev()) {
        std::cout << "Poprzedni: " << it.prev() << std::endl;
    }

    // 6. Czyszczenie listy
    list.clear();
    std::cout << "Po wyczyszczeniu:" << std::endl;
    list.displayForward();

    return 0;
}