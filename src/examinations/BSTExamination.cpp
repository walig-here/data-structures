#include "examinations/BSTExamination.h"
#include "app/utility/Timer.h"
#include "app/utility/RandomNumberGenerator.h"

 ExaminationRecord BSTExamination::add_element(BinarySearchTree *tree){

    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    tree->add(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        BST,
        ADD,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

 }

 ExaminationRecord BSTExamination::remove_element(BinarySearchTree *tree){

    // Generuję element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    tree->remove(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        BST,
        REMOVE,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

 }

 ExaminationRecord BSTExamination::find_element_unbalanced(BinarySearchTree *tree){

    // Generuję element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    tree->find(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        BST,
        FIND_UNBALANCED,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

 }

 vector<ExaminationRecord> BSTExamination::find_element_balanced(BinarySearchTree *tree){

    // Generuję element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();
    
    // Mierzę czas równoważenia
    Timer timer;
    timer.start();
    tree->balance();
    timer.stop();
    ExaminationRecord balance_record(
        BST,
        BALANCE,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    );
    
    timer.start();
    tree->find(new_element);
    timer.stop();
    ExaminationRecord find_record(
        BST,
        FIND_BALANCED,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    );

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        balance_record,
        find_record
    };

 }