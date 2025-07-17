#include <stdio.h>

void insertionSort(int nim[24001,24032,24012,23056,24028], int nilai[90,72,86,66,54], int n) {
    int i, j, keyNim, keyNilai, pass = 1;
    for (i = 1; i < n; i++) {
        keyNim = nim[i];
        keyNilai = nilai[i];
        j = i - 1;

        while (j >= 0 && nim[j] > keyNim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = keyNim;
        nilai[j + 1] = keyNilai;

        // Tampilkan hasil setiap pass
        printf("\nPass-%d:\n", pass++);
        printf("NIM : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nim[k]);
        }
        printf("\nNilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", nilai[k]);
        }
        printf("\n");
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

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :");
    insertionSort(nim, nilai, n);

    return 0;
}
