#include "app/modules/ListModule.h"
#include "app/utility/Console.h"
#include "app/utility/RandomNumberGenerator.h"


// Opcje do wyboru w menu głównym
enum MainMenuOptions{
    EXIT,
    LIST_MODULE,
    ARRAY_MODULE,
    HEAP_MODULE,
    GENERATE_RANDOM_DATA
};

// Menu główne, pozwalające na wybór struktury, którą chcemy przetestować
void mainMenu();

// Menu działań dla listy dwukierunkowej
void listMenu();

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
    menu.addOption(MainMenuOptions::LIST_MODULE, "Lista dwukierunkowa");
    menu.addOption(MainMenuOptions::ARRAY_MODULE, "Tablica dynamiczna");
    menu.addOption(MainMenuOptions::GENERATE_RANDOM_DATA, "Wygeneruj plik z danymi losowymi");

    bool is_running = true;
    while (is_running){
        
        Console::clearScreen();         
        switch (menu.getUserChoice()){
            
            // Wyjście z aplikacji
            case MainMenuOptions::EXIT: is_running = false; break;

            // Przejście do menu listy
            case MainMenuOptions::LIST_MODULE: Module::start(ModuleTypes::LIST); break;

            // Przejście do menu tablicy
            case MainMenuOptions::ARRAY_MODULE: Module::start(ModuleTypes::ARRAY); break;

            // Przejście do menu kopca
            case MainMenuOptions::HEAP_MODULE: Module::start(ModuleTypes::HEAP); break;

            // Wygenerowanie losowych danych
            case MainMenuOptions::GENERATE_RANDOM_DATA: 
                RandomNumberGenerator::generateThenSaveIntegers("random-data.txt", 15, -1000, 1000); 
            break;

            // Nieznana opcja
            default: Console::waitForUserResponse(); break;
            
        }

    }

}
