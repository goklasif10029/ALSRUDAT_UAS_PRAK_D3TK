#include <stdio.h>

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
    for (int i = 1; i < n; i++) {
        int keyNIM = nim[i];
        int keyNilai = nilai[i];
        int j = i - 1;

        // Pindahkan elemen NIM yang lebih besar dari keyNIM ke kanan
        while (j >= 0 && nim[j] > keyNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = keyNIM;
        nilai[j + 1] = keyNilai;

        // Tampilkan hasil pass
        printf("Pass-%d:\n", i);
        printf("NIM : ");
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
