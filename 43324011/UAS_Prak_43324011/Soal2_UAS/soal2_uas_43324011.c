// Nama : Aisa Silvana S. Nababan
// NIM  : 43324011
// PRODI: D3TK-01
// SOAL : 2

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    
    return node;
}


struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        
        struct node* temp = minValueNode(root->right);
        
        
        root->data = temp->data;
        
        
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(values)/sizeof(values[0]);
    
    
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    
    
    root = deleteNode(root, 6);
    
    
    root = insert(root, 9);
    
    
    printf("Hasil traversal InOrder setelah penghapusan 6 dan penambahan 9:\n");
    inorder(root);
    printf("\n");
    
    return 0;
}