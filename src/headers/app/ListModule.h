#pragma once
#include "data-structures/List.h"
#include "app/Module.h"

using namespace std;

// Moduł obsługujący pracę z listą dwukirunkową
class ListModule : virtual public Module{

    /* POLA */
    private: List* list;         // lista obsługiwana przez moduł

    /* METODY */

    // Konstruktor
    public: ListModule();

    // Destruktor
    public: virtual ~ListModule();

    // Pętla główna modułu
    private: virtual void loop();

};