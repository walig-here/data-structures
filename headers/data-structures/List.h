#pragma once
#include <iostream>
#include <vector>

using namespace std;

/* Struktura reprezentująca element listy */
struct ListElement{
    int value;                      // wartość zawarta w elemencie listy
    ListElement* next;              // adres kolejnego elementu
    ListElement* prev;              // adres poprzedniego elementu 

    // Konstruktor elementu listy
    ListElement(ListElement* prev = nullptr, int value = 0, ListElement* next = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

/* Klasa list dwukierunkowych */
class List{

    /* POLA */

    public: ListElement* head;      // Głowa listy
    public: ListElement* tail;      // Ogon listy
    private: bool print_backwards;  // czy lista ma być wyświetlana od tyłu?


    /* METODY */

    //-----------------------------------------------------------------------
    // Konstruktor. Tworzy pustą listę dwukierunkową.
    //-----------------------------------------------------------------------
    public: List();


    //-----------------------------------------------------------------------
    // Konstruktor kopiujący.
    //-----------------------------------------------------------------------
    public: List(List* &to_copy); 


    //-----------------------------------------------------------------------
    // Konstruktor tworzący listę na podstawie zadanego ciągu liczb
    //
    // Parametry:
    // elements - ciąg, na bazie ktrórego ma zostać zbudowana lista
    //-----------------------------------------------------------------------
    public: List(vector<int> elements);


    //-----------------------------------------------------------------------
    // Destruktor. Zwalnia pamięć po liście dwukierunkowej.
    //-----------------------------------------------------------------------
    public: ~List();


    //-----------------------------------------------------------------------
    // Wyszukuje w liście element o wskazanej wartości i zwraca jego adres.
    // W wypadku nie znalezienia żadnego elementu zwróci nullptr.
    //
    // Parametry:
    // value - wartość, jaką ma mieć wyszukiwany element
    //-----------------------------------------------------------------------
    public: ListElement* find(int value);


    //-----------------------------------------------------------------------
    // Pobranie wartości z głowy. W wypadku, gdy lista jest pusta zwrócony
    // zostanie nullptr.
    //-----------------------------------------------------------------------
    public: ListElement* front();


    //-----------------------------------------------------------------------
    // Pobranie wartości z ogona. W wypadku, gdy lista jest pusta zwrócony
    // zostanie nullptr.
    //-----------------------------------------------------------------------
    public: ListElement* back();


    //-----------------------------------------------------------------------
    // Dodaje element na początek listy
    //
    // Parametry:
    // new_element - wartość nowego elementu
    //-----------------------------------------------------------------------
    public: void push_front(int new_element);


    //-----------------------------------------------------------------------
    // Dodaje element na koniec listy.
    //
    // Parametry:
    // new_element - wartość nowego elementu
    //-----------------------------------------------------------------------
    public: void push_back(int new_element);


    //-----------------------------------------------------------------------
    // Usuwa element z początku kolejki. Zwraca true, gdy usunięcie 
    // przebiegło pomyślnie. W przeciwnym wypadku zwraca false.
    //-----------------------------------------------------------------------
    public: bool pop_front();


    //-----------------------------------------------------------------------
    // Usuwa element z końca kolejki. Zwraca true, gdy usunięcie 
    // przebiegło pomyślnie. W przeciwnym wypadku zwraca false.
    //-----------------------------------------------------------------------
    public: bool pop_back();


    //-----------------------------------------------------------------------
    // Dodanie elementu na wskazaną pozycję listy. Podanie indeksu równego 
    // lub większego od indeksu ogona poskutkuje dodanie elementu na koniec
    // listy.
    // 
    // Parametry:
    // new_element - wartośc nowego elementu
    // index - indeks na jaki ma dostać dodany nowy element
    //-----------------------------------------------------------------------
    public: void add(int new_element, unsigned index);


    //-----------------------------------------------------------------------
    // Usunięcie elementu o zadanym indeksie z listy. Zwraca false, jeżeli
    // akcja usunięcia zakończyła się niepowodzeniem. W przeciwnym wypadku
    // zwraca true.
    //
    // Parametry:
    // index - indeks elementu, który ma zostać usunięty
    //-----------------------------------------------------------------------
    public: bool remove(unsigned index);


    //-----------------------------------------------------------------------
    // Wyświetla zawartość listy.
    //-----------------------------------------------------------------------
    public: void print();


    //-----------------------------------------------------------------------
    // Zmienia kolejność wyświetlania listy. 
    //-----------------------------------------------------------------------
    public: void swap();

};

// Zbiór działań możliwych do wykonania na liście
enum ListActions{
    EXIT_LIST,
    EXAMINE_LIST,
    SWAP_LIST,
    HEAD_LIST,
    TAIL_LIST,
    PUSH_FRONT_LIST,
    PUSH_BACK_LIST,
    ADD_LIST,
    POP_FRONT_LIST,
    POP_BACK_LIST,
    REMOVE_LIST,
    FIND_LIST,
    LOAD_DATA_LIST
};