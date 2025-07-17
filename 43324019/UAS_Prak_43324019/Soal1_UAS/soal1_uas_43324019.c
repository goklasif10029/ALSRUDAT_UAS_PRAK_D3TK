/*
 NIM :43324019
 Nama :Mariana Doloksaribu
 Nama Program :insertionSort.c
*/

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int Array[], int N){
    int i, j, key;
    for(i = 1; i < N; i++){
        key = Array[i];
        j = i - 1;
        while(j >= 0 && key < Array[j]){
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
    }
}

void inputArray(int Array[], int N){
    int i;
    for(i = 0; i < N; i++){
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N){
    int i;
    for(i = 0; i < N; i++){
        printf("%d ", Array[i]);
    }
    printf("\n");
}

int main(){
    int Array[200];
    int i, N;

    printf("masukkan Jumlah Siswa: ");
    scanf("%d", &N);
    printf("Masukkan %d NIM Siswa: ", N);
    inputArray(Array, N);
    printf("Masukkan%d Nilai Siswa: ", N);
    inputArray(Array, N);
    printf("Urutan Berdasarkan NIM Setelah Insertion Sort: ");
    insertionSort(Array, N);
    printArray(Array, N);

    return 0;
}
