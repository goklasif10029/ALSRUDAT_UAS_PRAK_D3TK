/*
Nama : Bram Modestus Naibaho
Nim : 43324002
Prodi : DIII-Teknologi Komputer
*/

#include <stdio.h>

int main() {
    int n;
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int nim[n], nilai[n];
    printf("Masukkan %d NIM Siswa : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }
    printf("Masukkan %d Nilai Siswa : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    for (int pass = 1; pass < n; pass++) {
        int key_nim = nim[pass];
        int key_nilai = nilai[pass];
        int j = pass - 1;

        while (j >= 0 && nim[j] > key_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = key_nim;
        nilai[j + 1] = key_nilai;

        printf("Pass-%d: NIM : ", pass);
        for (int k = 0; k < n; k++) {
            printf("%d ", nim[k]);
        }
        printf("\n       Nilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n");
    }

    return 0;
}
