#include "data-structures/BinarySearchTree.h"
#include "gtest/gtest.h"

// Test dodawania do pustego drzewa
TEST(Add, AddEmptyTree){

    BinarySearchTree tree;
    int value = 45;
    tree.add(value);

    Node* node = tree.getRoot();
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, value);

}

// Test dodawania do niepustego drzewa
TEST(Add, AddNonEmptyTree){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);

    // 45
    Node* node = tree.getRoot();
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

//----------------------------------------------------------------------------------------------------------------------

// Test znajdowania elementu w pustej liście
TEST(Find, FindInEmptyTree){

    BinarySearchTree tree;
    Node* node = tree.find(0);

    ASSERT_EQ(node, nullptr);

}

// Test znajdowania elementu w niepustej liście, gdy ten w niej nie występuje
TEST(Find, FindInNonEmptyTreeElementNotExist){

    BinarySearchTree tree;
    tree.add(46); tree.add(89); tree.add(41);
    Node* node = tree.find(0);

    ASSERT_EQ(node, nullptr);

}

// Test znajdowania elementu w niepustej liście, gdy ten w niej występuje
TEST(Find, FindInNonEmptyTreeElementExist){

    BinarySearchTree tree;
    int value = 41;
    tree.add(46); tree.add(89); tree.add(value);
    Node* node = tree.find(value);

    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, value);

}

//----------------------------------------------------------------------------------------------------------------------

TEST(RotateRight, RotateNodeNotExist){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.rotateRight(-5);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

TEST(RotateRight, RotateNodeExist){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.rotateRight(21);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 18);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 21);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

//----------------------------------------------------------------------------------------------------------------------

TEST(RotateLeft, RotateNodeExist){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.rotateLeft(45);

    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 82);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 45);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

TEST(RotateLeft, RotateNodeNotExist){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.rotateLeft(-5);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.getRoot();
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

//----------------------------------------------------------------------------------------------------------------------

// Znalezienie maksimum w pustym drzewie
TEST(FindMax, FindInEmpty){

    BinarySearchTree tree;
    Node* maximum = tree.maxNode(tree.getRoot());

    ASSERT_EQ(maximum, nullptr);

}

// Znalezienie maskumum w niepustym drzewie
TEST(FindMax, FindInNonEmpty){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    Node* maxium = tree.maxNode(tree.getRoot());

    ASSERT_NE(maxium, nullptr);
    ASSERT_EQ(maxium->value, 145);

}

// Znalezienie maksimum w niepustym poddrzewie
TEST(FindMax, FinInNonEmptySubTree){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    Node* maxium = tree.maxNode(tree.find(21));

    ASSERT_NE(maxium, nullptr);
    ASSERT_EQ(maxium->value, 28);

}

//----------------------------------------------------------------------------------------------------------------------

// Znalezienie maksimum w pustym drzewie
TEST(FindMin, FindInEmpty){

    BinarySearchTree tree;
    Node* minimum = tree.minNode(tree.getRoot());

    ASSERT_EQ(minimum, nullptr);

}

// Znalezienie maskumum w niepustym drzewie
TEST(FindMin, FindInNonEmpty){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    Node* minimum = tree.minNode(tree.getRoot());

    ASSERT_NE(minimum, nullptr);
    ASSERT_EQ(minimum->value, 1);

}

// Znalezienie maksimum w niepustym poddrzewie
TEST(FindMin, FinInNonEmptySubTree){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    Node* minimum = tree.minNode(tree.find(22));

    ASSERT_NE(minimum, nullptr);
    ASSERT_EQ(minimum->value, 22);

}

//----------------------------------------------------------------------------------------------------------------------

// Znalezienie następnika w pustym drzewie
TEST(FindSuccessor, EmptyTree){

    BinarySearchTree tree;
    Node* successor = tree.getSuccessor(tree.getRoot());

    ASSERT_EQ(successor, nullptr);

}

// Znalezienie następnika w drzewie 1-elementowym
TEST(FindSuccessor, OneElementTree){

    BinarySearchTree tree;
    tree.add(45);
    Node* successor = tree.getSuccessor(tree.getRoot());

    ASSERT_EQ(successor, nullptr);

}

// Znalezienie następnika dla elementu posiadającego prawe poddrzewo
TEST(FindSuccessor, SuccessorOfElementWithLeftSubtree){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    Node* successor = tree.getSuccessor(tree.find(21));

    ASSERT_NE(successor, nullptr);
    ASSERT_EQ(successor->value, 22);

}

// Znalezienie następnik dla elementu bez prawego poddrzewa
TEST(FindSuccessor, SuccessorOfElementWithNoLeftSubtree){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    Node* successor = tree.getSuccessor(tree.find(18));

    ASSERT_NE(successor, nullptr);
    ASSERT_EQ(successor->value, 21);

}

//----------------------------------------------------------------------------------------------------------------------

// Usuwanie z pustego drzewa
TEST(Remove, EmptyTree){

    BinarySearchTree tree;
    tree.remove(45);

    ASSERT_EQ(tree.getRoot(), nullptr);

}

// Usuwanie elementu, który nie występuje w drzewie
TEST(Remove, NonExistingElement){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.remove(666);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

// Usunięcie liścia
TEST(Remove, RemoveLeaf){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.remove(18);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

// Usunięcie elementu z jednym potomkiem
TEST(Remove, RemoveParentWithOneChild){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.remove(145);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 21);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 82);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 21);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

// Usunięcie elementu z dwoma potomkami
TEST(Remove, RemoveParentWithBothChildren){

    BinarySearchTree tree;
    tree.add(45); 
    tree.add(145); 
    tree.add(21);
    tree.add(1);
    tree.add(22);
    tree.add(28);
    tree.add(18);
    tree.add(82);
    tree.remove(21);

    // Nic nie powinno się zmienić
    // 45
    Node* node = tree.find(45);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 45);
    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 22);
    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 145);
    ASSERT_EQ(node->parent, nullptr);       // rodzic

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 145);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 82);

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 21
    node = tree.find(21);
    ASSERT_EQ(node, nullptr);

    // 1
    node = tree.find(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 1);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 18);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 22);

    ASSERT_NE(node->left, nullptr);         // lewy
    ASSERT_EQ(node->left->value, 1);

    ASSERT_NE(node->right, nullptr);        // prawy
    ASSERT_EQ(node->right->value, 28);

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 45);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 82);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 145);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 18);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 1);

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 28);

    ASSERT_EQ(node->left, nullptr);         // lewy

    ASSERT_EQ(node->right, nullptr);        // prawy

    ASSERT_NE(node->parent, nullptr);       // rodzic
    ASSERT_EQ(node->parent->value, 22);

}

TEST(Balance, BalanceTree){

    BinarySearchTree tree;
    Node* node;
    tree.add(45);
    tree.add(21);
    tree.add(145);
    tree.add(1);
    tree.add(22);
    tree.add(18);
    tree.add(28);
    tree.add(82);
    tree.balance();

    // 28
    node = tree.find(28);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 28);
    
    ASSERT_NE(node->left, nullptr) ;    // lewy
    ASSERT_EQ(node->left->value, 21);   

    ASSERT_NE(node->right, nullptr);    // prawy
    ASSERT_EQ(node->right->value, 82);

    ASSERT_EQ(node->parent, nullptr);   // rodzic

    // 21
    node = tree.find(21);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 21);
    
    ASSERT_NE(node->left, nullptr) ;    // lewy
    ASSERT_EQ(node->left->value, 18);   

    ASSERT_NE(node->right, nullptr);    // prawy
    ASSERT_EQ(node->right->value, 22);

    ASSERT_NE(node->parent, nullptr);   // rodzic
    ASSERT_EQ(node->parent->value, 28);

    // 82
    node = tree.find(82);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 82);
    
    ASSERT_NE(node->left, nullptr) ;    // lewy
    ASSERT_EQ(node->left->value, 45);   

    ASSERT_NE(node->right, nullptr);    // prawy
    ASSERT_EQ(node->right->value, 145);

    ASSERT_NE(node->parent, nullptr);   // rodzic
    ASSERT_EQ(node->parent->value, 28);

    // 18
    node = tree.find(18);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 18);
    
    ASSERT_NE(node->left, nullptr) ;    // lewy
    ASSERT_EQ(node->left->value, 1);   

    ASSERT_EQ(node->right, nullptr);    // prawy

    ASSERT_NE(node->parent, nullptr);   // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 22
    node = tree.find(22);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 22);
    
    ASSERT_EQ(node->left, nullptr) ;    // lewy 

    ASSERT_EQ(node->right, nullptr);    // prawy

    ASSERT_NE(node->parent, nullptr);   // rodzic
    ASSERT_EQ(node->parent->value, 21);

    // 45
    node = tree.find(45);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 45);
    
    ASSERT_EQ(node->left, nullptr) ;    // lewy 

    ASSERT_EQ(node->right, nullptr);    // prawy

    ASSERT_NE(node->parent, nullptr);   // rodzic
    ASSERT_EQ(node->parent->value, 82);

    // 145
    node = tree.find(145);
    ASSERT_NE(node, nullptr);           // wierzchołek
    ASSERT_EQ(node->value, 145);
    
    ASSERT_EQ(node->left, nullptr) ;    // lewy 

    ASSERT_EQ(node->right, nullptr);    // prawy

    ASSERT_NE(node->parent, nullptr);   // rodzic
    ASSERT_EQ(node->parent->value, 82);

}

// Entry point modułu testującego klasę Arithmetic
int main(int argc, char const *argv[])
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}