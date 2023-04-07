#include "examinations/ListExamination.h"
#include "app/utility/Timer.h"
#include "app/utility/RandomNumberGenerator.h"

ExaminationRecord ListExamination::push_front(List list){
    
    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    list.push_front(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        PUSH_FRONT,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ListExamination::push_back(List list){

    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    list.push_back(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        PUSH_BACK,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ListExamination::add_element(List list){

    // Generuję nowy element oraz indeks
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();
    unsigned index = RandomNumberGenerator::getIntegers(1, 0, UINT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    list.add(new_element,index);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        ADD,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ListExamination::pop_front(List list){

    // Mierzę czas dodawnia elementu na początek
    Timer timer;
    timer.start();
    list.pop_front();
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        POP_FRONT,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ListExamination::pop_back(List list){

    // Mierzę czas
    Timer timer;
    timer.start();
    list.pop_back();
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        POP_BACK,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ListExamination::remove_element(List list){

    // Generuję indeks
    unsigned index = RandomNumberGenerator::getIntegers(1, 0, UINT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    list.remove(index);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        REMOVE,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ListExamination::find_element(List list){

    // Generuję szukany element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    list.find(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        LIST,
        FIND,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}