#include <iostream>

using namespace std;

/* Struktura reprezentująca element listy */
struct ListElement{
    int value = NULL;               // wartość zawarta w elemencie listy
    ListElement* next = nullptr;    // adres kolejnego elementu
    ListElement* prev = nullptr;    // adres poprzedniego elementu 

    // Konstruktor elementu listy
    ListElement(ListElement* prev = nullptr, int value = NULL, ListElement* next = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

/* Klasa list dwukierunkowych */
class List
{

    /* POLA */
    public: ListElement* head;      // Głowa kolejki
    public: ListElement* tail;      // Ogon kolejki

    /* METODY */

    //-----------------------------------------------------------------------
    // Konstruktor. Tworzy pustą listę dwukierunkową.
    //-----------------------------------------------------------------------
    public: List();


    //-----------------------------------------------------------------------
    // Destruktor. Zwalnia pamięć po liście dwukierunkowej.
    //-----------------------------------------------------------------------
    public: ~List();


    //-----------------------------------------------------------------------
    // Pobranie wartości z elementu o wskaznym indeksie. W wypadku zadania
    // indeksu o niepoprawnej wartości wywołany zostanie wyjątek "invalid index".
    // W wypadku użycie operatora na liście pustej wywołany zostanie wyjątek
    // "list is empty".
    //
    // Parametry:
    // index - indeks elementu, którego wartość ma zostać zwrócona
    //-----------------------------------------------------------------------
    public: int operator[](const unsigned int index);


    //-----------------------------------------------------------------------
    // Pobranie wartości z głowy. W wypadku, gdy lista jest pusta wywołany
    // zostanie wyjątek "list is empty".
    //-----------------------------------------------------------------------
    public: int front();


    //-----------------------------------------------------------------------
    // Pobranie wartości z ogona. W wypadku, gdy lista jest pusta wywołany
    // zostanie wyjątek "listy is empty".
    //-----------------------------------------------------------------------
    public: int back();


    //-----------------------------------------------------------------------
    // Dodaje element na początek listy
    //
    // Parametry:
    // new_element - wartość nowego elementu
    //-----------------------------------------------------------------------
    public: void push_front(const int new_element);


    //-----------------------------------------------------------------------
    // Dodaje element na koniec listy
    //
    // Parametry:
    // new_element - wartość nowego elementu
    //-----------------------------------------------------------------------
    public: void push_back(const int new_element);


    //-----------------------------------------------------------------------
    // Dodanie elementu na wskazaną pozycję listy. Podanie indeksu równego 
    // lub większego od indeksu ogona poskutkuje dodanie elementu na koniec
    // listy.
    // 
    // Parametry:
    // new_element - wartośc nowego elementu
    // index - indeks na jaki ma dostać dodany nowy element
    //-----------------------------------------------------------------------
    public: void add(const int new_element, const unsigned int index);


    // Usunięcie elementu o zadanym indeksie z listy
    public: void remove(const unsigned int index);


    // Wyświetlenie listy (od początku lub końca)
    public: void print(bool backwards = false);

};