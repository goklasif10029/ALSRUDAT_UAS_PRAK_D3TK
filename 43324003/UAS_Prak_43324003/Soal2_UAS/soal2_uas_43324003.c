/*
 NIM :          43324003
 Nama :         Helmi Hutabarat       
 Nama Program : Binary Search Tree
*/

#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk melakukan insertion sort NIM
void insertionSortNIM(int ArrayNIM[], int N) {
    int i, j, key;
    for (i = 1; i < N; i++) {
        key = ArrayNIM[i];
        j = i - 1;

        // Geser elemen yang lebih besar dari key ke satu posisi di depan
        while (j >= 0 && key < ArrayNIM[j]) {
            ArrayNIM[j + 1] = ArrayNIM[j];
            j--;
        }
        ArrayNIM[j + 1] = key;

    }
}

// Fungsi untuk input arrayNIM
void inputArrayNIM(int ArrayNIM[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &ArrayNIM[i]);
    }
}

// Fungsi untuk mencetak arrayNIM
void printArrayNIM(int ArrayNIM[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", ArrayNIM[i]);
    }
    printf("\n");
}

// Fungsi untuk melakukan insertion sort Nilai
void insertionSortNilai(int ArrayNilai[], int N) {
    int i, j, key;
    for (i = 1; i < N; i++) {
        key = ArrayNilai[i];
        j = i - 1;

        // Geser elemen yang lebih besar dari key ke satu posisi di depan
        while (j >= 0 && key < ArrayNilai[j]) {
            ArrayNilai[j + 1] = ArrayNilai[j];
            j--;
        }
        ArrayNilai[j + 1] = key;

    }
}

// Fungsi untuk input arrayNilai
void inputArrayNilai(int ArrayNilai[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &ArrayNilai[i]);
    }
}

// Fungsi untuk mencetak arrayNilai
void printArrayNilai(int ArrayNilai[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", ArrayNilai[i]);
    }
    printf("\n");
}

int main() {
    int ArrayNIM[100];
    int NIM;
    int ArrayNilai[100];
    int Nilai;

    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &NIM);

    printf("Masukkan %d NIM Siswa: ", NIM);
    inputArrayNIM(ArrayNIM, NIM);

    printf("Masukkan %d Nilai Siswa: ", Nilai);
    inputArrayNilai(ArrayNilai, Nilai);

    insertionSortNIM(ArrayNIM, NIM);
    insertionSortNilai(ArrayNilai, Nilai);

    printf("Urutan Berdasarkan NIM Setelah Insertion Sort : ");
    printf("NIM: ");
    printArrayNIM(ArrayNIM, NIM);
    printf("Nilai: ");
    printArrayNIM(ArrayNilai, Nilai);

    return 0;
}
