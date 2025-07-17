/* NAMA  : WANDA THABITA HUTASOIT
   NIM : 43324051
   PRODI: D3 TEKNOLOGI KOMPUTER 
   SOAL UAS 2
*/

#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan node ke dalam BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Fungsi untuk mencari nilai minimum (digunakan dalam penghapusan)
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Fungsi untuk menghapus node dari BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // node dengan satu atau tidak ada anak
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

        // node dengan dua anak
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Fungsi untuk traversal in-order
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(values) / sizeof(values[0]);

    struct Node* root = NULL;

    // Menyisipkan semua nilai awal ke dalam BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // a. Hapus nilai 6
    root = deleteNode(root, 6);

    // b. Tambahkan nilai 9
    root = insert(root, 9);

    // c. Cetak nilai dengan traversal in-order
    printf("InOrder Traversal setelah operasi:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
