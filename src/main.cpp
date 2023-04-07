#include "app/modules/ListModule.h"
#include "app/utility/Console.h"
#include "app/utility/RandomNumberGenerator.h"


// Opcje do wyboru w menu głównym
enum MainMenuOptions{
    EXIT,
    OPEN_LIST_MODULE,
    OPEN_ARRAY_MODULE,
    OPEN_HEAP_MODULE,
    OPEN_BST_MODULE,
    GENERATE_RANDOM_DATA
};

// Menu główne, pozwalające na wybór struktury, którą chcemy przetestować
void mainMenu();

// Główna funkcja aplikacji
int main(int argc, char const *argv[])
{

    // Głowne menu aplikacji
    mainMenu();
        
    // Poprawne zamknięcie
    return 0;
}


void mainMenu(){

    Menu menu("WYBOR STRUKTURY DANYCH");
    menu.addOption(MainMenuOptions::EXIT, "Zamknij program");
    menu.addOption(MainMenuOptions::OPEN_LIST_MODULE, "Lista dwukierunkowa");
    menu.addOption(MainMenuOptions::OPEN_ARRAY_MODULE, "Tablica dynamiczna");
    menu.addOption(MainMenuOptions::OPEN_HEAP_MODULE, "Kopiec");
    menu.addOption(MainMenuOptions::OPEN_BST_MODULE, "Drzewo wyszukiwan binarnych");
    menu.addOption(MainMenuOptions::GENERATE_RANDOM_DATA, "Wygeneruj plik z danymi losowymi");

    bool is_running = true;
    while (is_running){
        
        Console::clearScreen();         
        switch (menu.getUserChoice()){
            
            // Wyjście z aplikacji
            case MainMenuOptions::EXIT: is_running = false; break;

            // Przejście do menu listy
            case MainMenuOptions::OPEN_LIST_MODULE: Module::start(ModuleTypes::LIST_MODULE); break;

            // Przejście do menu tablicy
            case MainMenuOptions::OPEN_ARRAY_MODULE: Module::start(ModuleTypes::ARRAY_MODULE); break;

            // Przejście do menu kopca
            case MainMenuOptions::OPEN_HEAP_MODULE: Module::start(ModuleTypes::HEAP_MODULE); break;

            // Przejście do menu drzewa BST
            case MainMenuOptions::OPEN_BST_MODULE: Module::start(ModuleTypes::BST_MODULE); break;

            // Wygenerowanie losowych danych
            case MainMenuOptions::GENERATE_RANDOM_DATA: 
                RandomNumberGenerator::generateThenSaveIntegers("random-data.txt", 4, -1000, 1000); 
            break;

            // Nieznana opcja
            default: Console::waitForUserResponse(); break;
            
        }

    }

}
