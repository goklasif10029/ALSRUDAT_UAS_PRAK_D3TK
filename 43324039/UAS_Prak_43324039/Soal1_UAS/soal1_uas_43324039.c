/*
NIM : 43324039
Nama : Dionisius Sidabutar
Prodi : D3 Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h>


void inputArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("%d ", Array[i]);
    }
    printf("\n");
}

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
        printf("Pass-%d NIM: ", i);
        printf(" Nilai :", i);
        printArray(Array, N);
    }
}

int main(){
    int Array[100];
    int N, i;

    printf("Masukan Jumlah Siswa: ");
    scanf("%d", &N);
    printf("Masukkkan %d NIM Siswa: ", N);
    inputArray(Array, N);
    printf("Masukkkan %d Nilai Siswa: ", N);
    inputArray(Array, N);
    printf("Original Sequence: ");
    printArray(Array, N);
    printf("Urutan Berdasarkan NIM Setelah Insertion Sort: \n");
    insertionSort(Array, N);

    return 0;
}