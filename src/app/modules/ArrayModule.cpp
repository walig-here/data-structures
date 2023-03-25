#include "app/modules/ArrayModule.h"
#include "app/utility/Console.h"
#include "app/utility/FileReader.h"

ArrayModule::ArrayModule() : Module("TABLICA DYNAMICZNA"){

    array = new DynamicArray();

    menu->addOption(ArrayActions::EXIT, "Powrot do menu glownego");
    menu->addOption(ArrayActions::PUSH_FRONT_ARRAY, "Dodaj element na poczatek tablicy");
    menu->addOption(ArrayActions::PUSH_BACK_ARRAY, "Dodaj element na koniec tablicy");
    menu->addOption(ArrayActions::ADD_ARRAY, "Dodaj element na wybrana pozycje tablicy");
    menu->addOption(ArrayActions::POP_FRONT_ARRAY, "Usun element z poczatku tablicy");
    menu->addOption(ArrayActions::POP_BACK_ARRAY, "Usun element z konca tablicy");
    menu->addOption(ArrayActions::REMOVE_ARRAY, "Usun element z dowolnej pozycji");
    menu->addOption(ArrayActions::FIND_ARRAY, "Wyszukanie wartosci w tablicy");
    menu->addOption(ArrayActions::LOAD_DATA_ARRAY, "Wczytaj dane z pliku");

}

ArrayModule::~ArrayModule(){

    delete array;

}

void ArrayModule::loop(){

    bool is_running = true;
    DynamicArray* previous_state = nullptr;

    while (is_running){
    
        Console::clearScreen();

        if(previous_state != nullptr){
            cout << "POPRZEDNI STAN TABLICY:\n";
            previous_state->print();
            cout << endl;

            delete previous_state;
            previous_state = nullptr;
        }
        previous_state = new DynamicArray(array);

        cout << "OBECNY STAN LISTY:\n";
        array->print();
        cout << endl;

        switch (menu->getUserChoice()){
        
            // Powrót do menu głównego
            case ArrayActions::EXIT: is_running = false; break;

            // Dodanie elementu na poczatek tablicy
            case ArrayActions::PUSH_FRONT_ARRAY: pushFront(); break;

            // Dodanie elementu na koniec tablicy
            case ArrayActions::PUSH_BACK_ARRAY: pushBack(); break;

            // Dodanie elementu na dowolną pozycję tablicy
            case ArrayActions::ADD_ARRAY: add(); break;

            // Usuniecie elementu z poczatku tablicy
            case ArrayActions::POP_FRONT_ARRAY: popFront(); break;

            // Usuniecie elementu z konca tablicy
            case ArrayActions::POP_BACK_ARRAY: popBack(); break;

            // Usuniecie elementu z dowolnej pozycji w tablicy
            case ArrayActions::REMOVE_ARRAY: remove(); break;

            // Wyszukanie wartosci w tablicy
            case ArrayActions::FIND_ARRAY: find(); break;

            // Wczytaj dane z pliku
            case ArrayActions::LOAD_DATA_ARRAY: load(); break;

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

void ArrayModule::pushFront(){

    try{
        array->push_front(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e) {
        cout << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ArrayModule::pushBack(){

    try{
        array->push_back(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e) {
        cout << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ArrayModule::add(){

    try{
        array->add(Console::getIntInput(INSERT_ELEMENT_VALUE), Console::getIntInput(INSERT_INDEX)-1);
    } catch(invalid_argument e) {
        cout << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ArrayModule::popFront(){

    array->pop_front();

}

void ArrayModule::popBack(){

    array->pop_back();

}

void ArrayModule::remove(){

    try{
        array->remove(Console::getIntInput(INSERT_INDEX)-1);
    } catch(invalid_argument e) {
        cout << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ArrayModule::find(){

    int* found_element = nullptr; 
    try{
        found_element = array->find(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e) {
        cout << e.what() << endl;
        Console::waitForUserResponse();
        return;
    }

    if(found_element == nullptr) printf("%s\n", ELEMENT_DOES_NOT_EXIST.c_str());
    else printf("%s: %d\n", FTCHED_ELEMENT.c_str(), *found_element);
    Console::waitForUserResponse();
    return;

}

void ArrayModule::load(){

    if(array != nullptr){
        delete array;
        array = nullptr;
    }
    array = new DynamicArray(FileReader::readAllIntegers(Console::getInput(INSERT_PATH)));

}