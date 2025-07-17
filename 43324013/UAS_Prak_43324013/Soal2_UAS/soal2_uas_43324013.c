/*
NIM:            43324013
Nama:           Bonifasius Geraldo
Nama Program:   Binary Search Tree
*/

#include <stdio.h>
#include <stdlib.h>

// Definisi node BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi untuk membuat node baru
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi untuk menyisipkan data ke BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Fungsi untuk mencari node minimum
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi untuk menghapus node dari BST
Node* delete(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        // Node dengan satu anak atau tidak punya anak
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

        // Node dengan dua anak
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
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
    Node* root = NULL;

    // Membuat BST dari data awal
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    for (int i = 0; i < 7; i++) {
        root = insert(root, data[i]);
    }

    // a. Hapus nilai 6
    root = delete(root, 6);

    // b. Tambah nilai 9
    root = insert(root, 9);

    // c. Cetak InOrder
    printf("Hasil traversal InOrder setelah operasi:\n");
    inorder(root);
    printf("\n");

    return 0;
}
