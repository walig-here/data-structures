#pragma once
#include "data-structures/List.h"
#include "app/Module.h"

using namespace std;

// Moduł obsługujący pracę z listą dwukirunkową
class ListModule : virtual public Module{

    /* POLA */
    private: List* list;         // lista obsługiwana przez moduł

    private: static const string INSERT_INDEX;
    private: static const string FTCHED_ELEMENT;
    private: static const string LIST_EMPTY;

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

};