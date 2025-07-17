/* NAMA : WANDA THABITA HUTASOIT
   NIM : 43324051
   PRODI: D3 TEKNOLOGI KOMPUTER 24
   SOAL UAS NO 1
*/

#include <stdio.h>

void tampilkan(int nim[], int nilai[], int n, int pass) {
    printf("Pass-%d:\n", pass);
    printf("NIM : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nim[i]);
    }
    printf("\nNilai : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n\n");
}

int main() {
    int n;

    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int nim[n], nilai[n];

    printf("Masukkan %d NIM Siswa :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    // Insertion Sort berdasarkan NIM
    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");

    for (int i = 1; i < n; i++) {
        int key_nim = nim[i];
        int key_nilai = nilai[i];
        int j = i - 1;

        while (j >= 0 && nim[j] > key_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = key_nim;
        nilai[j + 1] = key_nilai;

        tampilkan(nim, nilai, n, i);
    }

    return 0;
}
