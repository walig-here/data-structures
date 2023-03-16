#include <iostream>
#include <list>

#include "app/utility/FileReader.h"
#include "app/utility/StringParser.h"
#include "data-structures/List.h"


using namespace std;

List::List(){

    head = nullptr;
    tail = nullptr;
    print_backwards = false;

}

List::List(List* &source) : List(){

    // Kopiujemy kolejność wyświetlania
    this->print_backwards = source->print_backwards;

    // Wykonujemy kopię wszystkich elementów
    ListElement* source_element = source->head;
    while(source_element != nullptr){
        this->push_back(source_element->value);
        source_element = source_element->next;
    }

}

List::List(string file) : List() {

    // Wczytujemy dane z pliku
    vector<int>* file_data = FileReader::readAllIntegers(file);
    if(file_data == nullptr) return;

    
    // Pierwszą liczbę traktujemy jako rozmiar struktury, kolejne jako wartości w niej zawarte
    // Jeżeli rozmiar jest <=0 to przerywamy wczytywanie.
    // Tak samo jeżeli w pliku znajduje się mniej liczb niż zadeklarowano we wczytanej wartości.
    unsigned size = (*file_data)[0];
    if(size <= 0 || file_data->size() <= size){
        delete file_data;
        printf("W pliku '%s' znajduja sie niepoprawne dane!\n", file.c_str());
        return;
    }
    for(int i = 1; i <= size; i++) push_back((*file_data)[i]);
    delete file_data;

}

List::~List(){

    // Zwalniamy kolejne elementy zaczynając od głowy
    while(pop_front());

}

ListElement* List::front(){

    return head;

}

ListElement* List::back(){

    return tail;

}

ListElement* List::find(int value){

    // Sprawdzamy, czy nie jest to wartość zapisana w ogonie
    if(tail != nullptr && tail->value == value) return tail;

    // Przeszukujemy listę w poszukiwaniu elementu o wskazanej wartości
    // W wypadku, gdy taka w liście nie wystąpi, zwórcony zostanie nullptr
    ListElement* found_element = head;
    while (found_element != nullptr && found_element->value != value)
        found_element = found_element->next;
    return found_element;

}

void List::add(int new_element_value, unsigned new_element_index){

    // Jeżeli dodajemy na początek to lepiej jest użyć metody push_front
    if(new_element_index == 0) return push_front(new_element_value);


    // Szukamy elementów, które będą sąsiadami nowego elementu, aby "umieścić" między nimi nowy element
    ListElement* prev_element = head;           // sąsiad "z lewej"
    ListElement* next_element = nullptr;        // sąsiad "z prawej"
    for(int i = 0; prev_element != nullptr; i++){

        if(i == new_element_index-1) {
            next_element = prev_element->next;        
            break;
        }
        prev_element = prev_element->next;

    }

    // Jeżeli sąsiad z prawej jest null to de facto dodajemy na koniec kolejki
    // Tyczy się to także sytuacji gdy wprowadzono indeks większy od indeksu ogona
    if(next_element == nullptr) return push_back(new_element_value);

    // Umieszamy nowy element między znalezionymi sąsiadami
    ListElement* new_element = new ListElement(prev_element, new_element_value, next_element);
    prev_element->next = new_element;
    next_element->prev = new_element;

}

void List::push_front(int new_element_value){

    ListElement* new_element = new ListElement(nullptr, new_element_value, head);
    if(head != nullptr) head->prev = new_element;
    head = new_element;

    // Sprawdzam, czy dodany element nie jest jednocześnie ogonem
    if(head->next == nullptr) tail = head;

}

void List::push_back(int new_element_value){

    ListElement* new_element = new ListElement(tail, new_element_value, nullptr);
    if(tail != nullptr) tail->next = new_element;
    tail = new_element;

    // Sprawdzam, czy dodany element nie jest jednocześnie głową
    if(tail->prev == nullptr) head = tail;

}

void List::print(){

    ListElement* current_element = nullptr;

    printf("Zawartosc listy ");
    if(print_backwards) {
        current_element = tail;
        printf("(od tylu): ");
    } else {
        current_element = head;
        printf("(od przodu): ");
    }

    if(current_element == nullptr){
        printf("pusta\n");
        return;
    }

    while (current_element != nullptr){

        printf("%d", current_element->value);
        if(current_element != head || current_element != tail) printf(" ");   
        
        if(print_backwards) current_element = current_element->prev;
        else current_element = current_element->next;
    }
    printf("\n");
}

void List::swap(){
    print_backwards = !print_backwards;
}

bool List::pop_front(){

    // Gdy lista jest pusta, to nie ma czego usuwać
    if(head == nullptr) return false;

    // Jeżeli głowa była jednymy elementem, to musimy "wyzerować" także ogon
    // W przeciwnym wypadku należy przepiąć wskaźnik elementu "za" głową
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    return true;

}

bool List::pop_back(){

    // Gdy lista jest pusta to nie ma czego usuwać
    if(tail == nullptr) return false;

    // Jeżeli ogon był jedynym elementem to musimy "wyzerować" także głowę
    // W przeciwnym wypadku należy przepiąć wskaźnik elementu "przed" ogonem
    if(tail->prev == nullptr){
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return true;

}

bool List::remove(unsigned wanted_index){

    // Jeżeli usuwamy z pierwszej pozycji, to lepiej jest użyć pop_front()
    if(wanted_index == 0) return pop_front();

    // Szukamy sądiadów z lewej i prawej elementu, który usuwamy
    // Następnie przepinamy ich wskaźniki i usuwamy element
    // Sprawdzam także, czy element nie jest ogonem, bo wtedy lepiej jest użyć metody pop_back()
    ListElement* element = head->next;
    for(int index = 1; element != nullptr; index++){
        
        if(wanted_index == index){
            if(element == tail) return pop_back();
            element->prev->next = element->next;
            element->next->prev = element->prev;
            delete element;
            return true;
        }
        element = element->next;

    }  

    // Element nie istnieje
    return false;

}