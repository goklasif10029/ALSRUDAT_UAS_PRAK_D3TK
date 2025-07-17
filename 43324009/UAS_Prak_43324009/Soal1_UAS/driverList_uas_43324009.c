/*
NIM          :  43324009
Nama         :  DORA SIANIPAR
Nama Program :  Insertion Sort
*/

#include <stdio.h>
#include "list.h"
#include "boolean.h"

void PrintAddress(List L)
{
    address P = First(L);
    while (P != Nil)
    {
        printf("%d|%p -> ", Info(P), P);
        P = Next(P);
    }
    printf("0\n");
}

int main()
{
    List L;
    CreateList(&L);
    int maxElements, element, choice, insertChoice;

    printf("Masukkan Maksimum Jumlah Elemen List Yang Akan Di-Insert: ");
    scanf("%d", &maxElements);

    printf("Silahkan Masukkan Elemen Linked List dengan Maksimum %d Elemen Dan Tidak Boleh Angka -99\n", maxElements);
    printf("Jika Nilai -99 atau Sudah Melebihi Batas Maksimum Elemen, Maka Elemen Tidak Dimasukkan ke dalam Linked List\n");
    printf("Insert Elemen Linked List :\n");

    int count = 0;
    while (count < maxElements)
    {
        scanf("%d", &element);
        if (element == -99)
        {
            break;
        }
        InsVLast(&L, element);
        count++;
    }

    printf("Isi Linked List: ");
    PrintAddress(L);
    printf("Jumlah Elemen Linked List: %d\n", NbElmt(L));

    while (1)
    {
        printf("\nMENU OPERASI LINKED LIST:\n");
        printf("1. INSERT LIST\n");
        printf("2. DELETE LIST\n");
        printf("Masukkan Pilihan (1/2) : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nMENU INSERT LINKED LIST:\n");
            printf("11. INSERT FIRST ELEMENT\n");
            printf("12. INSERT LAST ELEMENT\n");
            printf("13. INSERT AFTER ELEMENT\n");
            printf("Masukkan Pilihan Insert (11/12/13) : ");
            scanf("%d", &insertChoice);

            printf("Masukkan Elemen yang akan Di-Insert : ");
            scanf("%d", &element);

            if (insertChoice == 11)
            {
                InsVFirst(&L, element);
            }
            else if (insertChoice == 12)
            {
                InsVLast(&L, element);
            }
            else if (insertChoice == 13)
            {
                int afterElement;
                printf("Masukkan Elemen yang ada di dalam Linked List (setelah elemen ini akan di-insert): ");
                scanf("%d", &afterElement);
                address afterAddr = Search(L, afterElement);
                if (afterAddr != Nil)
                {
                    address newElement = Alokasi(element);
                    InsertAfter(&L, newElement, afterAddr);
                }
                else
                {
                    printf("Elemen %d tidak ditemukan dalam Linked List\n", afterElement);
                }
            }

            printf("Isi Linked List: ");
            PrintAddress(L);
            printf("Jumlah Elemen Linked List: %d\n", NbElmt(L));
        }
        else if (choice == 2)
        {
            printf("DELETE functionality not implemented in this example.\n");
            // Implement DELETE functionality as needed
        }
        else
        {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
