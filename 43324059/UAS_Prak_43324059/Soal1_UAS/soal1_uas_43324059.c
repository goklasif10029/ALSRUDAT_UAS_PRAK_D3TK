/*
Nama :Ester satia sinaga
NIM  :43324059
Prodi:D3-Teknologi Komputer
*/

#include <stdio.h>

int main() {
    int n, i, j, tempNIM, tempNilai;
    int nim[100], nilai[100];

    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    printf("Masukkan %d NIM Siswa :\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }

    printf("Masukkan %d Nilai Siswa :\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");

    for(i = 1; i < n; i++) {
        tempNIM = nim[i];
        tempNilai = nilai[i];
        j = i - 1;

        while(j >= 0 && nim[j] > tempNIM) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        nim[j + 1] = tempNIM;
        nilai[j + 1] = tempNilai;

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
