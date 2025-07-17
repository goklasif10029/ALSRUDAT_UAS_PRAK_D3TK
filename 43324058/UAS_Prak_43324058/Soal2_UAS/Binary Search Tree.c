/*
NIM : 43324058
Nama : Tio Febriyanti Simanjuntak
Nama Program : binary search tree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Fungsi membuat node baru
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi insert BST
Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Fungsi mencari node minimum
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi delete BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Fungsi inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int T[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(T)/sizeof(T[0]);
    Node* root = NULL;
    for(int i = 0; i < n; i++)
        root = insert(root, T[i]);

    // a. Hapus 6
    root = deleteNode(root, 6);
    // b. Tambah 9
    root = insert(root, 9);

    // c. Cetak inorder
    printf("InOrder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}