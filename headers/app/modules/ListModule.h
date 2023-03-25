#pragma once
#include "data-structures/List.h"
#include "app/modules/Module.h"

using namespace std;

// Moduł obsługujący pracę z listą dwukirunkową
class ListModule : virtual public Module{
    
    private: static const string LIST_EMPTY;

    /* POLA */
    private: List* list;         // lista obsługiwana przez moduł

    /* METODY */

    // Konstruktor
    public: ListModule();

    // Destruktor
    public: virtual ~ListModule();

    // Pętla główna modułu
    private: virtual void loop();

    // Dodanie elementu na początek
    private: void pushFront();

    // Dodanie elementu na koniec
    private: void pushBack();

    // Dodanie elementu w dowolne miejsce
    private: void add();

    // Pobranie głowy
    private: void head();

    // Pobranie ogona
    private: void tail();

    // Wyszukanie i pobranie dowolnego elementu
    private: void find();

    // Usunięcie elementu z początka
    private: void pop_front();

    // Usunięcie elementu z końca
    private: void pop_back();

    // Usunięcie element z dowolnego miejsca
    private: void remove();

    // Wczytanie danych
    private: void load();

};