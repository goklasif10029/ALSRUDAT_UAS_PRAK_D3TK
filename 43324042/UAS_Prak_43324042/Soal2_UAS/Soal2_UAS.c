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
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi insert BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Fungsi untuk mencari nilai minimum
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi delete node BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // node with only one child or no child
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

        // node with two children
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

// Main program
int main() {
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(data) / sizeof(data[0]);
    
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambah nilai 9
    root = insert(root, 9);

    // c. Cetak InOrder
    printf("Hasil InOrder Traversal setelah modifikasi:\n");
    inorder(root);
    printf("\n");

    return 0;
}
