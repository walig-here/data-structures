#pragma once
#include "data-structures/DynamicArray.h"
#include <math.h>

// Klasa reprezentująca kopiec maksymalny
class Heap{

    /* POLA */
    private: DynamicArray elements;     // implementacja kopca w formie tablicy

    /* METODY */

    //-----------------------------------------------------------------------
    // Konstruktor. Tworzy puty kopiec.
    //-----------------------------------------------------------------------
    public: Heap();


    //-----------------------------------------------------------------------
    // Konstruktor. Tworzy kopiec na podstawie zadanego ciągu liczb.
    //
    // Parametry
    // new_elements - ciąg wartości, których ma być zbudowany kopiec
    //-----------------------------------------------------------------------
    public: Heap(vector<int> new_elements);
    

    //-----------------------------------------------------------------------
    // Konstruktor kopiujący. Tworzy kopiec będący zadaną kopią zadanego
    // kopca.
    //
    // Parametry
    // copy - kopiec, który ma zostać skopiowany
    //-----------------------------------------------------------------------
    public: Heap(Heap* copy);


    //-----------------------------------------------------------------------
    // Destruktor. Zwalnia pamięć po kopcu.
    //-----------------------------------------------------------------------
    public: ~Heap();


    //-----------------------------------------------------------------------
    // Wyświetla zawartość kopca.
    //-----------------------------------------------------------------------
    public: void print();


    //-----------------------------------------------------------------------
    // Dodaje do kopca nowy element. Od razu po dodaniu elementu naprawia
    // kopiec.
    //
    // Parametry:
    // new_element - wartość elementu, który ma zostać dodany do kopca
    //-----------------------------------------------------------------------
    public: void add(int new_element);


    //-----------------------------------------------------------------------
    // Usuwa korzeń kopca. Od razu po usunięciu korzenia naprawia kopiec.
    //
    // Zwraca:
    // Informacje o wyniku operacji. True, gdy się powiodła. False, gdy nie.
    //-----------------------------------------------------------------------
    public: bool pop_root();


    //-----------------------------------------------------------------------
    // Znajduje element o zadanej wartości w kopcu i zwraca jego adres.
    // W przypadku, gdy element o zadanej wartości nie znajduje się w kopcu
    // zwrócony zostaje nullptr.
    //
    // Parametry:
    // value - wartość szukanego elementu
    //
    // Zwraca:
    // Adres elementu o zadanej wartości lub nullptr w przypadku nieistnienia
    // takiego elementu.
    //-----------------------------------------------------------------------
    public: int* find(int value);


    //-----------------------------------------------------------------------
    // Dokonuje naprawy całego kopca za pomocą algorytmu Floyda.
    //-----------------------------------------------------------------------
    private: void buildHeapFloyd();


    #define LEFT_CHILD_INDEX(i) (2 * i + 1)
    //-----------------------------------------------------------------------
    // Znajduje lewego potomka elementu o zadanym indeksie. Jeżeli element
    // nie ma lewego potomka zwrócony zostanie nullptr.
    // 
    // Parametry:
    // index - indeks elementu, którego potomka szukamy
    //
    // Zwraca:
    // Adres lewego potomka elementu o indeksie index lub nullptr, gdy lewy
    // potomek nie istnieje.
    //-----------------------------------------------------------------------
    private: int* getLeftChild(unsigned index) { return elements[LEFT_CHILD_INDEX(index)]; }

    
    #define RIGHT_CHILD_INDEX(i) (2 * i + 2)  
    //-----------------------------------------------------------------------
    // Znajduje prawego potomka elementu o zadanym indeksie. Jeżeli element
    // nie ma prawego potomka zwrócony zostanie nullptr.
    // 
    // Parametry:
    // index - indeks elementu, którego potomka szukamy
    //
    // Zwraca:
    // Adres prawego potomka elementu o indeksie index lub nullptr, gdy prawy
    // potomek nie istnieje.
    //-----------------------------------------------------------------------
    private: int* getRightChild(unsigned index) { return elements[RIGHT_CHILD_INDEX(index)]; }


    #define PARENT_INDEX(i) ( floor( (i - 1)/2 ) )
    //-----------------------------------------------------------------------
    // Znajduje rodzica elementu o zadanym indeksie lub nullptr, gdy zadany
    // element jest korzeniem.
    // 
    // Parametry:
    // index - indeks elementu, którego rodzica szukamy
    //
    // Zwraca:
    // Adres rodzica elementu o indeksie index lub nullptr, gdy element jest
    // korzeniem.
    //-----------------------------------------------------------------------
    private: int* getParent(unsigned index) { return elements[PARENT_INDEX(index)]; };


    //-----------------------------------------------------------------------
    // Zwraca tablice z elemetami kopca.
    //
    // Zwraca:
    // Kopie tablicy z elementami kopca.
    //-----------------------------------------------------------------------
    public: DynamicArray getElements() { return elements; }


    //-----------------------------------------------------------------------
    // Wykonuje naprawę kopca w dół zaczynając od elementu o zadanym
    // indeksie.
    //
    // Parametry:
    // node_index - indeks elementu, od którego ma rozpocząć się naprawa
    //-----------------------------------------------------------------------
    private: void repairDownwards(unsigned node_index);


    //-----------------------------------------------------------------------
    // Wykonuje naprawę kopca w górę zaczynając od elementu o zadanym
    // indeksie.
    //
    // Parametry:
    // node_index - indeks elementu, od którego ma rozpocząć się naprawa
    //-----------------------------------------------------------------------
    private: void repairUpwards(unsigned node_index);


    //-----------------------------------------------------------------------
    // Znajduje indeks największego (co do wartości) potomka elementu o 
    // zadanym indeksie. Jeżeli zadany element jest liściem zwrócona zostanie
    // wartość IS_LEAF.
    // 
    // Parametry:
    // node_index - indeks elementu, którego największego potomka szukamy
    //
    // Zwraca:
    // Indeks największego potomka elementu o indeksie node_index lub IS_LEAF
    // gdy ten element jest liściem.
    //-----------------------------------------------------------------------
    private: int getMaxChildIndex(unsigned node_index);
    #define IS_LEAF -123


    //-----------------------------------------------------------------------
    // Zwraca odniesienie do korzenia kopca. W wypadku, gdy kopiec jest pusty
    // zwrócony zostanie nullptr.
    //
    // Zwraca:
    // Adres elementu, będącego korzeniem kopca lub nullptr, gdy kopiec jest
    // pusty.
    //-----------------------------------------------------------------------
    public: int* root() { return elements[0]; }

};

enum HeapActions{
    EXIT_HEAP,
    ADD_HEAP,
    REMOVE_HEAP,
    FIND_HEAP,
    LOAD_HEAP
};