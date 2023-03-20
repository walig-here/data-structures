#include "app/modules/HeapModule.h"
#include "app/utility/Console.h"

HeapModule::HeapModule() : Module("KOPIEC") {

    menu->addOption(HeapActions::EXIT_HEAP, "Powrot do menu glownego");

}

HeapModule::~HeapModule(){

    delete heap;

}

void HeapModule::loop(){

    bool is_running = true;
    Heap* previous_state = nullptr;

    while (is_running){
    
        Console::clearScreen();

        if(previous_state != nullptr){
            cout << "POPRZEDNI STAN TABLICY:\n";
            previous_state->print();
            cout << endl;

            delete previous_state;
            previous_state = nullptr;
        }
        previous_state = new Heap();

        cout << "OBECNY STAN LISTY:\n";
        heap->print();
        cout << endl;

        switch (menu->getUserChoice()){
        
            // Powrót do menu głównego
            case ArrayActions::EXIT: is_running = false; break;

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