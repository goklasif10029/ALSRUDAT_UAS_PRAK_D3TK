#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}


Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
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

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambahkan nilai 9
    root = insert(root, 9);

    // c. Cetak InOrder
    printf("InOrder traversal setelah modifikasi: ");
    inorder(root);
    printf("\n");

    return 0;
}
