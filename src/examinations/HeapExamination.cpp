#include "examinations/HeapExamination.h"
#include "app/utility/Timer.h"
#include "app/utility/RandomNumberGenerator.h"

ExaminationRecord HeapExamination::add_element(Heap heap){

    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    heap.add(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        HEAP,
        ADD,
        new_element,
        0,
        timer.getResult(microseconds)
    };

}

ExaminationRecord HeapExamination::remove_element(Heap heap){

    // Mierzę czas
    Timer timer;
    timer.start();
    heap.pop_root();
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        HEAP,
        REMOVE_ROOT,
        0,
        0,
        timer.getResult(microseconds)
    };

}

ExaminationRecord HeapExamination::find_element(Heap heap){

    // Generuję szukany element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    heap.find(new_element);
    timer.stop();

    bool exist = heap.find(new_element) != nullptr;

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        HEAP,
        FIND,
        new_element,
        exist,
        timer.getResult(microseconds)
    };

}