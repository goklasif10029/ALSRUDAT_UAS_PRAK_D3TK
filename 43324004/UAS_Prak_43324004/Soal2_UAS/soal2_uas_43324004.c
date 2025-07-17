/*
Nama        : Josua HM Manurung
NIM         : 43324004
Prodi       : DIII Teknologi Komputer
Program     : Binary Tree       
*/

#include <stdio.h>
#include <stdlib.h>

// struktur binary yang dibuat
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Untuk membuat node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Menambahkan data ke binary tree
Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// mencari node terkecil
Node* findMin(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

//menghapus node
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
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
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// membuat in ordernya
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main() {
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // hapus nilai 6
    root = deleteNode(root, 6);

    // tambah nilai 9
    root = insert(root, 9);

    // print In Order
    printf("Transversal InOrder Setelah Langkah A dan B\n");
    inorder(root);
    printf("\n");

    return 0;
}


