/*
Nama: Rejeki H. Siregar
NIM: 43324022
Nama Program: Soal1_UAS_43324022
*/

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int array[], int array2[], int n) {
    int i, j, key, key2, k;
    for (i = 1; i < n; i++) {
        key = array[i];
        key2 = array2[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            array2[j + 1] = array2[j];
            j = j - 1;
        }
        array[j + 1] = key;
        array2[j + 1] = key2;
        printf("Pass-%d:\n", i);
        printf("NIM : ");
        for (k = 0; k < n; k++) {
            printf("%d ", array[k]);
        }
        printf("\nNilai : ");
        for (k = 0; k < n; k++) {
            printf("%d ", array2[k]);
        }
        printf("\n");
    }
}

void inputArray(int array[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void inputArray2(int array2[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &array2[i]);
    }
}

void printArray(int array[], int array2[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Nim : %d ", array[i]);
    }
        for (i = 0; i < n; i++) {
        printf("Nilla : %d ", array2[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    int array[100];
    int array2[100];
    printf("Masukkan Jumlah Mahasisiswa : ");
    scanf("%d", &n);
    printf("Masukkan %d NIM Siswa : ", n);
    inputArray(array, n);  
    printf("Masukkan %d Nilai Siswa : ", n);
    inputArray2(array2, n);  
    printf("Urutkan Berdasarkan NIM Setelah Insertion Sort: \n");
    insertionSort(array, array2, n);
} 
