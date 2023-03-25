
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

    // Równoważenie drzewea
    public: void balance();

};

enum BSTACtions{
    EXIT_BST
};