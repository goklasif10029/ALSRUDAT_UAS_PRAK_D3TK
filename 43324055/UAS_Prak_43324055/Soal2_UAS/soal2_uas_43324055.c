/*
Nama: Nisha Gurning
Nim: 43324055
Prodi: D3 Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* delete(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
    root->left = delete(root->left, data);
    else if (data > root->data)
    root->right = delete(root->right, data);
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
        root->right = delete(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int data[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(data)/sizeof(data[0]);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // a. Hapus 6
    root = delete(root, 6);

    // b. Tambah 9
    root = insert(root, 9);

    // c. InOrder traversal
    printf("InOrder Traversal Setelah Operasi:\n");
    inorder(root);
    printf("\n");

    return 0;
}