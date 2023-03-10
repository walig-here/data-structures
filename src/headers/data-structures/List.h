#include <iostream>

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
class List
{

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
    public: ListElement* find(const int value);


    //-----------------------------------------------------------------------
    // Pobranie wartości z głowy. W wypadku, gdy lista jest pusta zwrócony
    // zostanie nullptr.
    //-----------------------------------------------------------------------
    public: inline ListElement* front();


    //-----------------------------------------------------------------------
    // Pobranie wartości z ogona. W wypadku, gdy lista jest pusta zwrócony
    // zostanie nullptr.
    //-----------------------------------------------------------------------
    public: inline ListElement* back();


    //-----------------------------------------------------------------------
    // Dodaje element na początek listy
    //
    // Parametry:
    // new_element - wartość nowego elementu
    //-----------------------------------------------------------------------
    public: void push_front(const int new_element);


    //-----------------------------------------------------------------------
    // Dodaje element na koniec listy.
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
    public: void print();


    // Zmiana kolejności wyświetlania listy
    public: void swap();

};

// Zbiór działań możliwych do wykonania na liście
enum ListActions{
    BACK,
    SWAP,
    PUSH_FRONT,
    PUSH_BACK,
    ADD,
    POP_FRONT,
    POP_BACK,
    REMOVE,
    FIND,
    CLEAR
};