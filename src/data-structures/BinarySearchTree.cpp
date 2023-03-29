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

void BinarySearchTree::rotateRight(int value){

    // Znaduję wierzchołek względem którego obracamy
    // Jeżeli nie istnieje lub nie ma lewego potomka to nie obracam
    Node* node = find(value);
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

void BinarySearchTree::rotateLeft(int value){

    // Znaduję wierzchołek względem którego obracamy
    // Jeżeli nie istnieje lub nie ma prawego potomka to nie obracam
    Node* node = find(value);
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

    // Jeżeli węzeł istnieje, to:
    // Gdy jest liściem, to po prostu odłączam go od drzewa i usuwam
    // Gdy ma jednego potomka, to w miejsce węzła wstawiam jego potomka
    // Gdy ma dwóch potomków, to kopiuje wartość następnika, a następnik usuwam
    if(node->left == nullptr && node->right == nullptr){

        Node* parent = node->parent;
        if(parent == nullptr) {
            delete root;
            root = nullptr;
            return;
        }

        if(parent->left == node) parent->left = nullptr;
        else parent->right = nullptr;
        delete node;
        return;

    }

    if(node->left != nullptr && node->right != nullptr){

        Node* successor = getSuccessor(node);
        int successor_value = successor->value;
        remove(successor_value);
        node->value = successor_value;
        return;

    }

    Node* child;
    if(node->left != nullptr) child = node->left;
    else child = node->right;
    child->parent = node->parent;
    if(node->parent == nullptr) {
        delete root;
        root = child;
        return;
    }
    if(node->parent->left == node) node->parent->left = child;
    else node->parent->right = child;
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

void BinarySearchTree::straighten(){

    // Wykonuje rotacje w prawo na każdym z węzłów, dopóki ma on swoich lewych potomków
    Node* current_node = root;
    while (current_node != nullptr){
        if(current_node->left == nullptr) current_node = current_node->right;
        else {
            rotateRight(current_node->value);
            current_node = current_node->parent;
        }
    }
    

}

void BinarySearchTree::balance(){

    // Etap I - prostowanie
    straighten();

    // Etap II - równoważenie
    // Wynonuję m-n rotacji w lewo zaczynając od korzenia co drugi wierzchołek
    unsigned size = 0;
    getSize(root, size);
    unsigned m = pow( 2, floor(log2(size+1)) ) - 1;

    // Dopóki m>=1 wykonuję m rotacji w lewo co drugi wierzchołek zaczynając od korzenia
    Node* current_node;
    while (m >= 1){

        current_node = root;
        for(int i = (size == 0 ? m : size - m); i > 0; i--){
            rotateLeft(current_node->value);
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