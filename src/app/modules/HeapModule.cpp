#include "app/modules/HeapModule.h"
#include "app/utility/Console.h"
#include "app/utility/FileReader.h"

HeapModule::HeapModule() : Module("KOPIEC") {

    heap = new Heap();

    menu->addOption(HeapActions::EXIT_HEAP, "Powrot do menu glownego");
    menu->addOption(HeapActions::EXAMINE_HEAP, "Przeprowadz badania na kopcu");
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

            // Badania na kopcu
            case HeapActions::EXAMINE_HEAP: examine(); break;

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

#include "examinations/HeapExamination.h"
#include "app/utility/FileWriter.h"
#include "app/utility/RandomNumberGenerator.h"
#include <string>

void HeapModule::examine(){

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
    

    // Inicjujemy kopiec
    Heap* heap;
    vector<string> data;
    vector<int> elements;
    
    // Przeprowadzamy badania
    for(int j =0; j < 14; j++){
        cout << "ROZMIAR: " << number_of_elements[j] << endl;
        
        for(int i = 0; i < 50; i++) {
            cout << "Proba " << i+1 << "...";
            elements = RandomNumberGenerator::getIntegers(number_of_elements[j], INT_MIN, INT_MAX);
            heap = new Heap(elements);
            cout << "\t";

            data.push_back(HeapExamination::add_element(heap).getString()); cout << "#";
            data.push_back(HeapExamination::remove_element(heap).getString()); cout << "#";
            data.push_back(HeapExamination::find_element(heap).getString()); cout << "#";

            delete heap;
            cout << "\tzakonczona!\n";
        }

        FileWriter::save(data, "results/"+filename+to_string(number_of_elements[j])+".csv");
        cout << endl;
    }
    
    // Zapisujemy wyniki
    cout << "Badanie zakonczone!" << endl;
    Console::waitForUserResponse();

}