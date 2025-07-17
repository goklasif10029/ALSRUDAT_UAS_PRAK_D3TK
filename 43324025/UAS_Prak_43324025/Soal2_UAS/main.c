/* 
    NIM             : 43324025
    Nama            : Rahel Damayanti Panjaitan
    Nama Program    : main
*/

#include <stdio.h>
#include "bst.h"

int main() {
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(values) / sizeof(values[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Langkah a: hapus nilai 6
    root = delete(root, 6);

    // Langkah b: tambah nilai 9
    root = insert(root, 9);

    // Langkah c: InOrder traversal
    printf("InOrder Traversal setelah penghapusan dan penambahan:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
