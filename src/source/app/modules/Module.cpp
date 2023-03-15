#include "app/modules/ListModule.h"

const string Module::INSERT_ELEMENT_VALUE = "Wprowadz wartosc elementu.";
const string Module::ELEMENT_DOES_NOT_EXIST = "Wskazany element nie zjaduje sie w tej strukturze!";
const string Module::INSERT_PATH = "Wprowadz siezke do pliku.";

void Module::start(ModuleTypes module_type){

    Module* module;
    switch (module_type){
        // Moduł listy dwukierunkowej
        case ModuleTypes::LIST: module = new ListModule(); break;
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