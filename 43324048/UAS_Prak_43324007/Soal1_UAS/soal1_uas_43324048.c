/*
Nama : Theofilus Amoz Raja Sihombing
NIM  : 43324048
Prodi: D3 Teknologi Komputer
Nama file: soal1_uas_43324048.c
*/

#include <stdio.h>

int main() {
    int n, i, j, tempNIM, tempNilai;

    // Input jumlah siswa
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int NIM[n], nilai[n];

    // Input NIM
    printf("Masukkan %d NIM Siswa :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &NIM[i]);
    }

    // Input Nilai
    printf("Masukkan %d Nilai Siswa :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");

    // Insertion Sort
    for (i = 1; i < n; i++) {
        tempNIM = NIM[i];
        tempNilai = nilai[i];
        j = i - 1;

        while (j >= 0 && NIM[j] > tempNIM) {
            NIM[j + 1] = NIM[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        NIM[j + 1] = tempNIM;
        nilai[j + 1] = tempNilai;

        // Cetak hasil setiap pass
        printf("Pass-%d:\n", i);
        printf("NIM : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", NIM[k]);
        }
        printf("\nNilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n");
    }

    return 0;
}
