#include "examinations/ArrayExamination.h"
#include "app/utility/Timer.h"
#include "app/utility/RandomNumberGenerator.h"

ExaminationRecord ArrayExamination::push_front(DynamicArray array, string filename){

    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas dodawnia elementu na początek
    Timer timer;
    timer.start();
    array.push_front(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        PUSH_FRONT,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}