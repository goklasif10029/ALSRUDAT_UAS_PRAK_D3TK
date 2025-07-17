/*
Nama : Christina Jenny Elisha Simanjuntak
NIM : 43324056
Nama Program : binary search tree
*/

#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Fungsi untuk membuat node baru
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi insert ke BST
Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Fungsi untuk mencari node minimum
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi untuk menghapus node dari BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node dengan satu atau tidak ada anak
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node dengan dua anak: ambil inorder successor
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// InOrder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Buat BST dari {1,4,5,6,11,12,20}
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    Node* root = NULL;
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    // a. Hapus 6
    root = deleteNode(root, 6);

    // b. Tambah 9
    root = insert(root, 9);

    // c. Tampilkan inorder
    printf("Hasil InOrder setelah operasi:\n");
    inorder(root);
    printf("\n");

    return 0;
}
