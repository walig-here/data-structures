#pragma once
#include <iostream>

using namespace std;

// Klasa obsługująca konstolę systemową
class Console{
    
    /* POLE */
    private: const static string INVALID_FORMAT;

    /* METODY */
    
    // Funkcja czyszcząca konsolę
    public: static void clearScreen();

    // Funkcja czekająca na wprowadzenie ENTER
    public: static void waitForUserResponse();

    // Funckja pobierająca od użytkownika liczę typu int
    public: static int getIntInput(string msg = "");

};