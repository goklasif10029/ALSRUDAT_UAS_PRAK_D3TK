/*
Nama        : Josua HM Manurung
NIM         : 43324004
Prodi       : DIII Teknologi Komputer
Program     : Insertion Sort
*/

#include <stdio.h>

void insertionSort(int nim[], int nilai[], int n) {
    int i, keyNIM, keyNilai, j;
    for (i = 1; i < n; i++) {
        keyNIM = nim[i];
        keyNilai = nilai[i];
        j = i - 1;

        // Pindahkan elemen yang lebih besar dari keyNIM ke kanan
        while (j >= 0 && nim[j] > keyNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j = j - 1;
        }
        nim[j + 1] = keyNIM;
        nilai[j + 1] = keyNilai;

        // Cetak hasil pass
        printf("Pass-%d:\n", i);
        printf("NIM : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nim[k]);
        }
        printf("\nNilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n\n");
    }
}

int main() {
    int n, i;

    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int nim[n], nilai[n];

    printf("Masukkan %d NIM Siswa :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");
    // Pass-1 ditampilkan sebelum sort dilakukan agar sesuai format soal
    printf("Pass-1:\nNIM : ");
    for (i = 0; i < n; i++) printf("%d ", nim[i]);
    printf("\nNilai : ");
    for (i = 0; i < n; i++) printf("%d ", nilai[i]);
    printf("\n\n");

    insertionSort(nim, nilai, n);

    return 0;
}
