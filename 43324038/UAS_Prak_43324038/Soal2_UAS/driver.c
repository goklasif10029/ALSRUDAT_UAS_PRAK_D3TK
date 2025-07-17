/*Nama :Immanuel Tampubolon
   NIM :43324038
   Prodi : D-III Teknologi Komputer*/
#include <stdio.h>
#include "Bat.h"

int main() {
    Node* root = NULL;
    int values[] = {1, 4, 5, 6, 11, 12, 20};
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    root = deleteNode(root, 6);
    root = insert(root, 9);

    printf("Hasil traversal InOrder:\n");
    inorder(root);
    printf("\n");

    return 0;
}
