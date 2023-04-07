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

BinarySearchTree::BinarySearchTree(BinarySearchTree* to_copy) : BinarySearchTree() {

    // Jako że jest to de facto wczytywanie, to wykorzystuję funkcję używającą vector, którą wykorzystałem także
    // przy wyświetlaniu drzewa.
    vector<Node*> nodes;
    to_copy->indexNodes(nodes, to_copy->getRoot(), 0);

    // Kopiuję wszystkie elementy z wektora (niezerowe)
    for(auto node : nodes){
        if(node == nullptr) continue;
        add(node->value);
    }

}

BinarySearchTree::BinarySearchTree(vector<int> new_elements) : BinarySearchTree() {

    if(new_elements.empty()) return;
    for(auto number : new_elements) {
        add(number);
    }

}

BinarySearchTree::~BinarySearchTree(){

    while(root != nullptr) {
        remove(root->value);
    }

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

Node* BinarySearchTree::find(int value){

    // Przeszukuję drzewo w dół zaczynając od korzenia, rozważając kolejne wierzchołki.
    // Jeżeli szukany element jest większy od aktualnego elementu, to szukam go w prawym poddrzewie
    // Jeżeli mniejszy, to szukam go w lewym poddrzewie
    // Jeżeli jest równy to kończymy przeszukiwanie
    Node* current_node = root;
    while (current_node != nullptr){
        
        if(current_node->value == value) return current_node;
        
        if(value < current_node->value) current_node = current_node->left;
        else current_node = current_node->right;

    }
    return nullptr;
    

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

void BinarySearchTree::rotateRight(Node* node){

    // Znaduję wierzchołek względem którego obracamy
    // Jeżeli nie istnieje lub nie ma lewego potomka to nie obracam
    if(node == nullptr || node->left == nullptr) return;
    Node* left_tree_root = node->left;

    // Obracam
    node->left = left_tree_root->right;
    if(node->left != nullptr) node->left->parent = node;
    left_tree_root->right = node;
    left_tree_root->parent = node->parent;
    node->parent = left_tree_root;

    // Naprawiamy rodzica obracanego wierzchołka
    if(left_tree_root->parent == nullptr) {
        root = left_tree_root; 
        return; 
    }

    if(left_tree_root->value < left_tree_root->parent->value) left_tree_root->parent->left = left_tree_root;
    else left_tree_root->parent->right = left_tree_root;

}

void BinarySearchTree::rotateLeft(Node* node){

    // Znaduję wierzchołek względem którego obracamy
    // Jeżeli nie istnieje lub nie ma prawego potomka to nie obracam
    if(node == nullptr || node->right == nullptr) return;
    Node* right_tree_root = node->right;

    // Obracam
    node->right = right_tree_root->left;
    if(node->right != nullptr) node->right->parent = node;
    right_tree_root->left = node;
    right_tree_root->parent = node->parent;
    node->parent = right_tree_root;

    // Naprawiamy rodzica obracanego wierzchołka
    if(right_tree_root->parent == nullptr){
        root = right_tree_root;
        return;
    }

    if(right_tree_root->value < right_tree_root->parent->value) right_tree_root->parent->left = right_tree_root;
    else right_tree_root->parent->right = right_tree_root;

}

Node* BinarySearchTree::maxNode(Node* root){

    // W pustym drzewie nie szukamy
    if(root == nullptr) return nullptr;

    // Zwracamy najbardziej wysunięty na prawo wierzchołek
    Node* maximum = root;
    while ( maximum->right != nullptr ) maximum = maximum->right;
    return maximum;    

}

void BinarySearchTree::remove(int value){

    // Znajduje wskazywany węzeł. Jeżeli nie ma takiego w drzewie to nie usuwam.
    Node* node = find(value);
    if(node == nullptr) return;

    // Jeżeli węzeł ma jakichkolwiek potomków, to de facto należy usunąć jego następnik
    // Jednocześnie klucz z następnika należy przekopiować do usuwanego węzła
    if(node->left != nullptr || node->right != nullptr){
        Node* succesor = getSuccessor(node);
        if(succesor != nullptr){
            node->value = succesor->value;
            node = succesor;
        }
    }

    // W tym momencie węzeł może być już wyłącznie liściem lub mieć jednego potomka
    // Jeżeli jest liściem, to po prostu odłączamy go od drzewa, przy czym gdy był to korzeń, to drzewo staje się puste
    if(node->left == nullptr && node->right == nullptr){
        Node* node_parent = node->parent;

        if(node_parent != nullptr && node_parent->left == node) node_parent->left = nullptr;
        else if(node_parent != nullptr) node_parent->right = nullptr;
        else root = nullptr;

        delete node;
        return;
    }

    // Jeżeli ma jednego potomka, to przepinamy potomka do rodzica usuwanego elementu i usuwamy element
    // Jeżeli jednak usuwany element był korzeniem, to potomek staje się nowym korzeniem 
    Node* child;
    Node* parent = node->parent;
    if(node->left != nullptr) child = node->left;
    else child = node->right;

    if(parent != nullptr && parent->left == node) parent->left = child;
    else if(parent != nullptr) parent->right = child;
    else root = child;

    child->parent = parent;

    delete node;
}

Node* BinarySearchTree::minNode(Node* root){

    // W pustym drzewie nie szukamy
    if(root == nullptr) return nullptr;

    // Zwracamy najbardziej wysunięty na lewo wierzchołek
    Node* minimum = root;
    while ( minimum->left != nullptr ) minimum = minimum->left;
    return minimum;  

}

Node* BinarySearchTree::getSuccessor(Node* node){

    // W pustym drzewie nie szukam
    if(root == nullptr) return nullptr;

    // Jeżeli ma prawe poddrzewo, to następnik jest maksium tego poddrzewa
    // W przeciwnym wypadku następnik jest pierwszym węzłem większym od tego węzła
    Node* successor = minNode(node->right);
    if(successor != nullptr) return successor;

    successor = node->parent;
    while (successor != nullptr){
        if(successor->value > node->value) break;
        successor = successor->parent;
    }
    return successor;

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

unsigned BinarySearchTree::straighten(){

    // Wykonuje rotacje w prawo na każdym z węzłów, dopóki ma on swoich lewych potomków
    Node* current_node = root;
    unsigned size = 0;
    while (current_node != nullptr){
        if(current_node->left == nullptr) {
            current_node = current_node->right;
            size++;
        }
        else {
            rotateRight(current_node);
            current_node = current_node->parent;
        }
    }
    return size;
}

void BinarySearchTree::balance(){

    // Etap I - prostowanie
    unsigned size = straighten();

    // Etap II - równoważenie
    // Wynonuję m-n rotacji w lewo zaczynając od korzenia co drugi wierzchołek
    unsigned m = pow( 2, floor(log2(size+1)) ) - 1;

    // Dopóki m>=1 wykonuję m rotacji w lewo co drugi wierzchołek zaczynając od korzenia
    Node* current_node;
    while (m >= 1){

        current_node = root;
        for(int i = (size == 0 ? m : size - m); i > 0; i--){
            rotateLeft(current_node);
            if(current_node->parent != nullptr) current_node = current_node->parent->right;
        }

        m = floor(m/2);
        size = 0;

    }
    

}

void BinarySearchTree::getSize(Node* root, unsigned& size){

    if(root == nullptr) return;
    size++;
    getSize(root->left, size);
    getSize(root->right, size); 

}