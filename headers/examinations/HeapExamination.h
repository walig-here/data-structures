
/**
 * Moduł dokonujący eskperytmentów na kopcu
*/

#include "data-structures/Heap.h"
#include "examinations/ExaminationRecord.h"

namespace HeapExamination{

   /**
    * Zbadanie dodawania elemntu na dowolny indeks kopca
   */
    ExaminationRecord add_element(Heap heap);

    /**
     * Zbadania usuwanie elementu z dowolnej pozycji
    */
   ExaminationRecord remove_element(Heap heap);

   /**
    * Zbadanie wyszukiwania elementu na dowolnej pozycji
   */
    ExaminationRecord find_element(Heap heap);

}