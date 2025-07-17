/*
 NIM : 43324015
 Nama : Dirly Jesaya Nathaniel Tato
 Nama Program : Insertion Sort (UAS)
*/

#include <stdio.h>

int main() {
    int n, i, j, key_nim, key_nilai;

    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &n);

    int nim[n], nilai[n];

    printf("Masukkan %d NIM Siswa:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort:\n");

    for (i = 1; i < n; i++) {
        key_nim = nim[i];
        key_nilai = nilai[i];
        j = i - 1;

        while (j >= 0 && nim[j] > key_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }

        nim[j + 1] = key_nim;
        nilai[j + 1] = key_nilai;
        
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

    return 0;
}
