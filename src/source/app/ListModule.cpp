#include "app/ListModule.h"
#include "app/Console.h"

const string ListModule::INSERT_INDEX = "Wprowadz pozycje elementu (indeksujac od 1)";
const string ListModule::FTCHED_ELEMENT = "Pobrany element";
const string ListModule::LIST_EMPTY = "Lista jest pusta!";

void ListModule::loop(){

    bool is_running = true;
    List* previous_state = nullptr;     // przechowuje poprzedni stan listy

    while (is_running){
        
        Console::clearScreen();

        if(previous_state != nullptr){
            cout << "POPRZEDNI STAN LISTY:\n";
            previous_state->print();
            cout << endl;

            delete previous_state;
            previous_state = nullptr;
        }
        previous_state = new List(list);

        cout << "OBECNY STAN LISTY:\n";
        list->print();
        cout << endl;

        switch(menu->getUserChoice()){
            // Powrot do menu
            case ListActions::BACK: is_running = false; break;

            // Zmiana kierunku wyświetlania
            case ListActions::SWAP: list->swap(); break;

            // Dodanie elementu na początek
            case ListActions::PUSH_FRONT: pushFront(); break;

            // Dodanie elementu na koniec listy
            case ListActions::PUSH_BACK: pushBack(); break;    

            // Dodanie elementu w dowolne miejsce
            case ListActions::ADD: add(); break;

            // Pobierz głowę
            case ListActions::HEAD: head(); break;

            // Pobierz ogon
            case ListActions::TAIL: tail(); break;

            // Wyszukanie elementu
            case ListActions::FIND: find(); break;

            // Usunięcie elementu z głowy
            case ListActions::POP_FRONT: pop_front(); break;

            // Usunięcie elementu z ogona
            case ListActions::POP_BACK: pop_back(); break;

            // Usunięcie elementu z dowolnego miejsca listy
            case ListActions::REMOVE: remove(); break;

            // Nieznana opcja
            default: Console::waitForUserResponse(); break;
        }
    }

    // Usunięcie porzedniego stanu listy
    if(previous_state != nullptr) {
        delete previous_state;
        previous_state = nullptr;
    }

}

ListModule::ListModule() : Module("LISTA DWUKIERUNKOWA"){

    list = new List();

    menu->addOption(ListActions::BACK, "Powrot do menu glownego");
    menu->addOption(ListActions::SWAP, "Zmien kierunek wyswietlania");
    menu->addOption(ListActions::HEAD, "Pobierz glowe listy");
    menu->addOption(ListActions::TAIL, "Pobierz ogon listy");
    menu->addOption(ListActions::PUSH_FRONT, "Dodaj element na poczatek listy");
    menu->addOption(ListActions::PUSH_BACK, "Dodaj element na koniec listy");
    menu->addOption(ListActions::ADD, "Dodaj element w dowolne miejsce listy");
    menu->addOption(ListActions::POP_FRONT, "Usun element z poczatku listy");
    menu->addOption(ListActions::POP_BACK, "Usun element z konca listy");
    menu->addOption(ListActions::REMOVE, "Usun element z dowolnego miejsca listy");
    menu->addOption(ListActions::CLEAR, "Wyczysc liste");
    menu->addOption(ListActions::FIND, "Wyszukaj element w liscie");

}

ListModule::~ListModule(){

    delete list;

}

void ListModule::pushFront(){

    try{
        list->push_front(Console::getIntInput(INSERT_ELEMENT_VALUE)); 
    } catch(invalid_argument e){
        cout << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ListModule::pushBack(){

    try{
        list->push_back(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout  << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ListModule::add(){

    try{
        list->add(  
            Console::getIntInput(INSERT_ELEMENT_VALUE), 
            Console::getIntInput(INSERT_INDEX)-1
        );
    } catch(invalid_argument e){
        cout << e.what() << endl;
        Console::waitForUserResponse();
    }

}

void ListModule::head(){

    ListElement* head_element = list->front();

    if(head_element == nullptr) printf("%s\n", LIST_EMPTY.c_str());
    else printf("%s: %d\n", FTCHED_ELEMENT.c_str(), head_element->value);

    Console::waitForUserResponse();

}

void ListModule::tail(){

    ListElement* tail_element = list->back();

    if(tail_element == nullptr) printf("%s\n", LIST_EMPTY.c_str());
    else printf("%s: %d\n", FTCHED_ELEMENT.c_str(), tail_element->value);

    Console::waitForUserResponse();

}

void ListModule::find(){

    ListElement* element = list->find(Console::getIntInput(INSERT_ELEMENT_VALUE));

    if(element == nullptr) printf("%s\n", ELEMENT_DOES_NOT_EXIST.c_str());
    else printf("%s: %d\n", FTCHED_ELEMENT.c_str(), element->value);

    Console::waitForUserResponse();

}

void ListModule::pop_front(){

    if(list->pop_front()) return;
    printf("%s\n", LIST_EMPTY.c_str());
    Console::waitForUserResponse();

}

void ListModule::pop_back(){

    if(list->pop_back()) return;
    printf("%s\n", LIST_EMPTY.c_str());
    Console::waitForUserResponse();

}

void ListModule::remove(){

    try{
        if(list->remove(Console::getIntInput(INSERT_INDEX)-1)) return;
        printf("%s\n", ELEMENT_DOES_NOT_EXIST.c_str());
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }
    Console::waitForUserResponse();

}