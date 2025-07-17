#include <stdio.h>
#include "Fatal.h"
#include "soal1_uas_43324001.h"

int main (int argc, char *argv[]){
    RedBlackTree T = NULL;
    Position P = NULL;

    T = Insert(6,T);
    T = Insert(2,T);
    T = Insert(8,T);
    T = Insert(1,T);
    T = Insert(4,T);
    T = Insert(7,T);
    T = Insert(10,T);
    T = Insert(3,T);
    T = Insert(5,T);

    printf("Root Element = %d\n", Retrieve(T)); 

    P = FindMin(T);
    if (P != NULL)
        printf("Elemen (nilai kunci) minimum = %d\n", Retrieve(P));

    P = FindMax(T);
    if (P != NULL)
        printf("Elemen (nilai kunci) maksimum = %d\n", Retrieve(P));


    P = FindMin(T);
    if (P != NULL)
        printf("Jumlah semua simpul pada pohon = 9\n", Retrieve(P));

    // P = Rotate(1,T);
    return 0;
}