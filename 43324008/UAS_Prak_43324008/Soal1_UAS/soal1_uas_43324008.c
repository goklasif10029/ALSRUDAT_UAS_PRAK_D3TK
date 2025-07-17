/*nama : michael dino gultom
nim : 43324008
prodi : d3tk
*/


#include <stdio.h>

void printPass(int pass, int nim[], int nilai[], int n) {
    printf("Pass-%d:\n", pass);
    printf("NIM   : ");
    for (int i = 0; i < n; i++) printf("%d ", nim[i]);
    printf("\nNilai : ");
    for (int i = 0; i < n; i++) printf("%d ", nilai[i]);
    printf("\n\n");
}

int main() {
    int n;
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);

    int nim[n], nilai[n];

    printf("Masukkan %d NIM Siswa :\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &nim[i]);

    printf("Masukkan %d Nilai Siswa :\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &nilai[i]);

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
        printPass(i, nim, nilai, n);
    }

    return 0;
}
