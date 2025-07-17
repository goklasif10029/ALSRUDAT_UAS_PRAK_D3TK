/*  Nama : Markos Panjaitan
    NIM  : 43324021
    Nama Program : mlist.c
*/

#include <stdio.h>
#include <stdlib.h>

#define boolean unsigned char
#define true 1
#define false 0

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d|%d -> ", node->data, node->next);
        node = node->next;
    }
    printf("\n");
}

int countNodes(struct Node* node) {
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

struct Node* insertFirst(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertLast(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Elemen dengan nilai %d tidak ditemukan dalam linked list\n", key);
        return head;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteAfter(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    } else {
        printf("Elemen setelah %d tidak ditemukan atau tidak ada\n", key);
    }

    return head;
}

int main() {
    int maxElements, i, input, insertOption, insertValue, insertAfterValue;
    struct Node* head = NULL;

    printf("Masukkan Maksimum Jumlah Elemen List Yang akan Di-Insert : ");
    scanf("%d", &maxElements);

    printf("Silahkan Masukkan Elemen Linked List dengan Maksimum %d Elemen Dan Tidak Boleh Angka -99\n", maxElements);
    printf("Jika Nilai -99 atau Sudah Melebihi Batas Maksimum Elemen, Maka Elemen Tidak Dimasukkan ke dalam Linked List\n");

    for (i = 1; i <= maxElements; i++) {
        printf("Insert Elemen%d : ", i);
        scanf("%d", &input);
        if (input == -99 || countNodes(head) >= maxElements) {
            break;
        }
        head = insertLast(head, input);
    }

    printf("Isi Linked List : ");
    printList(head);
    printf("Jumlah Elemen Linked List : %d\n", countNodes(head));

    printf("\nMENU OPERASI LINKED LIST :\n");
    printf("1. INSERT LIST\n");
    printf("2. DELETE LIST\n");
    printf("Masukkan Pilihan (1/2) : ");
    scanf("%d", &input);

    if (input == 1) {
        printf("\nMENU INSERT LINKED LIST:\n");
        printf("11. INSERT FIRST ELEMENT\n");
        printf("12. INSERT LAST ELEMENT\n");
        printf("13. INSERT AFTER ELEMENT\n");
        printf("Masukkan Pilihan Insert (11/12/13) : ");
        scanf("%d", &insertOption);

        switch (insertOption) {
            case 11:
                printf("Masukkan Elemen yang Di-Insert : ");
                scanf("%d", &insertValue);
                head = insertFirst(head, insertValue);
                break;
            case 12:
                printf("Masukkan Elemen yang Di-Insert : ");
                scanf("%d", &insertValue);
                head = insertLast(head, insertValue);
                break;
            case 13:
                printf("Masukkan Nilai Elemen yang Ingin Ditambahkan : ");
                scanf("%d", &insertAfterValue);
                printf("Masukkan Elemen yang Di-Insert : ");
                scanf("%d", &insertValue);
                head = insertAfter(head, insertAfterValue, insertValue);
                break;
            default:
                printf("Pilihan tidak sesuai, program keluar.\n");
                exit(0);
        }

        printf("Isi Linked List : ");
        printList(head);
        printf("Jumlah Elemen Linked List : %d\n", countNodes(head));
    } 
    else if (input == 2) {
        int deleteOption;
        printf("\nMENU DELETE LINKED LIST:\n");
        printf("21. DELETE FIRST ELEMENT\n");
        printf("22. DELETE LAST ELEMENT\n");
        printf("23. DELETE AFTER ELEMENT\n");
        printf("Masukkan Pilihan Insert (21/22/23) : ");
        scanf("%d", &deleteOption);

        switch (deleteOption) {
            case 21:
                head = deleteFirst(head);
                break;
            case 22:
                head = deleteLast(head);
                break;
            case 23:
                printf("Masukkan Nilai Elemen Sebelum Elemen yang Akan Dihapus : ");
                scanf("%d", &insertAfterValue);
                head = deleteAfter(head, insertAfterValue);
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

        printf("Isi Linked List : ");
        printList(head);
        printf("Jumlah Elemen Linked List : %d\n", countNodes(head));
    } 
    else {
        printf("Pilihan tidak sesuai, program keluar.\n");
        exit(0);
    }

    return 0;
}


