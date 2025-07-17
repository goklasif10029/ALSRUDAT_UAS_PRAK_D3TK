// NIM           : 43324049
// Nama          : Okto Esra Beliana Sinaga
// Program Studi : D3 Teknologi Komputer

#include <stdio.h>

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

        // Menampilkan hasil tiap langkah
        printf("Pass-%d:\n", i);
        printf("NIM   : ");
        for (int k = 0; k < n; k++)
            printf("%d ", nim[k]);
        printf("\nNilai : ");
        for (int k = 0; k < n; k++)
            printf("%d ", nilai[k]);
        printf("\n\n");
    }
}

int main() {
    int n;
    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &n);

    int nim[n], nilai[n];
    printf("Masukkan %d NIM Siswa: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nim[i]);

    printf("Masukkan %d Nilai Siswa: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nilai[i]);

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort:\n");
    insertionSort(nim, nilai, n);

    return 0;
}
