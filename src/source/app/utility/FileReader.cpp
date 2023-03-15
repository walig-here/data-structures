
#include <string>
#include <fstream>

#include "app/utility/FileReader.h"
#include "app/utility/StringParser.h"

list<string>* FileReader::readAllLines( const string file_name ){

    // Sprawdzam, czy plik istnieje
    list<string>* list = nullptr;
    fstream file(file_name);
    if(!file.good()) return list;

    // Wczytuję kolejne linie
    list = new::list<string>();
    string line; 
    while( getline( file, line ) && !file.fail() ) list->push_back(line);
    
    // Jeżeli w pliku nie było żadnych linni (lista pusta), to zwalnia miejsce po liście
    if(list->size() == 0){
        delete list;
        list = nullptr;
    }

    // Zamykam plik
    file.close();
    return list;

}


vector<int>* FileReader::readAllIntegers( string file ){
    
    // Wczytuję dane z pliku
    list<string>* lines = readAllLines(file);
    vector<int>* integers = nullptr;
    if(lines == nullptr) return integers;

    // Wydzielam z poszczególnych linii kolejne liczby całkowite
    integers = new::vector<int>();
    list<int>* line_integers;
    for(auto line : *lines){
        
        line_integers = StringParser::parseInt(line);
        if(line_integers == nullptr) continue;

        for(auto integer : *line_integers) integers->push_back(integer);
        delete line_integers;

    }
    delete lines;

    // Jeżeli nie wczytano żadnych liczb całkowitych to zwracamy nullptr
    if( integers->size() == 0 ){
        delete integers;
        integers = nullptr;
    }
    return integers;

}