#include "data-structures/Heap.h"

Heap::Heap(){

}

Heap::Heap(vector<int> new_elements) : Heap() {

    if(new_elements.empty()) return;
    for(auto number : new_elements) elements.push_back(number);
    buildHeapFloyd();

}

Heap::Heap(Heap* copy) : Heap(){

    if(copy == nullptr) return;
    
    for(int i = 0; i < copy->elements.getLength(); i++)
        elements.push_back(*(copy->elements[i]));

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
                printf("%4d", *(elements[already_printed]));
                already_printed++;
            }
            else printf("    ");

            if(already_printed == elements.getLength()){
                printf("\n\n");
                return;
            }

        }
        if(y%2 == 1) p /= 2;
    }

}

bool Heap::pop_root(){

    // Z pustego nie można usunąć
    if(root() == nullptr) return false;

    // Kopiuje wartośc ostatniego elementu na pierwszą pozycję, usuwam ostatni elementu
    // Następnie naprawiam kopiec w dół
    *root() = *(elements[elements.getLength()-1]);
    elements.pop_back();
    repairDownwards(0);
    return true;

}

int* Heap::find(int value){

    // Jeżeli szukany element jest większy korzenia to na pewno nie występuje w kopcu
    if(value > *root()) return nullptr;
    return elements.find(value);

}

void Heap::add(int new_element){

    elements.push_back(new_element);
    repairUpwards(elements.getLength()-1);

}

int Heap::getMaxChildIndex(unsigned node_index){

    int* left_child = getLeftChild(node_index);
    int* right_child = getRightChild(node_index);

    // Jeżeli jest liściem to brak maksymalnego potomka
    if(left_child == nullptr && right_child == nullptr) return IS_LEAF;

    // Jeżeli ma jednego potomka to właśnie on jest maksimum
    if(left_child == nullptr) return RIGHT_CHILD_INDEX(node_index);
    if(right_child == nullptr) return LEFT_CHILD_INDEX(node_index);

    // W przeciwnym wypadku szukamy maksimum w sposób tradycyjny
    if(*left_child < *right_child) return RIGHT_CHILD_INDEX(node_index);
    return LEFT_CHILD_INDEX(node_index);

}

void Heap::repairUpwards(unsigned node_index){

    // Sprawdzam, czy wierzchołek nie jest korzeniem, wówczas kończe naprawę
    if( node_index == 0 ) return;

    // Sprawdzam, czy wierchołek jest maksymalnym potomkiem swojego rodzica
    // Jeżeli tak, to zamieniam go miejscami z rodzicem i kontynuuję naprawę
    // Jeżeli nie, to naprawę można zakończyć, gdyż warunek kopca jest na pewno spełniony
    if( node_index != getMaxChildIndex(PARENT_INDEX(node_index)) ) return;

    int* current_node = elements[node_index];
    int* parent = elements[PARENT_INDEX(node_index)];
    if(*parent >= *current_node) return;

    elements.swap(node_index, PARENT_INDEX(node_index));
    repairUpwards(PARENT_INDEX(node_index));

}

void Heap::repairDownwards(unsigned current_index){

    // Znajduję maksymalnego potomka
    // Jeżeli wierzchołek okaże się liściem (nie ma potomków) kończę naprawę
    int max_index = getMaxChildIndex(current_index);
    if(max_index == IS_LEAF) return;
    int* max = elements[max_index];
    int* current_node = elements[current_index];
    
    // Zamieniam miejscami rodzica z maksymalnym potomkiem, jeżeli zaburzony jest warunek kopca 
    // Kontynuuje naprawe kopca
    if( *max <= *current_node) return;
    elements.swap(max_index, current_index);
    repairDownwards(max_index);

}

void Heap::buildHeapFloyd(){

    // Pustego nie naprawiam
    if(elements.getLength() == 0) return;

    // Wybieram kolejnych rodziców i zamieniam miejscami z dziećmi, jeżeli nie jest spełniony warunek kopca
    int left_child;
    int right_child;
    for(int i = (elements.getLength()-1)/2; i >= 0; i--) {
        repairDownwards(i);
    }

}