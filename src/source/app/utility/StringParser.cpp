#include "app/utility/StringParser.h"

#include <sstream>

list<string>* StringParser::parse(string to_parse){

    // Sprawdzam, czy ciąg znaków nie jest pusty
    list<string>* words = nullptr;
    if(to_parse == "") return words;

    // Pobieram kolejne słowa ze stringa
    istringstream parser(to_parse);
    words = new::list<string>();
    string word;
    while(parser >> word) cout << "Wczytano: " << word << endl;
    return words;

}