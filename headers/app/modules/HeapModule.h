#pragma once
#include "app/modules/Module.h"
#include "data-structures/Heap.h"

using namespace std;

class HeapModule : public Module {

    /* POLA */
    private: Heap* heap;    // kopiec

    /* METODY */

    // KOnstruktor
    public: HeapModule();

    // Destruktor
    public: virtual ~HeapModule();

    // Pętla główna modułu
    private: virtual void loop();

    // Dodanie elementu
    private: void add();

    // Wczytanie danych z pliku
    private: void load();

    // Usunięcie korzenia
    private: void removeRoot();

    // Pobranie watości
    private: void find();

};