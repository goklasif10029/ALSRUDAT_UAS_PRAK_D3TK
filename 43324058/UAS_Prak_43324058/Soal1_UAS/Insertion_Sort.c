/*
NIM : 43324058
Nama : Tio Febriyanti Simanjuntak
Nama Program : insertionSortmodif
*/

#include <stdio.h>

int main() {
    int n, i, j, temp_nim, temp_nilai;
    int nim[100], nilai[100];

    // Input jumlah siswa
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    // Input NIM siswa
    printf("Masukkan %d NIM Siswa :\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    // Input nilai siswa
    printf("Masukkan %d Nilai Siswa :\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("Urutan Berdasarkan NIM Setelah Insertion Sort :\n");

    // Insertion Sort
    for(i = 1; i < n; i++) {
        temp_nim = nim[i];
        temp_nilai = nilai[i];
        j = i - 1;
        while(j >= 0 && nim[j] > temp_nim) {
            nim[j+1] = nim[j];
            nilai[j+1] = nilai[j];
            j--;
        }
        nim[j+1] = temp_nim;
        nilai[j+1] = temp_nilai;

        // Cetak setiap pass
        printf("Pass-%d:\n", i);
        printf("NIM : ");
        for(int k = 0; k < n; k++) {
            printf("%d ", nim[k]);
        }
        printf("\nNilai : ");
        for(int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n\n");
    }

    return 0;
}