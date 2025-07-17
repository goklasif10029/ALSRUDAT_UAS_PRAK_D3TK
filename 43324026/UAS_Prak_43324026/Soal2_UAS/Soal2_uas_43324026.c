#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Fungsi untuk membuat node baru
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Fungsi untuk memasukkan node ke BST
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    
    return node;
}

// Fungsi untuk mencari node dengan nilai minimum (digunakan untuk delete)
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi untuk menghapus node dari BST
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node dengan hanya satu anak atau tidak ada anak
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node dengan dua anak: dapatkan inorder successor (terkecil di subtree kanan)
        struct node* temp = minValueNode(root->right);
        
        // Salin data inorder successor ke node ini
        root->data = temp->data;
        
        // Hapus inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Fungsi untuk traversal InOrder
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
    
    // Membangun BST awal
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    
    // a. Menghapus nilai 6
    root = deleteNode(root, 6);
    
    // b. Menambahkan nilai 9
    root = insert(root, 9);
    
    // c. Mencetak hasil dengan traversal InOrder
    printf("Hasil traversal InOrder setelah penghapusan 6 dan penambahan 9:\n");
    inorder(root);
    printf("\n");
    
    return 0;
}