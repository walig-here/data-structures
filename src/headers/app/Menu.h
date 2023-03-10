#include <list>
#include <iostream>

using namespace std;

// Struktura reprezentująca jedną pozycję z menu
struct MenuElement{

    string desc;            // opis opcji
    unsigned int token;     // symbol, który należy wprowadzić, aby wybrać tę opcję

    // Konstruktor
    MenuElement(const unsigned int token, const string desc){
        this->desc = desc;
        this->token = token;
    };

};

// Klasa reprezentująca menu wyboru opcji przez użytkownika
class Menu{

    /* POLA */
    private: list<MenuElement*> options;       // opcje dostępne w menu
    private: string header;                   // nagłówek w menu


    /* METODY */

    // Konstruktor
    public: Menu(string header = "Menu");


    // Destruktor
    public: ~Menu();


    // Dodanie opcji do menu
    public: void addOption(const unsigned int token, string desc = "");


    // Wyświetlenie menu
    private: void print();


    // Pobranie wyboru od użytkownika
    public: int getUserChoice();

    //-----------------------------------------------------------------------
    // Sprawdza, czy zadany symbol w formie ciągu znaków jest poprawny. Jeśli
    // symbol jest niepoprawny to zwróci wartość -1. W przeciwnym wypadku
    // zwróci zadany symbol w poprawnym formacie (liczba całkowita).
    // 
    // Parametry:
    // token - symbol, który zostanie sprawdzony
    //-----------------------------------------------------------------------
    private: int isValidToken(const string token);

};