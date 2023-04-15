#include "app/modules/ListModule.h"
#include "app/utility/Console.h"
#include "app/modules/ListModule.h"
#include "app/utility/FileReader.h"

#include <list>

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
            case ListActions::EXIT_LIST: is_running = false; break;

            // Przeprowadz badania na liscie
            case ListActions::EXAMINE_LIST: examine(); break;

            // Zmiana kierunku wyświetlania
            case ListActions::SWAP_LIST: list->swap(); break;

            // Dodanie elementu na początek
            case ListActions::PUSH_FRONT_LIST: pushFront(); break;

            // Dodanie elementu na koniec listy
            case ListActions::PUSH_BACK_LIST: pushBack(); break;    

            // Dodanie elementu w dowolne miejsce
            case ListActions::ADD_LIST: add(); break;

            // Pobierz głowę
            case ListActions::HEAD_LIST: head(); break;

            // Pobierz ogon
            case ListActions::TAIL_LIST: tail(); break;

            // Wyszukanie elementu
            case ListActions::FIND_LIST: find(); break;

            // Usunięcie elementu z głowy
            case ListActions::POP_FRONT_LIST: pop_front(); break;

            // Usunięcie elementu z ogona
            case ListActions::POP_BACK_LIST: pop_back(); break;

            // Usunięcie elementu z dowolnego miejsca listy
            case ListActions::REMOVE_LIST: remove(); break;

            // Wczytanie z pliku
            case ListActions::LOAD_DATA_LIST: load(); break;

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

    menu->addOption(ListActions::EXIT_LIST, "Powrot do menu glownego");
    menu->addOption(ListActions::EXAMINE_LIST, "Przeprowadz badania na liscie");
    menu->addOption(ListActions::SWAP_LIST, "Zmien kierunek wyswietlania");
    menu->addOption(ListActions::HEAD_LIST, "Pobierz glowe listy");
    menu->addOption(ListActions::TAIL_LIST, "Pobierz ogon listy");
    menu->addOption(ListActions::PUSH_FRONT_LIST, "Dodaj element na poczatek listy");
    menu->addOption(ListActions::PUSH_BACK_LIST, "Dodaj element na koniec listy");
    menu->addOption(ListActions::ADD_LIST, "Dodaj element w dowolne miejsce listy");
    menu->addOption(ListActions::POP_FRONT_LIST, "Usun element z poczatku listy");
    menu->addOption(ListActions::POP_BACK_LIST, "Usun element z konca listy");
    menu->addOption(ListActions::REMOVE_LIST, "Usun element z dowolnego miejsca listy");
    menu->addOption(ListActions::FIND_LIST, "Wyszukaj element w liscie");
    menu->addOption(ListActions::LOAD_DATA_LIST, "Wczytaj dane z pliku");

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

void ListModule::load(){

    if(list != nullptr){
        delete list;
        list = nullptr;
    }
    list = new List(FileReader::readAllIntegers(Console::getInput(INSERT_PATH)));
    if(list->front() == nullptr) Console::waitForUserResponse();

}

#include "examinations/ListExamination.h"
#include "app/utility/FileWriter.h"
#include "app/utility/RandomNumberGenerator.h"
#include <string>

void ListModule::examine(){

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
    List* list;
    vector<string> data;
    vector<int> elements;
    
    // Przeprowadzamy badania
    for(int j = 0; j < 14; j++){
        cout << "ROZMIAR: " << number_of_elements[j] << endl;
        
        for(int i = 0; i < 30; i++) {
            cout << "Proba " << i+1 << "...";
            elements = RandomNumberGenerator::getIntegers(number_of_elements[j], INT_MIN, INT_MAX);
            list = new List(elements);
            cout << "\t";

            data.push_back(ListExamination::push_front(list).getString()); cout << "#";
            data.push_back(ListExamination::push_back(list).getString()); cout << "#";
            data.push_back(ListExamination::add_element(list).getString()); cout << "#";
            data.push_back(ListExamination::pop_front(list).getString()); cout << "#";
            data.push_back(ListExamination::pop_back(list).getString()); cout << "#";
            data.push_back(ListExamination::remove_element(list).getString()); cout << "#";
            data.push_back(ListExamination::find_element(list).getString()); cout << "#";

            delete list;
            cout << "\tzakonczona!\n";
        }
        
        FileWriter::save(data, "results/"+filename+to_string(number_of_elements[j])+".csv");
        data.clear();
        cout << endl;
    }
    
    // Zapisujemy wyniki
    FileWriter::save(data, "results/"+filename+".csv");
    cout << "Badanie zakonczone!" << endl;
    Console::waitForUserResponse();

}