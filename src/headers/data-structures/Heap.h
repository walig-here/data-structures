#pragma once
#include "data-structures/DynamicArray.h"

// Klasa reprezentująca kopiec maksymalny
class Heap{

    /* POLA */
    private: DynamicArray elements;     // implementacja kopca w formie tablicy
    private: bool max_heap;             // czy kopiec jest maksymalny?

    /* METODY */

    // Konstruktor
    public: Heap(bool max_heap);

    // Destruktor
    public: ~Heap();

    // Wyświetlenie kopca
    public: void print();

    // Dodanie elementu
    public: void add(int new_element);

    // Usunięcie elementu:
    public: bool remove(int element_value);

    // Znalezienie elementu
    public: int* find();

    // Naprawa kopca za pomocą algorytmu Floyda
    private: void repair();

    // Pobranie lewego potomka
    private: int getLeftChild(unsigned index);

    // Pobranie prawego potomka
    private: int getRightChild(unsigned index);

    // Naprawienie węzła rodzic-potomkowie
    // Zwraca true, jeżeli wystąpiła zmaiana lub false, gdy nie wystąpiła
    private: bool repairNode(int &parent_index, int &left_child_index, int &right_child_index);

};

enum HeapActions{
    EXIT_HEAP,
    ADD_HEAP
};