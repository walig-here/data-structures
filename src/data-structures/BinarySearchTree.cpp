#include "data-structures/BinarySearchTree.h"
#include <math.h>
#include <iostream>

Node::Node(){
    value = 0;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Node::Node(Node* parent, int value, Node* left, Node* right){

    this->parent = parent;
    this->value = value;
    this->left = left;
    this->right = right;

}

BinarySearchTree::BinarySearchTree(){

    root = nullptr;

}

BinarySearchTree::~BinarySearchTree(){

    

}

void BinarySearchTree::indexNodes(vector<Node*> &nodes, Node* node, int node_index){

    // Jeżeli obecny węzeł jest null to kończę zbieranie węzłów na tej gałęzi
    if(node == nullptr) return;

    // Rozszerzam wektor (o ile jest to potrzebne) i uzupełniam wszystkie nowe komórki wartościami null
    unsigned size = pow(2, floor(log2(node_index+1))+1) - 1;
    if(nodes.size() < size) {
        nodes.resize(size);
        for(int i = floor(size/2); i < size-1; i++) nodes[i] = nullptr;
    }
    
    // Dodaję obecny węzeł do wektora i preszukuję jego lewe i prawe poddrzewa
    nodes[node_index] = node;
    indexNodes(nodes, node->left, 2*node_index+1);
    indexNodes(nodes, node->right, 2*node_index+2);

}

void BinarySearchTree::print(){
    
    vector<Node*> nodes;
    indexNodes(nodes, root, 0);

    printf("Zawartosc drzewa:\n");

    if(nodes.size() == 0){
        printf("pusty\n");
        return;
    }

    // Jeżeli nie jest pusty to tworzymy graf przedstawiający kopiec
    unsigned height = 2*floor(log2(nodes.size()))+1;
    unsigned width = 2*pow(2, floor(log2(nodes.size()))) - 1;
    
    int p = width+1;
    int already_printed = 0;

    for(int y = 1; y <= height; y++){

        if(y%2 == 0) {
            printf("\n\n");
            continue;
        }

        for(int x = 1; x <= width; x++){

            
            if(x%p == p/2) {
                if(nodes[already_printed] != nullptr) printf("%4d", nodes[already_printed]->value);
                else printf("    ");
                already_printed++;
            }
            else printf("    ");

            if(already_printed == nodes.size()){
                printf("\n\n");
                return;
            }

        }
        if(y%2 == 1) p /= 2;
    }

}

void BinarySearchTree::add(int value){

    // Jeżeli drzewo jest puste, to nowy element staje się korzeniem
    if(root == nullptr){
        root = new Node(nullptr, value, nullptr, nullptr);
        return;
    }

    // Szukam rodzica dla nowego elementu. Przemieszczam się w dół drzewa (w lewo lub prawo w zależności od wartości rozważanego węzła).
    // Jeżeli trafię na węzeł, do którego można dołożyć potomka o zadanej wartości to końszę przerzukiwanie.
    Node* new_elemets_parent = root;
    while (new_elemets_parent != nullptr){
        
        if(new_elemets_parent->left == nullptr && value < new_elemets_parent->value){
            new_elemets_parent->left = new Node(new_elemets_parent, value, nullptr, nullptr);
            return;
        }
        if(new_elemets_parent->right == nullptr && value >= new_elemets_parent->value){
            new_elemets_parent->right = new Node(new_elemets_parent, value, nullptr, nullptr);
            return;
        }

        if(value >= new_elemets_parent->value) new_elemets_parent = new_elemets_parent->right;
        else new_elemets_parent = new_elemets_parent->left;

    }
    

}