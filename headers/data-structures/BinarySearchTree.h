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

    //-----------------------------------------------------------------------
    // Konstruktor. Tworzy puste drzewo wyszukiwań binarnych.
    //-----------------------------------------------------------------------
    public: BinarySearchTree();


    //-----------------------------------------------------------------------
    // Konstruktor kopiujący.
    //-----------------------------------------------------------------------
    public: BinarySearchTree(BinarySearchTree* to_copy);


    //-----------------------------------------------------------------------
    // Konstruktor tworzący BST na podstawie zadanego ciągu liczb.
    // 
    // Parametry:
    // elements - ciąg liczb, z którego ma zostać zbudowane BST
    //-----------------------------------------------------------------------
    public: BinarySearchTree(vector<int> new_elements);


    //-----------------------------------------------------------------------
    // Destruktor. Zwalnia pamięć po BST.
    //-----------------------------------------------------------------------
    public: ~BinarySearchTree();


    //-----------------------------------------------------------------------
    // Wyświetla zawartość drzewa.
    //-----------------------------------------------------------------------
    public: void print();


    //-----------------------------------------------------------------------
    // Dodaje nowy element do drzewa.
    // 
    // Parametry:
    // value - nowa wartość, która ma zostać dodana do BST
    //-----------------------------------------------------------------------
    public: void add(int value);


    //-----------------------------------------------------------------------
    // Wyszukuje w BST element o wskazanej wartości i zwraca jego adres.
    // W wypadku nie znalezienia żadnego elementu zwróci nullptr.
    //
    // Parametry:
    // value - wartość, jaką ma mieć wyszukiwany element
    //-----------------------------------------------------------------------
    public: Node* find(int value);


    //-----------------------------------------------------------------------
    // Usuwa element o zadanej wartości z drzewa.
    //
    // Parametry:
    // value - wartość elementu, który ma zostać usunięty z drzewa.
    //-----------------------------------------------------------------------
    public: void remove(int value);

    //-----------------------------------------------------------------------
    // Wykonuje rotację w prawo względem wierzchołka o wskazanym adresie.
    // Jeżeli zostanie zadany nullptr, to rotacja się nie wykona.
    //
    // Parametry:
    // node - wierzchołek względem, którego ma zostać wykonana rotacja
    //-----------------------------------------------------------------------
    public: void rotateRight(Node* node);


    //-----------------------------------------------------------------------
    // Wykonuje rotację w lewo względem wierzchołka o wskazanym adresie.
    // Jeżeli zostanie zadany nullptr, to rotacja się nie wykona.
    //
    // Parametry:
    // node - wierzchołek względem, którego ma zostać wykonana rotacja
    //-----------------------------------------------------------------------
    public: void rotateLeft(Node* node);


    //-----------------------------------------------------------------------
    // Wykonuje na drzewie algorymt równoważący DSW.
    //-----------------------------------------------------------------------
    public: void balance();


    //-----------------------------------------------------------------------
    // Buduje na podstawie istniejących wierzchołków tablicę dynamiczną, 
    // dzięki czemu można wyświetlić drzewo ananlogicznie do kopca. Jest to
    // metoda rekurencyjna, która zbiera wierzchołki drzewa w konwencji 
    // inorder.
    //
    // Parametry:
    // nodes - tablica, w której znajdą się wierzchołki
    // node - wierzchołek, od którego zaczynamy spisywanie wierzchołków
    // node_index - indeks wierzchołka, od którego zaczynamy spisywanie
    //              wierzchołków
    //-----------------------------------------------------------------------
    private: void indexNodes(vector<Node*> &nodes, Node* node, int node_index=0);


    //-----------------------------------------------------------------------
    // Zwraca odniesienie do korzenia drzewa. W wypadku, gdy dzrewo jest
    // puste zwrócony zostanie nullptr.
    //
    // Zwraca:
    // Adres elementu, będącego korzeniem drzewa lub nullptr, gdy drzewo jest
    // puste.
    //-----------------------------------------------------------------------
    public: Node* getRoot() { return root; }


    //-----------------------------------------------------------------------
    // Zwraca odniesienie do maksymalnego wierzchołka drzewa o zadanym 
    // korzeniu. Jeżeli drzewo jest puste zwróci nullptr.
    //
    // Parametry:
    // root - korzeń, drzewa, które przeszukujemy
    //
    // Zwraca:
    // Adres maksymalnego wierzchołka we wskazanym drzewie.
    //-----------------------------------------------------------------------
    public: Node* maxNode(Node* root);


    //-----------------------------------------------------------------------
    // Zwraca odniesienie do minimalnego wierzchołka drzewa o zadanym 
    // korzeniu. Jeżeli drzewo jest puste zwróci nullptr.
    //
    // Parametry:
    // root - korzeń, drzewa, które przeszukujemy
    //
    // Zwraca:
    // Adres minimalnego wierzchołka we wskazanym drzewie.
    //-----------------------------------------------------------------------
    public: Node* minNode(Node* root);


    //-----------------------------------------------------------------------
    // Zwraca następnika wskazanego węzła.
    //
    // Parametry:
    // node - węzeł, którego następnika szukamy
    //
    // Zwraca:
    // Adres następnika wskazanego węzła.
    //-----------------------------------------------------------------------
    public: Node* getSuccessor(Node* node);


    //-----------------------------------------------------------------------
    // Metoda prostująca drzewo. Pierwszy etap algorytmu DSW.
    //
    // Zwraca:
    // Ilość wierzchołków prostowanego drzewa.
    //-----------------------------------------------------------------------
    private: unsigned straighten();

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