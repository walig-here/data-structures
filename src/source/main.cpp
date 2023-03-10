#include <cstdlib>
#include <stdio.h>

#include "data-structures/List.h"
#include "app/Menu.h"
#include "app/Console.h"

// Menu główne, pozwalające na wybór struktury, którą chcemy przetestować
void dataStructureChoice();


// Główna funkcja aplikacji
int main(int argc, char const *argv[])
{

    // Głowne menu aplikacji
    dataStructureChoice();
        
    // Poprawne zamknięcie
    return 0;
}


void dataStructureChoice(){

    const int EXIT = 1;
    const int LIST = 2;

    Menu menu("WYBOR STRUKTURY DANYCH");
    menu.addOption(EXIT, "Zamknij program");
    menu.addOption(LIST, "Lista dwukierunkowa");

    bool is_running = true;
    int user_choice;
    while (is_running){
        
        Console::clearScreen();         
        user_choice = menu.getUserChoice();

        switch (user_choice){
            
            // Wyjście z aplikacji
            case EXIT: is_running = false; break;
            // Lista
            case LIST: break;
            // Nieznana opcja
            default: Console::waitForUserResponse(); break;
        }
    }

}
