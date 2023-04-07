#include "app/modules/BSTModule.h"
#include "app/utility/Console.h"
#include "app/utility/FileReader.h"

BSTModule::BSTModule() : Module("DRZEWO WYSZUKIWAN BINARNYCH") {

    tree = new BinarySearchTree();

    menu->addOption(BSTACtions::EXIT_BST, "Powrot do menu glownego");
    menu->addOption(BSTACtions::EXAMINE_BST, "Przeprowadz badania na drzewie");
    menu->addOption(BSTACtions::ADD_BST, "Dodaj element do drzewa");
    menu->addOption(BSTACtions::REMOVE_BST, "Usun element z drzewa");
    menu->addOption(BSTACtions::ROTATE_LEFT, "Rotacja w lewo wzgledem wezla");
    menu->addOption(BSTACtions::ROTATE_RIGHT, "Rotacja w prawo wzgledem wezla");
    menu->addOption(BSTACtions::FIND_BST, "Znajdz element w drzewie");
    menu->addOption(BSTACtions::BALANCE_BST, "Zrownowaz drzewo");
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

            // Badania nad BST
            case BSTACtions::EXAMINE_BST: examine(); break;

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
            case BSTACtions::BALANCE_BST: balance(); break;

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
        tree->rotateRight(tree->find(Console::getIntInput(INSERT_ELEMENT_VALUE)));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}

void BSTModule::rotateLeft(){

    try{
        tree->rotateLeft(tree->find(Console::getIntInput(INSERT_ELEMENT_VALUE)));
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

#include "examinations/BSTExamination.h"
#include "app/utility/FileWriter.h"
#include "app/utility/RandomNumberGenerator.h"
#include <string>

void BSTModule::examine(){

    // Wczytujemy dane
    unsigned number_of_elements[] = { 
        0,
        25000,
        50000,
        75000,
        100000,
        280000,
        460000,
        640000,
        1000000,
        2800000,
        4600000,
        6400000,
        8200000,
        10000000
     };
    string filename;
    Console::clearScreen();
    filename = Console::getInput("Wprowadz nazwe pliku, gdzie zostana zapisane wyniki");
    

    // Inicjujemy tablicę
    BinarySearchTree* tree;
    vector<string> data;
    vector<int> elements;
    
    // Przeprowadzamy badania
    for(int j = 0; j < 14; j++){
        cout << "ROZMIAR: " << number_of_elements[j] << endl;

        for(int i = 0; i < 50; i++) {
            cout << "Proba " << i+1 << "...";
            elements = RandomNumberGenerator::getIntegers(number_of_elements[j], INT_MIN, INT_MAX);
            cout << "\t";
            
            tree = new BinarySearchTree(elements);
            data.push_back(BSTExamination::add_element(tree).getString()); cout << "#";
            delete tree;

            tree = new BinarySearchTree(elements);
            data.push_back(BSTExamination::remove_element(tree).getString()); cout << "#";
            delete tree;

            tree = new BinarySearchTree(elements);
            data.push_back(BSTExamination::find_element_unbalanced(tree).getString()); cout << "#";
            delete tree;

            tree = new BinarySearchTree(elements);
            {
                vector<ExaminationRecord> records = BSTExamination::find_element_balanced(tree);
                data.push_back(records[0].getString()); cout << "#";
                data.push_back(records[1].getString()); cout << "#";
            }
            delete tree;

            cout << "\tzakonczona!\n";
        }

        FileWriter::save(data, "results/"+filename+to_string(number_of_elements[j])+".csv");
        cout << endl;
    }
    
    // Zapisujemy wyniki
    cout << "Badanie zakonczone!" << endl;
    Console::waitForUserResponse();

}