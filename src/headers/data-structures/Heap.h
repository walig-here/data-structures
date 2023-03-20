#include "data-structures/DynamicArray.h"

// Klasa reprezentująca kopiec
class Heap{

    /* POLA */
    private: DynamicArray elements;     // implementacja kopca w formie tablicy

    /* METODY */

    // Konstruktor
    public: Heap();

    // Destruktor
    public: ~Heap();

    // Wyświetlenie kopca
    public: void print();

    // Dodanie elementu
    public: void add(int new_element);

    // Usunięcie elementu:
    public: bool remove(int element_value);

    // Znalezienie elementu
    private: int* find();

};

enum HeapActions{
    EXIT_HEAP
};