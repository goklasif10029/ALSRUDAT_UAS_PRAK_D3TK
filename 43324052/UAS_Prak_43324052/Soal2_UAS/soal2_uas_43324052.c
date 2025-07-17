/*
NIM:43324052
Nama: Debora Tampubolon
Prodi: D3 - Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node Structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 2. Insertion Function
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data is equal to root->data, we typically don't insert duplicates
    // or handle them based on specific requirements (e.g., allow duplicates, ignore)
    return root;
}

// Helper function to find the minimum value node in a subtree (used for deletion)
Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// 3. Deletion Function
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
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

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 4. Inorder Traversal Function
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    // Initial tree creation: T = {1,4,5,6,11,12,20}
    int initial_elements[] = {1, 4, 5, 6, 11, 12, 20};
    int num_initial_elements = sizeof(initial_elements) / sizeof(initial_elements[0]);

    for (int i = 0; i < num_initial_elements; i++) {
        root = insert(root, initial_elements[i]);
    }

    printf("Initial Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // a. Lakukan penghapusan nilai 6. (Perform deletion of value 6)
    root = deleteNode(root, 6);
    printf("After deleting 6 (Inorder Traversal): ");
    inorderTraversal(root);
    printf("\n");

    // b. Lakukan penambahan nilai 9. (Perform addition of value 9)
    root = insert(root, 9);
    printf("After adding 9 (Inorder Traversal): ");
    inorderTraversal(root);
    printf("\n");

    // c. Setelah melakukan Langkah a dan Langkah b, cetak ke layar nilai elemen yang ada di T,
    //    dengan menggunakan traversal InOrder.
    //    (After performing steps a and b, print the elements in T using Inorder traversal.)
    printf("Final Inorder Traversal (after deleting 6 and adding 9): ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}