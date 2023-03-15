#include <iostream>
#include <list>

using namespace std;

// Klasa wyłuskująca z ciągu znaków pojedyńcze wyrazy
class StringParser{

    /* METODY */

    // Konstruktor
    private: StringParser() {};

    // Destrutkor
    private: ~StringParser() {};

    /// @brief
    /// Wydziela z ciągu znaków pojedyńcze wyrazy.
    ///
    /// @param to_parse ciąg znaków, z którego będziemy wydzielać wyrazy
    ///
    /// @return
    /// Listę wydzielonych wyrazów lub nullptr w wypadku podania pustego ciągu znaków.
    public: static list<string>* parse(string to_parse);

};