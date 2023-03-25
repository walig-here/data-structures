#include <list>
#include <iostream>

using namespace std;

// Klasa służąca do zapisu danych do pliku
class FileWriter{

    /* METODY */

    // Konstruktor
    private: FileWriter() {}

    // Destruktor
    private: ~FileWriter() {}

    // Zapisuje dane liczbowe do pliku
    public: static bool saveInt(list<int> integers, string file);

    // Zapisuje dane alfanumeryczne do pliku
    public: static bool save(list<string> lines, string file);

};
