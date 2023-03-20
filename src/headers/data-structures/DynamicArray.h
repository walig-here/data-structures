#include <iostream>

using namespace std;

/* Klasa przedstawiająca tablicę dynamiczną */
class DynamicArray{

    /* POLA */
    private: int* array_address;        // adres pierwszej komórki w tablicy
    private: unsigned length;           // aktualna długość tablicy

    /* MEOTDY */

    // Konstruktor
    public: DynamicArray();


    // Konstruktor kopiujący
    public: DynamicArray(DynamicArray* array);

    //-----------------------------------------------------------------------
    // Konstruktor tworzący tablice na podstawie danych wczytanych z pliku.
    //
    // Parametry:
    // file - nazwa pliku, z którego zostaną wczytane dane
    //-----------------------------------------------------------------------
    public: DynamicArray(string file);


    // Destruktor
    public: ~DynamicArray();


    //-----------------------------------------------------------------------
    // Dodaje nowy element na wskazane miejsce w tablicy.
    // 
    // Parametry:
    // new_element - nowa wartość, która ma zostać dodana do tablicy
    // index - pozycja w tablicy, na którą ma zostać dodany nowy element  
    //-----------------------------------------------------------------------
    public: void add(int new_element, unsigned index);


    //-----------------------------------------------------------------------
    // Dodaje element na początek tablicy.
    //
    // Parametry:
    // new_element - wartość dodawanego do tablicy elementu
    //-----------------------------------------------------------------------
    public: void push_front(int new_element);


    //-----------------------------------------------------------------------
    // Dodaje element na koniec tablicy.
    //
    // Parametry:
    // new_element - wartość dodawanego do tablicy elementu
    //-----------------------------------------------------------------------
    public: void push_back(int new_element);


    //-----------------------------------------------------------------------
    // Usunięcie elementu o podanym indeksie.
    //
    // Parametry:
    // index - pozycja elementu tablicy, który ma zostać usunięty
    //-----------------------------------------------------------------------
    public: void remove(unsigned index);


    //-----------------------------------------------------------------------
    // Usuwa element z początku tablicy.
    //-----------------------------------------------------------------------
    public: void pop_front();


    //-----------------------------------------------------------------------
    // Usuwa element z końca tablicy.
    //-----------------------------------------------------------------------
    public: void pop_back();


    //-----------------------------------------------------------------------
    // Wyświetla zawartość tablicy.
    //-----------------------------------------------------------------------
    public: void print();


    //-----------------------------------------------------------------------
    // Wyszukuje w tablicy wskazaną wartość. W wypadku, gdy taka wartośc nie
    // występuje w tablicy, zwróci nullptr.
    //
    // Parametry:
    // value - wartość, która ma zostać odnaleziona
    //-----------------------------------------------------------------------
    public: int* find(int value);

    // Pobranie długości tablicy
    public: inline unsigned getLength() { return length; }

    // Pobranie elementu o zadanym indeksie
    public: int* operator[](unsigned index);

};

enum ArrayActions{
    EXIT,
    PUSH_FRONT_ARRAY,
    PUSH_BACK_ARRAY,
    ADD_ARRAY,
    POP_FRONT_ARRAY,
    POP_BACK_ARRAY,
    REMOVE_ARRAY,
    FIND_ARRAY,
    LOAD_DATA_ARRAY
};