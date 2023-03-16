#include "app/utility/RandomNumberGenerator.h"
#include "app/utility/FileWriter.h"

list<int>* RandomNumberGenerator::getIntegers(long long unsigned count, long long int min, long long int max){

    // Sprawdzam, czy zadana ilość liczb jest niezerowa
    list<int>* list = nullptr;
    if(count == 0) return list;

    // Dokonuję ewentualnej poprawki wybranego przedziału
    if(min > max) swap(min, max);

    // Generuję liczby
    list = new::list<int>;
    random_device seed;
    mt19937 generator(seed());
    uniform_int_distribution<> distribution(min, max);

    for(int i = 0; i < count; i++) list->push_back(distribution(generator));
    return list;

}

bool RandomNumberGenerator::generateThenSaveIntegers(string file, long long unsigned count, long long int min, long long int max){

    list<int>* integers = getIntegers(count, min, max);
    if(integers == nullptr) return false;
    integers->push_front(count);
    if(FileWriter::saveInt(integers, file)){
        delete integers;
        return true;
    }
    delete integers;
    return false;

}