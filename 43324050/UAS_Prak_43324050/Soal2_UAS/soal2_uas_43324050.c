/*
NIM  : 43324050
Nam  : Tania Mutiara Panjaitan
prodi : D3 Teknologi Komputer 
*/

#include <stdio.h>
#include <stdlib.h>

// Struktur Node BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Fungsi buat node baru
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert ke BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// InOrder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Fungsi cari minimum
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete node dari BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main program
int main() {
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(values) / sizeof(values[0]);
    struct Node* root = NULL;

    // Masukkan elemen ke BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Langkah a: hapus 6
    root = deleteNode(root, 6);

    // Langkah b: tambah 9
    root = insert(root, 9);

    // Langkah c: cetak inorder
    printf("InOrder traversal setelah penghapusan dan penambahan:\n");
    inorder(root);
    printf("\n");

    return 0;
}

