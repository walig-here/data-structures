#include "data-structures/DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(){

    array_address = nullptr;
    length = 0;

}

DynamicArray::~DynamicArray(){

    // Zwolnienie obaszaru pamięci zajmowanego przez tablice
    if(array_address == nullptr) return;
    delete[] array_address;
    array_address = nullptr;

}

int DynamicArray::operator[](int index){

    // Sprawdzenie poprawnosci indeksu
    if(index < 0 || index >= length) return 0;

    // Zwrócenie wartości zawartej pod podanym indeksem
    return array_address[index];

}

void DynamicArray::add(int new_element, int index){

    // Relokacja tablicy
    array_address = (int*) realloc(array_address, ++length * sizeof(int));

}