#include "app/ListModule.h"

const string Module::INSERT_NEW_EMENT_VALUE = "Wprowadz wartosc nowego elementu.";

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