#include "app/modules/ListModule.h"
#include "app/modules/ArrayModule.h"
#include "app/modules/HeapModule.h"
#include "app/modules/BSTModule.h"

const string Module::INSERT_ELEMENT_VALUE = "Wprowadz wartosc elementu.";
const string Module::ELEMENT_DOES_NOT_EXIST = "Wskazany element nie zjaduje sie w tej strukturze!";
const string Module::INSERT_PATH = "Wprowadz siezke do pliku.";
const string Module::INSERT_INDEX = "Wprowadz pozycje elementu (indeksujac od 1)";
const string Module::FTCHED_ELEMENT = "Pobrany element";

void Module::start(ModuleTypes module_type){

    Module* module;
    switch (module_type){
        // Moduł listy dwukierunkowej
        case ModuleTypes::LIST_MODULE: module = new ListModule(); break;
        
        // Moduł tablicy dynamicznej
        case ModuleTypes::ARRAY_MODULE: module = new ArrayModule(); break;

        // Moduł kopca
        case ModuleTypes::HEAP_MODULE: module = new HeapModule(); break;

        // Moduł drzewa BST
        case ModuleTypes::BST_MODULE: module = new BSTModule(); break;
    }
    
    module->loop();
    delete module;

}

Module::Module(const string menu_header){

    menu = new Menu(menu_header);

}

Module::~Module(){

    delete menu;

}