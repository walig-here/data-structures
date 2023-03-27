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
    public: void rotateRight(int value);

    // Rotacja w lewo
    public: void rotateLeft(int value);

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

};

enum BSTACtions{
    EXIT_BST,
    ADD_BST,
    REMOVE_BST,
    ROTATE_LEFT,
    ROTATE_RIGHT
};