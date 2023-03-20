#include "data-structures/Heap.h"

Heap::Heap(){

}

Heap::~Heap(){

}

void Heap::print(){

    printf("Zawartosc kopca:\n");

    if(elements.getLength() == 0){
        printf("pusty");
        return;
    }

    for(int i = 0; i < elements.getLength(); i++){
        printf("%d ", *(elements[i]));
    }
    printf("\n");

}