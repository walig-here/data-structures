
/**
 * Moduł dokonujący eskperytmentów na BST
*/

#include "data-structures/BinarySearchTree.h"
#include "examinations/ExaminationRecord.h"

namespace BSTExamination{

   /**
    * Zbadanie dodawania elemntu na dowolny indeks kopca
   */
    ExaminationRecord add_element(BinarySearchTree *tree);

    /**
     * Zbadania usuwanie elementu z dowolnej pozycji
    */
    ExaminationRecord remove_element(BinarySearchTree *tree);

   /**
    * Zbadanie wyszukiwania elementu w drzewie niezrównoważonym
   */
    ExaminationRecord find_element_unbalanced(BinarySearchTree *tree);

   /**
    * Zbadanie równoważenia i wyszukiwania elementu w drzewie zrównoważonym
   */
     vector<ExaminationRecord> find_element_balanced(BinarySearchTree *tree);

}