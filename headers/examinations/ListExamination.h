
/**
 * Moduł dokonujący eskperytmentów na liście
*/

#include "data-structures/List.h"
#include "examinations/ExaminationRecord.h"

namespace ListExamination{

    /**
     * Zbadanie dodawania elementu na początek listy
     */
    ExaminationRecord push_front(List list);

    /**
     * Zbadanie dodawania elementu na koniec listy
    */
    ExaminationRecord push_back(List list);

   /**
    * Zbadanie dodawania elemntu na dowolny indeks listy
   */
    ExaminationRecord add_element(List list);

    /**
     * Zbadanie usuwania elementu z początku listy
    */
   ExaminationRecord pop_front(List list);

   /**
    * Zbadanie usuwania elementu z końca listy
   */
    ExaminationRecord pop_back(List list);

    /**
     * Zbadania usuwanie elementu z dowolnej pozycji
    */
   ExaminationRecord remove_element(List list);

   /**
    * Zbadanie wyszukiwania elementu na dowolnej pozycji
   */
    ExaminationRecord find_element(List list);

}