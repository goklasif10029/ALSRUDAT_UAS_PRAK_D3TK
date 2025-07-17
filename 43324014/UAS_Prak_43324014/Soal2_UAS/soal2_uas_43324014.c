/*
Nama : Falito Leo Sandara Manurung
NIM : 43324014
Prodi : D3 Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi insert BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Fungsi inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Fungsi mencari node minimum (digunakan saat delete)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi delete node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node dengan satu atau tidak ada anak
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node dengan dua anak: ambil inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int initialValues[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(initialValues) / sizeof(initialValues[0]);

    // Masukkan nilai awal ke BST
    for (int i = 0; i < n; i++) {
        root = insert(root, initialValues[i]);
    }

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambahkan nilai 9
    root = insert(root, 9);

    // c. Cetak hasil traversal in-order
    printf("Hasil InOrder Traversal setelah operasi:\n");
    inorder(root);
    printf("\n");

    return 0;
}
