#include "data-structures/DynamicArray.h"
#include "app/utility/FileReader.h"

#include <iostream>
#include <vector>

using namespace std;

DynamicArray::DynamicArray(){

    array_address = nullptr;
    length = 0;

}

DynamicArray::DynamicArray(DynamicArray *array) : DynamicArray() {

    if(array == nullptr) return;
    for(int i = 0; i < array->length; i++)
        push_back(array->array_address[i]);

}

DynamicArray::DynamicArray(string file) : DynamicArray() {

    // Wczytujemy dane z pliku
    vector<int> file_data = FileReader::readAllIntegers(file);
    if(file_data.size() == 0) return;

    
    // Pierwszą liczbę traktujemy jako rozmiar struktury, kolejne jako wartości w niej zawarte
    // Jeżeli rozmiar jest <=0 to przerywamy wczytywanie.
    // Tak samo jeżeli w pliku znajduje się mniej liczb niż zadeklarowano we wczytanej wartości.
    unsigned size = file_data[0];
    if(size <= 0 || file_data.size() <= size){
        printf("W pliku '%s' znajduja sie niepoprawne dane!\n", file.c_str());
        return;
    }
    for(int i = 1; i <= size; i++) push_back(file_data[i]);

}

DynamicArray::~DynamicArray(){

    // Zwolnienie obaszaru pamięci zajmowanego przez tablice
    if(array_address == nullptr) return;
    delete[] array_address;
    array_address = nullptr;

}

void DynamicArray::add(int new_element, unsigned index){

    // Jeżeli indeks to 0, to dodajemy na początek
    if(index == 0) return push_front(new_element);

    // Jeżeli indeks nie mieści się w tablicy to dodajemy na koniec
    if(index >= length) return push_back(new_element);

    // Relokacja tablicę i przesuwam wszystkie elementy na pozycjach większych niz index o 1 pozycję
    int* new_address = new int[++length];
    new_address[index] = new_element;

    for(int i = 0; i < length-1; i++)
        new_address[( i >= index ? i+1 : i)] = array_address[i]; 
    
    // Zwalniam poprzednią lokalizację i ustalam nowy adres
    delete[] array_address;
    array_address = new_address;

}

void DynamicArray::push_front(int new_element){

    // Relokuję tablicę i przesuwam dotyczas istniejące elementy o jedną pozycję w prawo
    int* new_address = new int[++length];
    new_address[0] = new_element;
    for(int i = 1; i < length; i++)
        new_address[i] = array_address[i-1];

    // Zwalniam poprzednią lokalizację tablicy i ustalam nową wartość adresu
    delete[] array_address;
    array_address = new_address;

}

void DynamicArray::push_back(int new_element){

    // Relokuję tablicę i kopiuję dotychczas istniejące elementy
    // Na koniec tablicy dodaję nowy element
    int* new_address = new int[++length];
    for(int i = 0; i < length-1; i++)
        new_address[i] = array_address[i];
    new_address[length-1] = new_element;

    // Zwalniam poprzednią lokalizację tablicy i ustalam nową wartość adresu
    delete[] array_address;
    array_address = new_address;

}

void DynamicArray::remove(unsigned index){

    // Jeżeli indeks 0, to usuwamy z początku
    if(index == 0) return pop_front();

    // Jeżeli wskazano ostatni element to pop_back()
    if(index == length-1) return pop_back();

    // Jeżeli wskazano indeks większy od maksymalnego, to nie usuwamy
    if(index >= length) return;

    // Relokuję tablicę i kopiuje dotychczas istniejące elementy poza tym usuniętym
    // Wszystkie elementy zajdujące się za usuniętym elementem są przesunięte o 1 pozycję w lewo
    int* new_address = new int[--length];
    for(int i = 0; i < length; i++)
        new_address[i] = array_address[ ( i >= index ? i+1 : i ) ]; 
    
    // Zwalniam poprzednią lokalizację tablicy i ustalam nową wartość adresu
    delete[] array_address;
    array_address = new_address;

}

void DynamicArray::pop_front(){

    // Z pustej tablicy nie usuwam
    if(length == 0) return;

    // Relokuję tablicę i kopiuje wszystkie dotchczas istniejące elementy poza pierwszym
    // Każdy element jest przesunięty o 1 pozycję w lewo
    int* new_address = new int[--length];
    for(int i = 0; i < length; i++)
        new_address[i] = array_address[i+1];
    
    // Zwalniam poprzednią lokalizację tablicy i ustalam nową wartość adresu
    delete[] array_address;
    array_address = new_address;

}

void DynamicArray::print(){

    printf("Zawartosc tablicy:\n");
    if(length == 0) {
        printf("pusta\n");
        return;
    }

    for(int i = 0; i < length; i++) 
        printf("%d ", array_address[i]);
    printf("\n");

}

void DynamicArray::pop_back(){

    // Z pustej tablicy nie usuwam
    if(length == 0) return;

    // Relokuję tablicę i kopiuje wszystkie dotchczas istniejące elementy poza ostatnim
    int* new_address = new int[--length];
    for(int i = 0; i < length; i++)
        new_address[i] = array_address[i];
    
    // Zwalniam poprzednią lokalizację tablicy i ustalam nową wartość adresu
    delete[] array_address;
    array_address = new_address;

}

int* DynamicArray::find(int value){

    for(int i = 0; i < length; i++)
        if(array_address[i] == value) return array_address+i;
    return nullptr;

}

int* DynamicArray::operator[](unsigned index){

    if(this == nullptr) return nullptr;
    if(index >= length) return nullptr;
    return &(array_address[index]);

}