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
    StructureType structure;    // type struktury
    OperationType operation;    // operacja
    double time_s;              // zmierzony czas w sekundach
    double time_ms;             // czas zmierzony w milisekundach
    double times_us;            // czas zmierzony w mikrosekundach

    // Konstruktor
    ExaminationRecord(StructureType structure, OperationType operation, double time_s, double time_ms, double time_us);

    // Zwraca rekord w formie ciągu znaków
    string getString();
};
