/*
Nama : Theofilus Amoz Raja Sihombing
NIM  : 43324048
Prodi: D3 Teknologi Komputer
Nama file: soal2_uas_43324048.c
*/
#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Fungsi membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi insert
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Fungsi cari nilai minimum (digunakan untuk delete)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi delete node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

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

// Fungsi inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Langkah awal: membangun tree dari {1,4,5,6,11,12,20}
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(data)/sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambahkan nilai 9
    root = insert(root, 9);

    // c. Cetak hasil akhir dengan InOrder traversal
    printf("Hasil InOrder traversal setelah update:\n");
    inorder(root);
    printf("\n");

    return 0;
}
