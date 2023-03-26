#include "app/modules/BSTModule.h"
#include "app/utility/Console.h"

BSTModule::BSTModule() : Module("DRZEWO WYSZUKIWAN BINARNYCH") {

    tree = new BinarySearchTree();

    menu->addOption(BSTACtions::EXIT_BST, "Powrot do menu glownego");
    menu->addOption(BSTACtions::ADD_BST, "Dodaj element do drzewa");

}

BSTModule::~BSTModule(){

    delete tree;

}

void BSTModule::loop(){

    bool is_running = true;
    BinarySearchTree* previous_state = nullptr;

    while (is_running){
    
        Console::clearScreen();

        if(previous_state != nullptr){
            cout << "POPRZEDNI STAN DRZEWA:\n";
            previous_state->print();
            cout << endl;

            delete previous_state;
            previous_state = nullptr;
        }
        previous_state = new BinarySearchTree();

        cout << "OBECNY STAN DRZEWA:\n";
        tree->print();
        cout << endl;

        switch (menu->getUserChoice()){
        
            // Powrót do menu głównego
            case BSTACtions::EXIT_BST: is_running = false; break;

            // Dodanie elementu
            case BSTACtions::ADD_BST: add(); break;

            // Nieznana opcja
            default: Console::waitForUserResponse(); break;

        }

    }
    
    // Usunięcie porzedniego stanu tablicy
    if(previous_state != nullptr) {
        delete previous_state;
        previous_state = nullptr;
    }

}

void BSTModule::add(){

    try{
        tree->add(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}