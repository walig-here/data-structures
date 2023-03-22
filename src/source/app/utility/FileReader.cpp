
#include <string>
#include <fstream>

#include "app/utility/FileReader.h"
#include "app/utility/StringParser.h"

list<string> FileReader::readAllLines( const string file_name ){

    // Sprawdzam, czy plik istnieje
    list<string> list;
    fstream file(file_name);
    if(!file.good()) return list;

    // Wczytuję kolejne linie
    string line; 
    while( getline( file, line ) && !file.fail() ) list.push_back(line);

    // Zamykam plik
    file.close();
    return list;

}


vector<int> FileReader::readAllIntegers( string file ){
    
    // Wczytuję dane z pliku
    list<string> lines = readAllLines(file);
    vector<int> integers;
    if(lines.size() == 0) return integers;

    // Wydzielam z poszczególnych linii kolejne liczby całkowite
    list<int> line_integers;
    for(auto line : lines){
        
        line_integers = StringParser::parseInt(line);
        if(line_integers.size() == 0) continue;

        for(auto integer : line_integers) integers.push_back(integer);
        line_integers.clear();

    }
    return integers;

}