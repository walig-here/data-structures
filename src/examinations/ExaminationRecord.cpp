#include "examinations/ExaminationRecord.h"
#include <string>

ExaminationRecord::ExaminationRecord(StructureType structure, OperationType operation, int element, long long additional_data, double time_us){

    this->structure = structure;
    this->operation = operation;
    this->element_value = element;
    this->additional_data = additional_data;
    this->times_us = time_us;

}

string ExaminationRecord::getString(){

    string record_to_string = "";
    
    // Strutkura
    switch (structure){
        case ARRAY:         record_to_string += "tablica";              break;
        case LIST:          record_to_string += "lista";                break;
        case HEAP:          record_to_string += "kopiec";               break;
        case BST:           record_to_string += "bst";                  break;
    }

    // Operacja
    switch (operation){
        case PUSH_FRONT:        record_to_string += ",dodaj na poczatek";           break;
        case PUSH_BACK:         record_to_string += ",dodaj na koniec";             break;
        case ADD:               record_to_string += ",dodaj";                       break;
        case POP_FRONT:         record_to_string += ",usun z poczatku";             break;
        case POP_BACK:          record_to_string += ",usun z konca";                break;
        case REMOVE:            record_to_string += ",usun";                        break;
        case FIND:              record_to_string += ",wyszukaj";                    break;
        case REMOVE_ROOT:       record_to_string += ",usun korzen";                 break;
        case FIND_BALANCED:     record_to_string += ",wyszukaj w zrownowazonym";    break;
        case FIND_UNBALANCED:   record_to_string += ",wyszukaj w niezbalansowanym"; break;
        case BALANCE:           record_to_string += ",zrownowaz";                   break;
    }

    // Czasy
    record_to_string += "," + to_string(element_value) + "," + to_string(additional_data) + "," + to_string(times_us);

    // Zwracam rekord
    return record_to_string;

}