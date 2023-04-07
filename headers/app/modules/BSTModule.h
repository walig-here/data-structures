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

    // Dodanie węzła do drzewa
    private: void add();

    // Usunięcie węzła
    private: void remove();

    // Rotacja w lewo
    private: void rotateLeft();

    // Rotacja w prawo
    private: void rotateRight();

    // Wyszukanie elementu
    private: void find();

    // Wczytanie z pliku
    private: void load();

    // Zrównoważenie drzewa
    private: void balance();

    // Przebadanie drzewa
    private: void examine();

};
