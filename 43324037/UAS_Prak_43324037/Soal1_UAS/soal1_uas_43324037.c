/*
NIM             : 43324037
Nama            : Joice simaremare
Nama Program    : Insertion Sort
*/

#include <stdio.h>

void printData(int nim[], int nilai[], int n) {
    printf("NIM   : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nim[i]);
    }
    printf("\nNilai : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");
}

void insertionSortNIM(int nim[], int nilai[], int n) {
    for (int i = 1; i < n; i++) {
        int keyNIM = nim[i];
        int keyNilai = nilai[i];
        int j = i - 1;

        while (j >= 0 && nim[j] > keyNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = keyNIM;
        nilai[j + 1] = keyNilai;

        printf("Pass-%d:\n", i);
        printData(nim, nilai, n);
    }
}

int main() {
    int n;
    int nim[100], nilai[100];

    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    printf("Masukkan %d NIM Siswa :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");
    insertionSortNIM(nim, nilai, n);

    return 0;
}
