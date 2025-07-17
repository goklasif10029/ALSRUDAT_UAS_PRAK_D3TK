#ifndef BAT_H
#define BAT_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Deklarasi fungsi
Node* insert(Node* root, int data);
Node* deleteNode(Node* root, int data);
void inorder(Node* root);

#endif
