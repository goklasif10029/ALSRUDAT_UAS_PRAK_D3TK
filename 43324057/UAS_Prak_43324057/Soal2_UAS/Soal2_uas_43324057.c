#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi membuat node baru
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fungsi insert
Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

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

// Fungsi mencari node minimum
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi hapus node
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node ditemukan
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

        // Dua anak
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Fungsi utama
int main() {
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(data)/sizeof(data[0]);

    Node* root = NULL;

    // Membuat BST
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // a. Hapus 6
    root = deleteNode(root, 6);

    // b. Tambah 9
    root = insert(root, 9);

    // c. Cetak inorder traversal
    printf("Hasil InOrder Traversal setelah update:\n");
    inorder(root);
    printf("\n");

    return 0;
}
