#pragma once
#include "data-structures/DynamicArray.h"
#include <math.h>

// Klasa reprezentująca kopiec maksymalny
class Heap{

    /* POLA */
    private: DynamicArray elements;     // implementacja kopca w formie tablicy

    /* METODY */

    // Konstruktor
    public: Heap();

    // Konstruktor. Bujuje kopiec ciągu liczb
    public: Heap(vector<int> new_elements);
    

    // Konstruktor kopiujący.
    public: Heap(Heap* copy);


    // Destruktor
    public: ~Heap();

    // Wyświetlenie kopca
    public: void print();

    // Dodanie elementu
    public: void add(int new_element);

    // Usunięcie korzenia:
    public: bool pop_root();

    // Znalezienie elementu
    public: int* find(int value);

    // Naprawa kopca za pomocą algorytmu Floyda
    private: void buildHeapFloyd();

    // Pobranie lewego potomka
    #define LEFT_CHILD_INDEX(i) (2 * i + 1)
    private: int* getLeftChild(unsigned index) { return elements[LEFT_CHILD_INDEX(index)]; }

    // Pobranie prawego potomka
    #define RIGHT_CHILD_INDEX(i) (2 * i + 2)  
    private: int* getRightChild(unsigned index) { return elements[RIGHT_CHILD_INDEX(index)]; }

    // Pobranie rodzica
    #define PARENT_INDEX(i) ( floor( (i - 1)/2 ) )
    private: int* getParent(unsigned index) { return elements[PARENT_INDEX(index)]; };

    // Pobranie tablicy elementów
    public: DynamicArray getElements() { return elements; }

    // Naprawa kopca w dół
    private: void repairDownwards(unsigned node_index);

    // Naprawa kopca w górę
    private: void repairUpwards(unsigned node_index);

    // Pobranie potomka o największej wartości
    private: int getMaxChildIndex(unsigned node_index);
    #define IS_LEAF -123

    // Pobranie korzenia
    public: int* root() { return elements[0]; }

};

enum HeapActions{
    EXIT_HEAP,
    ADD_HEAP,
    REMOVE_HEAP,
    FIND_HEAP,
    LOAD_HEAP
};