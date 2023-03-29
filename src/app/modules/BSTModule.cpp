#include "app/modules/BSTModule.h"
#include "app/utility/Console.h"
#include "app/utility/FileReader.h"

BSTModule::BSTModule() : Module("DRZEWO WYSZUKIWAN BINARNYCH") {

    tree = new BinarySearchTree();

    menu->addOption(BSTACtions::EXIT_BST, "Powrot do menu glownego");
    menu->addOption(BSTACtions::ADD_BST, "Dodaj element do drzewa");
    menu->addOption(BSTACtions::REMOVE_BST, "Usun element z drzewa");
    menu->addOption(BSTACtions::ROTATE_LEFT, "Rotacja w lewo wzgledem wezla");
    menu->addOption(BSTACtions::ROTATE_RIGHT, "Rotacja w prawo wzgledem wezla");
    menu->addOption(BSTACtions::FIND_BST, "Znajdz element w drzewie");
    menu->addOption(BSTACtions::BALANCE, "Zrownowaz drzewo");
    menu->addOption(BSTACtions::LOAD_BST, "Wczytaj dane z pliku");

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
        previous_state = new BinarySearchTree(tree);

        cout << "OBECNY STAN DRZEWA:\n";
        tree->print();
        cout << endl;

        switch (menu->getUserChoice()){
        
            // Powrót do menu głównego
            case BSTACtions::EXIT_BST: is_running = false; break;

            // Dodanie elementu
            case BSTACtions::ADD_BST: add(); break;

            // Usunięcie elementu
            case BSTACtions::REMOVE_BST: remove(); break;

            // Rotacja w lewo
            case BSTACtions::ROTATE_LEFT: rotateLeft(); break;

            // Rotacja w prawo
            case BSTACtions::ROTATE_RIGHT: rotateRight(); break;

            // Wyszukanie lementu
            case BSTACtions::FIND_BST: find(); break;

            // Równoważanie drzewa
            case BSTACtions::BALANCE: balance(); break;

            // Wczytanie z pliku
            case BSTACtions::LOAD_BST: load(); break;

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

void BSTModule::rotateRight(){

    try{
        tree->rotateRight(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}

void BSTModule::rotateLeft(){

    try{
        tree->rotateLeft(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}

void BSTModule::remove(){
    
    try{
        tree->remove(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}

void BSTModule::add(){

    try{
        tree->add(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}

void BSTModule::balance(){

    tree->balance();

}

void BSTModule::find(){

    try{
        tree->find(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }
    Console::waitForUserResponse();

}

void BSTModule::load(){

    if(tree != nullptr){
        delete tree;
        tree = nullptr;
    }
    tree = new BinarySearchTree(FileReader::readAllIntegers(Console::getInput(INSERT_PATH)));

}