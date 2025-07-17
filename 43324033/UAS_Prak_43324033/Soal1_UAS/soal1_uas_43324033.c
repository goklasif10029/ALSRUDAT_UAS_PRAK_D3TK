/*
NIM : 43324033
Nama : Angeleno Zuliano Hutapea 
Nama Program : Insertion Sort (Sorting NIM dan Menyusun Nilai sesuai)
*/

#include <stdio.h>

int main() {
    int n, i, j, temp_nim, temp_nilai;
    int nim[100], nilai[100];

    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &n);

    printf("Masukkan NIM Siswa:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan Nilai Siswa:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort:\n");

    for (i = 1; i < n; i++) {
        temp_nim = nim[i];
        temp_nilai = nilai[i];
        j = i - 1;

        while (j >= 0 && nim[j] > temp_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }

        nim[j + 1] = temp_nim;
        nilai[j + 1] = temp_nilai;

        printf("Pass-%d:\n", i);
        printf("NIM : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nim[k]);
        }
        printf("\nNilai: ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n");
    }

    return 0;
}
