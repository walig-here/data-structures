#include <fstream>

#include "app/utility/FileReader.h"

list<string>* FileReader::readAllLines( const string file_name ){

    // Sprawdzam, czy plik istnieje
    list<string>* list = nullptr;
    fstream file(file_name);
    if(!file.good()) return list;

    // Wczytuję kolejne linie
    list = new::list<string>();
    string line; 
    while( getline( file, line ) && !file.fail() ) list->push_back(line);
    
    // Zamykam plik
    file.close();
    return list;

}