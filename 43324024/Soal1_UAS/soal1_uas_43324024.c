/* 
Nama    : Michael Julianto Sipahutar
NIM     : 43324024
Prodi   : D-III Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int jumlah, i, j, temp_nim, temp_nilai;

    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &jumlah);

    int nim[jumlah], nilai[jumlah];

    printf("Masukkan %d NIM Siswa :\n", jumlah);
    for (i = 0; i < jumlah; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa :\n", jumlah);
    for (i = 0; i < jumlah; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");

    for (i = 1; i < jumlah; i++) {
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
        printf("NIM   : ");
        for (int k = 0; k < jumlah; k++) {
            printf("%d ", nim[k]);
        }
        printf("\nNilai : ");
        for (int k = 0; k < jumlah; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n\n");
    }

    return 0;
}
