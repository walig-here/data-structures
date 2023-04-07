
/**
 * Moduł dokonujący eskperytmentów na tablicy
*/

#include "data-structures/DynamicArray.h"
#include "examinations/ExaminationRecord.h"

namespace ArrayExamination{

    /**
     * Zbadanie dodawania elementu na początek tablicy
     */
    ExaminationRecord push_front(DynamicArray* array);

    /**
     * Zbadanie dodawania elementu na koniec tablicy
    */
    ExaminationRecord push_back(DynamicArray* array);

   /**
    * Zbadanie dodawania elemntu na dowolny indeks tablcicy
   */
    ExaminationRecord add_element(DynamicArray* array);

    /**
     * Zbadanie usuwania elementu z początku tablicy
    */
   ExaminationRecord pop_front(DynamicArray* array);

   /**
    * Zbadanie usuwania elementu z końca tablicy
   */
    ExaminationRecord pop_back(DynamicArray* array);

    /**
     * Zbadania usuwanie elementu z dowolnej pozycji
    */
   ExaminationRecord remove_element(DynamicArray* array);

   /**
    * Zbadanie wyszukiwania elementu na dowolnej pozycji
   */
    ExaminationRecord find_element(DynamicArray* array);

} 