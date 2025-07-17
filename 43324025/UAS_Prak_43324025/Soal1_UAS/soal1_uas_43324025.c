/* 
    NIM             : 43324025
    Nama            : Rahel Damayanti Panjaitan
    Nama Program    : Insertion Sort
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, temp_nilai;
    int nim[100], nilai[100];

    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    printf("Masukkan %d NIM Siswa:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");

    for(i = 1; i < n; i++) {
        int key_nim = nim[i];
        int key_nilai = nilai[i];
        j = i - 1;

        // Sorting berdasarkan nim
        while(j >= 0 && nim[j] > key_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = key_nim;
        nilai[j + 1] = key_nilai;

        // Output tiap pass
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
