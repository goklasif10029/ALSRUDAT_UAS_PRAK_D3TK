/* 
    NIM             : 13322044
    Nama            : Rosmida Ferawati Siagian
    Nama Program    : Insertion Sort
*/

#include <stdio.h>
#include <stdlib.h>

/*fungsi untuk membaca imputan array dari user*/
void inputArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Array[i]);
    }
}

/*untuk menampilkan isi array(print array)*/
void printArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("%d ", Array[i]);
    }
    printf("\n");
}

/*Fungsi algoritma insertion sort*/
void insertionSort(int Array[], int N){
    int i, j, key;
    for (i = 1; i < N; i++){
        key = Array[i];
        j = i - 1;
        while (j >= 0 && key < Array[j])
        {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
        printf("Pass-%d: ", i);
        printArray(Array, N);
    }
}

/*fungsi main untuk memanggil fungsi inputArray, 
printArray dan insertionSort yang merupakan output dari program*/
int main(){
    int Array[100];
    int N, i;

    printf("Masukkan Jumlah Data Aray: ");
    scanf("%d", &N);
    printf("Masukkan %d elemen pada Array: ", N);
    inputArray(Array, N);
    printf("Data Array Sebelum Proses Insertion Sort: ");
    printArray(Array, N);
    printf("Data Array Genap Setelah Proses Insertion Sort: \n");
    insertionSort(Array, N);
    printf("Data Array Ganjil Setelah Proses Insertion Sort: \n");
    insertionSort(Array, N);
    return 0;
}
