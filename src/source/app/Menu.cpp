#include "Menu.h"
#include <string.h>

Menu::Menu(string header){

    this->header = header;

}


Menu::~Menu(){

    // Czyszczenie listy opcji
    for(auto element : options) delete element;
    options.clear();

}


void Menu::addOption(const unsigned int token, string desc){

    if(desc == "") desc = "Opcja " + to_string(token);
    MenuElement* new_element = new MenuElement(token, desc);
    options.push_back(new_element);

}

void Menu::print(){

    // Format menu:
    // NAGŁÓWEK
    // Instrukcja obsługi
    // [t1] desc1
    // ...
    // [tn] descn
    // > 

    const string MANUAL = "Wybierz jedna z ponizszych opcji wprowadzajac odpowiadajacy jej symbol.";

    printf("%s\n", header.c_str());
    printf("%s\n", MANUAL.c_str());
    for(auto element : options) printf("[ %d ]\t\t%s\n", element->token, element->desc.c_str());
    printf("> ");

}

int Menu::getUserChoice(){

    // Użytkownik dokonuje wyboru
    string userChoice;
    int chosen_token;
    print();
    cin >> userChoice;

    // Sprawdzam, czy użtykownik nie wybrał symbolu o niedozwolonym formacie (nie liczbę)
    // lub symbolu, który nie występuje w menu
    chosen_token = isValidToken(userChoice);
    if(chosen_token < 0) return chosen_token;

    // Zwracam symbol
    return chosen_token;

}

int Menu::isValidToken(const string token){

    const string INVALID_FORMAT = "Symbol niedozwolonego formatu!";
    const string SYMBOL_DOES_NOT_EXIST = "Symbol nie istnieje!";
    int validated_token = -1;

    // Czy symbol ma dozwolony format?
    try{
        validated_token = stoi(token);
    } catch(invalid_argument){
        printf("%s\n", INVALID_FORMAT.c_str());
        return -1;
    }

    // Czy istnieje w menu?
    for(auto element : options){
        if(validated_token != element->token) continue;
        return validated_token;
    }

    // Nie istnieje w menu
    printf("%s\n", SYMBOL_DOES_NOT_EXIST.c_str());
    return -2;

}