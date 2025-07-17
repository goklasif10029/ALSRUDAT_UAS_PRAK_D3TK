 /*
 Nama : Bona Maruli Panjaitan
 Nim  : 43324035
 Prodi: D3 Teknologi Komputer
 Soal : No 1 
 */


#include <stdio.h>

void printPass(int pass, int nim[], int nilai[], int n) {
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

void insertionSort(int nim[], int nilai[], int n) {
    int i, j, keyNIM, keyNilai;

    for (i = 1; i < n; i++) {
        keyNIM = nim[i];
        keyNilai = nilai[i];
        j = i - 1;

        while (j >= 0 && nim[j] > keyNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j = j - 1;
        }

        nim[j + 1] = keyNIM;
        nilai[j + 1] = keyNilai;

        printPass(i, nim, nilai, n);
    }
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

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort  :\n");
    insertionSort(nim, nilai, n);

    return 0;
}
