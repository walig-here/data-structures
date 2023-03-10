#include "app/Menu.h"

using namespace std;

// Typy modułów
enum ModuleTypes{
    LIST
};

// Klasa służąca do obługi modułów aplikacji
class Module{

    /* POLA */
    protected: Menu* menu;    // menu modułu
    protected: const static string INSERT_NEW_EMENT_VALUE;

    /* METODY */

    // Otwiera wskazany moduł
    public: static void start(ModuleTypes type);

    // Konstruktor
    protected: Module(const string menu_header);

    // Destruktor
    protected: virtual ~Module();

    // Obsługa pętli
    private: virtual void loop() = 0;

};