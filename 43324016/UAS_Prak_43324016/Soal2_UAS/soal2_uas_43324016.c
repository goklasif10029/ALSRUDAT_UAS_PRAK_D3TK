#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to find the minimum value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a value from BST
Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get inorder successor
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(values)/sizeof(values[0]);
    
    // Build the initial BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    
    printf("BST awal (InOrder): ");
    inorderTraversal(root);
    printf("\n");
    
    // a. Delete value 6
    root = deleteNode(root, 6);
    printf("Setelah menghapus 6 (InOrder): ");
    inorderTraversal(root);
    printf("\n");
    
    // b. Add value 9
    root = insert(root, 9);
    printf("Setelah menambahkan 9 (InOrder): ");
    inorderTraversal(root);
    printf("\n");
    
    // c. Final tree after operations
    printf("Hasil akhir setelah operasi a dan b (InOrder): ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}   