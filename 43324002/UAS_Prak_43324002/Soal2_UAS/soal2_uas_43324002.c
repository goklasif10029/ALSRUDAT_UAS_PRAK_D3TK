/*
Nama : Bram Modestus Naibaho
Nim : 43324002
Prodi : DIII-Teknologi Komputer
*/

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

Node* insert(Node* root, int key) {
    if (root == NULL) 
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        
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
        
        Node* temp = minValueNode(root->right);
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
    int init[] = {1,4,5,6,11,12,20};
    int n = sizeof(init)/sizeof(init[0]);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, init[i]);
    }

    root = deleteNode(root, 6);

    root = insert(root, 9);

    printf("Isi tree setelah delete 6 dan insert 9 (InOrder):\n");
    inorder(root);
    printf("\n");

    return 0;
}
