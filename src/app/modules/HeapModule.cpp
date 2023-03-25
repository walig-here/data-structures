#include "app/modules/HeapModule.h"
#include "app/utility/Console.h"
#include "app/utility/FileReader.h"

HeapModule::HeapModule() : Module("KOPIEC") {

    heap = new Heap();

    menu->addOption(HeapActions::EXIT_HEAP, "Powrot do menu glownego");
    menu->addOption(HeapActions::ADD_HEAP, "Dodaj element do kopca");
    menu->addOption(HeapActions::REMOVE_HEAP, "Usun korzen kopca");
    menu->addOption(HeapActions::FIND_HEAP, "Znajdz element w kopcu");
    menu->addOption(HeapActions::LOAD_HEAP, "Wczytaj dane z pliku");

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
            cout << "POPRZEDNI STAN KOPCA:\n";
            previous_state->print();
            cout << endl;

            delete previous_state;
            previous_state = nullptr;
        }
        previous_state = new Heap(heap);

        cout << "OBECNY STAN KOPCA:\n";
        heap->print();
        cout << endl;

        switch (menu->getUserChoice()){
        
            // Powrót do menu głównego
            case HeapActions::EXIT_HEAP: is_running = false; break;

            // Dodanie elementu
            case HeapActions::ADD_HEAP: add(); break;

            // Usunięcie krozenia
            case HeapActions::REMOVE_HEAP: removeRoot(); break;

            // Wyszukanie elementu w kopcu
            case HeapActions::FIND_HEAP: find(); break;

            // Wczytanie danych
            case HeapActions::LOAD_HEAP: load(); break;

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

void HeapModule::load(){

    if(heap != nullptr){
        delete heap;
        heap = nullptr;
    }
    heap = new Heap(FileReader::readAllIntegers(Console::getInput(INSERT_PATH)));
    if(heap->root() == nullptr) {
        cout << "Nastapil blad wczytywania danych!" << endl;
        Console::waitForUserResponse();
    }

}

void HeapModule::removeRoot(){

    heap->pop_root();

}

void HeapModule::find(){

    int* element;
    try{
        element = heap->find(Console::getIntInput(INSERT_ELEMENT_VALUE));
    } catch(invalid_argument e){
        cout << e.what() << endl;
        return;
    }

    if(element == nullptr) cout << "Element nie znajduje sie w tej strukturze!" << endl;
    else  cout << "Znaleziony element: " << *element << endl;
    Console::waitForUserResponse();

}