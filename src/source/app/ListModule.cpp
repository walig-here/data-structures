#include "app/ListModule.h"
#include "app/Console.h"

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
            case ListActions::PUSH_FRONT: 
                try{
                    list->push_front(Console::getIntInput(INSERT_NEW_EMENT_VALUE)); 
                } catch(invalid_argument e){
                    cout << e.what() << endl;
                    Console::waitForUserResponse();
                }
            break;

            // Dodanie elementu na koniec listy
            case ListActions::PUSH_BACK:
                try{
                    list->push_back(Console::getIntInput(INSERT_NEW_EMENT_VALUE));
                } catch(invalid_argument e){
                    cout << e.what() << endl;
                    Console::waitForUserResponse();
                }
            break;    

            // Wyczyść całą listę
            case ListActions::CLEAR:
                delete list;
                list = new List();
            break;

            // Nieznana opcja
            default: Console::waitForUserResponse(); break;
        }
    }

    if(previous_state != nullptr) delete previous_state;

}

ListModule::ListModule() : Module("LISTA DWUKIERUNKOWA"){

    list = new List();

    menu->addOption(ListActions::BACK, "Powrot do menu glownego");
    menu->addOption(ListActions::SWAP, "Zmien kierunek wyswietlania");
    menu->addOption(ListActions::PUSH_FRONT, "Dodaj element na poczatek listy");
    menu->addOption(ListActions::PUSH_BACK, "Dodaj element na koniec listy");
    menu->addOption(ListActions::ADD, "Dodaj element w dowolne miejsce listy");
    menu->addOption(ListActions::POP_FRONT, "Usun element z konca listy");
    menu->addOption(ListActions::POP_BACK, "Usun element z konca listy");
    menu->addOption(ListActions::REMOVE, "Usun element z dowolnego miejsca listy");
    menu->addOption(ListActions::FIND, "Wyszukaj element w liscie");
    menu->addOption(ListActions::CLEAR, "Wyczysc liste");

}

ListModule::~ListModule(){

    delete list;

}