#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, tempNIM, tempNilai;
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int NIM[n], Nilai[n];

    printf("Masukkan %d NIM Siswa :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &NIM[i]);
    }

    printf("Masukkan %d Nilai Siswa :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &Nilai[i]);
    }

    printf("Urutan Berdasarkan NIM Setelah Insertion Sort :\n");

    for (i = 1; i < n; i++) {
        tempNIM = NIM[i];
        tempNilai = Nilai[i];
        j = i - 1;
        while (j >= 0 && NIM[j] > tempNIM) {
            NIM[j + 1] = NIM[j];
            Nilai[j + 1] = Nilai[j];
            j--;
        }
        NIM[j + 1] = tempNIM;
        Nilai[j + 1] = tempNilai;

        // Tampilkan hasil setiap pass
        printf("Pass-%d:\n", i);
        printf("NIM : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", NIM[k]);
        }
        printf("\nNilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", Nilai[k]);
        }
        printf("\n");
    }

    return 0;
}