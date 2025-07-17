#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi membuat node baru
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Fungsi untuk menyisipkan node
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Fungsi InOrder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Fungsi mencari nilai minimum
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi menghapus node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node dengan satu anak atau tidak ada
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node dengan dua anak
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(values) / sizeof(values[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambah nilai 9
    root = insert(root, 9);

    // c. Tampilkan traversal InOrder
    printf("InOrder traversal setelah operasi:\n");
    inorder(root);
    printf("\n");

    return 0;
}
