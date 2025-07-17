/*
  Nama  : Yusmita Pasaribu
  NIM   : 43324010
  Prodi : D3 Teknologi komputer
*/


#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk Binary Search Tree (BST)
struct Node {
    int data;
    struct Node *left, *right;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan elemen ke dalam BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Fungsi untuk mencari node dengan nilai minimum (digunakan saat penghapusan)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi untuk menghapus elemen dari BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
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

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Fungsi untuk melakukan traversal InOrder (mencetak elemen secara terurut)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Membuat BST dengan elemen awal
    int elements[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, elements[i]);

    printf("BST sebelum perubahan:\n");
    inOrderTraversal(root);
    printf("\n");

    // Langkah a: Hapus elemen 6
    root = deleteNode(root, 6);

    // Langkah b: Tambah elemen 9
    root = insert(root, 9);

    printf("BST setelah perubahan:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

