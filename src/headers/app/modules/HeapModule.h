#include "app/modules/Module.h"
#include "data-structures/Heap.h"

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

};