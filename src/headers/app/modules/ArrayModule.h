#include "app/modules/Module.h"
#include "data-structures/DynamicArray.h"

using namespace std;

// Moduł obsłujący testy dla tablicy dynamicznej
class ArrayModule : public Module{

    /* POLA */
    private: DynamicArray* array;


    /* METODY */
    
    // Konstruktor
    public: ArrayModule();

    // Destruktor
    public: virtual ~ArrayModule();

    // Pętla główna modułu
    private: virtual void loop();

    // Dodanie elementu na poczatek
    private: void pushFront();

    // Dodanie elementu na koniec
    private: void pushBack();

    // Dodanie w dowolne miejsce
    private: void add();

    // Usunięcie z początku
    private: void popFront();

    // Usunięcie z końca
    private: void popBack();

    // Usunięcie z dowolnego miejsca tablicy
    private: void remove();

    // Wyszukanie elementu w tablicy
    private: void find();

    // Wczytanie danych z pliku
    private: void load();

};