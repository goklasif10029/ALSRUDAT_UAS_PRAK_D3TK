/* 
    NIM             : 43324025
    Nama            : Rahel Damayanti Panjaitan
    Nama Program    : binary search tree ( header )
*/

#ifndef BST_H
#define BST_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Primitif
Node* insert(Node* root, int data);
Node* delete(Node* root, int data);
void inorderTraversal(Node* root);
Node* createNode(int data);
Node* findMin(Node* root);

#endif
