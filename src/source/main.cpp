#include "app/utility/FileReader.h"
#include "app/modules/ListModule.h"
#include "app/utility/Console.h"
#include "app/utility/StringParser.h"

// Menu główne, pozwalające na wybór struktury, którą chcemy przetestować
void mainMenu();

// Menu działań dla listy dwukierunkowej
void listMenu();

// Główna funkcja aplikacji
int main(int argc, char const *argv[])
{

    list<string>* list = FileReader::readAllLines("plik.txt");
    if(list == nullptr) return 0;
    std::list<string>* words;
    for(auto line : *list) {
        cout << line << endl;
        words = StringParser::parse(line);
        for(auto word : *words) cout << "\t" << word << endl;
    }
    delete list;
    return 0;

    // Głowne menu aplikacji
    mainMenu();
        
    // Poprawne zamknięcie
    return 0;
}


void mainMenu(){

    const int EXIT = 1;
    const int LIST = 2;

    Menu menu("WYBOR STRUKTURY DANYCH");
    menu.addOption(EXIT, "Zamknij program");
    menu.addOption(LIST, "Lista dwukierunkowa");

    bool is_running = true;
    while (is_running){
        
        Console::clearScreen();         
        switch (menu.getUserChoice()){
            
            // Wyjście z aplikacji
            case EXIT: is_running = false; break;

            // Przejście do menu listy
            case LIST: Module::start(ModuleTypes::LIST); break;

            // Nieznana opcja
            default: Console::waitForUserResponse(); break;
            
        }

    }

}
