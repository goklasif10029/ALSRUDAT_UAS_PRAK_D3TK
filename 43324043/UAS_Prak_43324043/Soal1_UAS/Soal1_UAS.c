#include <stdio.h>

int main() {
    int n;
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int nim[n], nilai[n];

    printf("Masukkan %d NIM Siswa:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort:\n");

    for (int i = 1; i < n; i++) {
        int keyNIM = nim[i];
        int keyNilai = nilai[i];
        int j = i - 1;

        while (j >= 0 && nim[j] > keyNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = keyNIM;
        nilai[j + 1] = keyNilai;

        printf("Pass-%d:\n", i);
        printf("NIM   : ");
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
