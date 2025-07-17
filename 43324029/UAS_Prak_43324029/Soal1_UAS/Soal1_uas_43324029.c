/*
NIM             : 43324029
Nama            : Rael Regina Rumahorbo
Nama Program    : Insertion Sort
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

int main() {
    int n;

    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &n);

    int nim[n], nilai[n];
    printf("Masukkan %d NIM Siswa :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%
