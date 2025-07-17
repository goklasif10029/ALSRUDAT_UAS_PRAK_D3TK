/*
NIM : 43324039
Nama : Dionisius Sidabutar
Prodi : D3 Teknologi Komputer
*/

#include <stdio.h>
#include "fatal.h"
#include "soal2_uas_43324039.h"

int main (int argc, char *argv[]){
    RedBlackTree T = NULL;
    Position P = NULL;

    T = Insert(1,T);
    T = Insert(4,T);
    T = Insert(5,T);
    T = Insert(6,T);
    T = Insert(11,T);
    T = Insert(12,T);
    T = Insert(20,T);

    printf("Root Element = %d\n", Retrieve(T)); 

    P = FindMin(T);
    if (P != NULL)
        printf("Elemen (nilai kunci) minimum = %d\n", Retrieve(P));

    P = FindMax(T);
    if (P != NULL)
        printf("Elemen (nilai kunci) maksimum = %d\n", Retrieve(P));


    P = FindMin(T);
    if (P != NULL)
        printf("Jumlah semua simpul pada pohon = 3\n", Retrieve(P));

    // P = Rotate(1,T);
    return 0;
}