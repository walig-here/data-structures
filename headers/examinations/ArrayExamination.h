
/**
 * Moduł dokonujący eskperytmentów na tablicy
*/

#include "data-structures/DynamicArray.h"
#include "examinations/ExaminationRecord.h"

namespace ArrayExamination{

    /**
     * Zbadanie dodawania elementu na początek tablicy
     */
    ExaminationRecord push_front(DynamicArray array, string filename);

    /**
     * Zbadanie dodawania elementu na koniec tablicy
    */
    double push_back(DynamicArray array, string filename);

   /**
    * Zbadanie dodawania elemntu na dowolny indeks tablcicy
   */
    double add_element(DynamicArray array, string filename);

    /**
     * Zbadanie usuwania elementu z początku tablicy
    */
   double pop_front(DynamicArray array, string filename);

   /**
    * Zbadanie usuwania elementu z końca tablicy
   */
    double pop_back(DynamicArray array, string filename);

    /**
     * Zbadania usuwanie elementu z dowolnej pozycji
    */
   double remove_element(DynamicArray array, string filename);

   /**
    * Zbadanie wyszukiwania elementu na dowolnej pozycji
   */
    double find_element(DynamicArray array, string filename);

} 