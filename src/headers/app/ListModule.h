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

};