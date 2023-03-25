#include "data-structures/Heap.h"
#include <math.h>

Heap::Heap(bool max_heap){

    this->max_heap = max_heap;

}

Heap::~Heap(){

}

void Heap::print(){

    printf("Zawartosc kopca:\n");

    if(elements.getLength() == 0){
        printf("pusty\n");
        return;
    }

    // Jeżeli nie jest pusty to tworzymy graf przedstawiający kopiec
    unsigned height = 2*floor(log2(elements.getLength()))+1;
    unsigned width = 2*pow(2, floor(log2(elements.getLength()))) - 1;
    
    int p = width+1;
    int already_printed = 0;

    for(int y = 1; y <= height; y++){

        if(y%2 == 0) {
            printf("\n\n");
            continue;
        }

        for(int x = 1; x <= width; x++){

            if(x%p == p/2) {
                printf("[%4d]", *(elements[already_printed]));
                already_printed++;
            }
            else printf("     ");

            if(already_printed == elements.getLength()){
                printf("\n\n");
                return;
            }

        }
        if(y%2 == 1) p /= 2;
    }

}

void Heap::add(int new_element){

    elements.push_back(new_element);
    repair();

}

int Heap::getRightChild(unsigned index){
    return 2 * index + 2;     
}

int Heap::getLeftChild(unsigned index){
    return 2 * index + 1;
}

bool Heap::repairNode(int &parent_index, int &left_child_index, int &right_child_index){

    if(elements[parent_index] == nullptr) return false;

    int parent_value = *(elements[parent_index]);
    int child_index = -1;

    // Jeżeli kopiec jest maksymalny to rodzic zamienia się wartościami z większym wierzchołkiem
    // Jeżeli minimalny to z mniejszym
    if ( 
        elements[left_child_index] != nullptr &&
        (
            (max_heap && parent_value < *(elements[left_child_index])) || 
            (!max_heap && parent_value > *(elements[left_child_index]))
        )
    ) 
        child_index = left_child_index;
    else if ( 
        elements[right_child_index] != nullptr &&
        (
            (max_heap && parent_value < *(elements[right_child_index])) || 
            (!max_heap && parent_value > *(elements[right_child_index]))
        )
    )
        child_index = right_child_index;
    
    if(child_index == -1) return false;

    *(elements[parent_index]) = *(elements[child_index]);
    *(elements[child_index]) = parent_value;

    // Zamieniamy także w taki sposób, aby odzwiercielały nowy węzeł
    parent_index = child_index;
    left_child_index = getLeftChild(parent_index);
    right_child_index = getRightChild(parent_index);

    return true;

}

void Heap::repair(){

    // Pustego nie naprawiam
    if(elements.getLength() == 0) return;

    // Wybieram kolejnych rodziców i zamieniam miejscami z dziećmi, jeżeli nie jest spełniony warunek kopca
    int left_child;
    int right_child;
    for(int i = (elements.getLength()-1)/2; i >= 0; i--){

        left_child = getLeftChild(i);
        right_child = getRightChild(i);

        while (repairNode(i, left_child, right_child));

    }

}