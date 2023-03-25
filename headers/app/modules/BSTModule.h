#pragma once
#include "app/modules/Module.h"
#include "data-structures/BinarySearchTree.h"

using namespace std;

class BSTModule : public Module {

    /* POLA */
    private: BinarySearchTree* tree;    // drzewo

    /* METODY */

    // KOnstruktor
    public: BSTModule();

    // Destruktor
    public: virtual ~BSTModule();

    // Pętla główna modułu
    private: virtual void loop();

};
