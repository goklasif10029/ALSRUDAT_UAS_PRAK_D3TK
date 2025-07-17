/*
    NIM : 43324005
    Nama : Arfin Melkisedek Samosir
    Prodi : D-III Teknologi Komputer 
    Nama Program : Binary Search Tree
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

// Fungsi untuk menyisipkan node ke BST
Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// Fungsi InOrder traversal (LNR)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Fungsi untuk mencari node dengan nilai minimum (untuk delete)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi untuk menghapus node dari BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node dengan satu atau tanpa anak
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
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

// Program utama
int main() {
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(data)/sizeof(data[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambah nilai 9
    root = insert(root, 9);

    // c. Cetak elemen BST dengan InOrder
    printf("InOrder Traversal setelah delete(6) dan insert(9):\n");
    inOrder(root);
    printf("\n");

    return 0;
}