/*
    NIM : 43324031
    NAMA :Septian A. Hutasoit
    NAMA PROGRAM : soal_uas1.c
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int nim[], int nilai[], int N) {
    int i, j, keyNim, keyNilai;
    for (i = 1; i < N; i++) {
        keyNim = nim[i];
        keyNilai = nilai[i];
        j = i - 1;
        while (j >= 0 && keyNim < nim[j]) {
            nim[j+1] = nim[j];
            nilai[j+1] = nilai[j];
            j = j - 1;
        }
        nim[j+1] = keyNim;
        nilai[j+1] = keyNilai;
        
        // buat nampilin hasil pass 
        printf("Pass-%d: \n", i);

        
        // buat nampilin hasil pass 
        printf("NIM : ");
        for (int k = 0; k < N; k++) {
            printf("%d ", nim[k]);
        }
        printf("\n");

        printf("Nilai : ");
        for (int k = 0; k < N; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n");
    }
}

void inputArray(int Array[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

int main() {
    int nim[100];
    int nilai[100];
    int i, N;
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &N);
    printf("Masukkan %d NIM Siswa : ", N);
    inputArray(nim, N);
    printf("Masukkan %d Nilai Siswa : ", N);
    inputArray(nilai, N);
    
    printf("Urutan Berdasarkan NIM Setelah Insertion Sort :\n");
    insertionSort(nim, nilai, N);
    return 0;
}