#define LINUX

#ifdef WINDOWS 
    #include <windows.h>
#endif
#include <iostream>

#include "app/Console.h"

void Console::clearScreen(){
    // Obsługa konsoli dla dystrybucji na system MS Windows
    #ifdef WINDOWS  
        system("cls");
    #endif
    // Obsługa konstoli dla dystrybucji na systemy Linux
    #ifdef LINUX
        system("clear");
    #endif
}

void Console::waitForUserResponse(){

    fflush(stdin);
    printf("Wcisnij dowolny klawisz, aby kontynuowac...");
    getchar(); getchar();

}