#include <iostream>
#include "List.h"

using namespace std;

List::List(){

    head = nullptr;
    tail = nullptr;

}

List::~List(){



}

int List::front(){

    // Sprawdzam, czy lista nie jest pusta. 
    // Jeżeli jest to zwracam NULL.
    // W przeciwnym wypadku zwracam wartość elementu.
    if(head == nullptr) throw runtime_error("list is empty");
    return head->value;

}

int List::back(){

    // Sprzwdzam, czy lista nie jest pusta.
    // Jeżeli jest to zwracam NULL.
    // W przeciwnym wypadku zwracam wartość elementu.
    if(tail == nullptr) throw runtime_error("list is empty");
    return tail->value;

}

int List::operator[](const unsigned int wanted_index){

    // Jeżeli lista jest pusta to dalsze wykonanie metody nie ma sensu
    if(head == nullptr) throw runtime_error("list is empty");

    // Przy pobraniu z początku optymalniej jest użyć front()
    if(wanted_index == 0) return front();

    // Przeszukuję listę w poszukiwaniu elementu o zadanym indeksie
    ListElement* current_element; 
    for(int index = 0; current_element != nullptr; index++){

        current_element = current_element->next;
        if(index == wanted_index) return current_element->value;

    }

    // W wypadku, gdy element o wskazanym indeksie nie istnieje to występuje wyjątek
    throw runtime_error("invalid index");

}

void List::add(int new_element_value, unsigned int new_element_index){

    // Jeżeli dodajemy na początek to lepiej jest użyć metody push_front
    if(new_element_index == 0) return push_front(new_element_value);


    // Szukamy elementów, które będą sąsiadami nowego elementu, aby "umieścić" między nimi nowy element
    ListElement* prev_element = nullptr;  // sąsiad "z lewej"
    ListElement* next_element = nullptr;  // sąsiad "z prawej"
    for(int i = 0; prev_element != nullptr; i++){

        prev_element = prev_element->next;
        if(i != new_element_index-1) continue;
        next_element = prev_element->next;        
        break;

    }

    // Jeżeli sąsiad z prawej jest null to de facto dodajemy na koniec kolejki
    // Tyczy się to także sytuacji gdy wprowadzono indeks większy od indeksu ogona
    if(next_element == nullptr) return push_back(new_element_value);

    // Umieszamy nowy element między znalezionymi sąsiadami
    ListElement* new_element = new ListElement(prev_element, new_element_value, next_element);
    prev_element->next = new_element;
    next_element->prev = new_element;

}

void List::push_front(const int new_element_value){

    ListElement* new_element = new ListElement(nullptr, new_element_value, head);
    if(head != nullptr) head->prev = new_element;
    head = new_element;

}

void List::push_back(const int new_element_value){

    ListElement* new_element = new ListElement(tail, new_element_value, nullptr);
    if(tail != nullptr) tail->next = new_element;
    tail = new_element;

}