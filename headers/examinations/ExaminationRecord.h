#include <iostream>

using namespace std;

/**
 * Typy struktur
*/
enum StructureType{
    ARRAY,
    LIST,
    HEAP,
    BST
};

/**
 * Typy operacji
*/
enum OperationType{
    PUSH_FRONT,
    PUSH_BACK,
    ADD,
    POP_FRONT,
    POP_BACK,
    REMOVE,
    REMOVE_ROOT,
    FIND,
    BALANCE,
    FIND_UNBALANCED,
    FIND_BALANCED
};

/**
 * Rekord zapisujący dane nt przeprowadzonego badania
*/
struct ExaminationRecord{
    StructureType structure;        // typ struktury
    OperationType operation;        // operacja
    int element_value;              // wartość używanego w teście eksperytmentu
    long long additional_data;      // dodadkowe dane
    double times_us;                // czas zmierzony w mikrosekundach

    // Konstruktor
    ExaminationRecord(StructureType structure, OperationType operation, int element, long long additional_data, double time_us);

    // Zwraca rekord w formie ciągu znaków
    string getString();
};
