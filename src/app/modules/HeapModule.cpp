#include "app/modules/HeapModule.h"
#include "app/utility/Console.h"

HeapModule::HeapModule() : Module("KOPIEC") {

    heap = new Heap(true);

    menu->addOption(HeapActions::EXIT_HEAP, "Powrot do menu glownego");
    menu->addOption(HeapActions::ADD_HEAP, "Dodaj element do kopca");

}

HeapModule::~HeapModule(){

    delete heap;

}

void HeapModule::loop(){

    bool is_running = true;
    bool is_max = true;
    Heap* previous_state = nullptr;

    while (is_running){
    
        Console::clearScreen();

        if(previous_state != nullptr){
            cout << "POPRZEDNI STAN KOPCA:\n";
            previous_state->print();
            cout << endl;

            delete previous_state;
            previous_state = nullptr;
        }
        previous_state = new Heap(is_max);

        cout << "OBECNY STAN KOPCA:\n";
        heap->print();
        cout << endl;

        switch (menu->getUserChoice()){
        
            // Powrót do menu głównego
            case HeapActions::EXIT_HEAP: is_running = false; break;

            // Dodanie elementu
            case HeapActions::ADD_HEAP: add(); break;

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

void HeapModule::add(){

    try{
        heap->add(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
    }

}