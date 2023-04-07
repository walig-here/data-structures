#pragma once
#include <vector>

using namespace std;

/* Struktura reprezentująca węzeł drzewa BST */
struct Node{

    /* POLA */
    int value;          // wartość węzła (klucz)
    Node* parent;       // wskaźnik na rodzica
    Node* left;         // wskaźnik na lewego potomka
    Node* right;        // wskaźnik na prawego potomka

    /* METODY */

    // Kosntruktor domyślny
    Node();

    // Konstruktor z parametrami
    Node(Node* parent, int value, Node* left, Node* right);

};


/* Klasa reprezentująca drzewo wyszukiwań binarnych (BST) */
class BinarySearchTree{

    /* POLA */
    private: Node* root;    // korzeń drzewa

    /* METODY */

    // Konstruktor
    public: BinarySearchTree();

    // Konstruktor kopiujący
    public: BinarySearchTree(BinarySearchTree* to_copy);

    // Konstruktor pobierający ciąg liczb
    public: BinarySearchTree(vector<int> new_elements);

    // Destruktor
    public: ~BinarySearchTree();

    // Wyświetlanie drzewa
    public: void print();

    // Dodanie elementu
    public: void add(int value);

    // Wyszukanie elementu
    public: Node* find(int value);

    // Usunięcie elementu
    public: void remove(int value);

    // Rotacja w prawo
    public: void rotateRight(Node* node);

    // Rotacja w lewo
    public: void rotateLeft(Node* node);

    // Równoważenie drzewa
    public: void balance();

    // Zwraca tablicę pozwalającą na na poprawne wyświetlenie drzewa (jak kopca)
    private: void indexNodes(vector<Node*> &nodes, Node* node, int node_index);

    // Zwraca korzeń
    public: Node* getRoot() { return root; }

    // Zwraca węzeł maksymalny z drzewa o podanym korzeniu
    public: Node* maxNode(Node* root);

    // Zwraca węzeł minimalny z drzewa o podanym korzewniu
    public: Node* minNode(Node* root);

    // Zwraca następnika wskazanego węzła
    public: Node* getSuccessor(Node* node);

    // Prostuje drzewo
    private: unsigned straighten();

    // Zlicza ilość wierzchołków drzewa o zadanym korzeniu
    public: void getSize(Node* root, unsigned& tree_size);

};

enum BSTACtions{
    EXIT_BST,
    EXAMINE_BST,
    ADD_BST,
    REMOVE_BST,
    ROTATE_LEFT,
    ROTATE_RIGHT,
    FIND_BST,
    BALANCE_BST,
    LOAD_BST
};