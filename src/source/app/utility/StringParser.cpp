#include "app/utility/StringParser.h"

#include <sstream>

list<string>* StringParser::parse(string to_parse){

    // Sprawdzam, czy ciąg znaków nie jest pusty
    list<string>* words = nullptr;
    if(to_parse == "") return words;

    // Pobieram kolejne wyrazy z ciągu znaków
    istringstream parser(to_parse);
    words = new::list<string>();
    string word;
    while( parser >> word ) words->push_back(word);
    return words;

}

list<int>* StringParser::parseInt(string to_parse){

    // Spośród wyrazów zawartych w ciągu znaków wybieram te, które są liczbami całkowitymi
    list<string>* words = parse(to_parse);
    list<int>* integers = nullptr;
    if(words == nullptr) return integers;

    integers = new::list<int>; 
    for(auto word : *words){
        try{
            integers->push_back( stoi(word) );
        }catch(invalid_argument){
            continue;
        }
    }

    // Jeżeli linia nie zawierała żandych liczb to zwracam nullptr
    if(integers->size() == 0){
        delete integers;
        integers = nullptr;
    }
    return integers;

}