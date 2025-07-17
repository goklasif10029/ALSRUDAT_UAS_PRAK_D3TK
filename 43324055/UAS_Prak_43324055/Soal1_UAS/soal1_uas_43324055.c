/*
Nama: Nisha Gurning
Nim: 43324055
Prodi: D3 Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, keyNIM, keyNilai;

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

    printf("Urutan Berdasarkan NIM Setelah Insertion Sort:\n");

    for (i = 1; i < n; i++) {
        keyNIM = nim[i];
        keyNilai = nilai[i];
        j = i - 1;

        while (j >= 0 && nim[j] > keyNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = keyNIM;
        nilai[j + 1] = keyNilai;

        printf("Pass-%d:\n", i);
        printf("NIM   : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nim[k]);
        }
        printf("\nNilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n\n");
    }

    return 0;
}