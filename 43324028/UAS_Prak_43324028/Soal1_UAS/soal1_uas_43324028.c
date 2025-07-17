/*
NIM :  43324028
Nama:  JESSICA RUTH ABIGAEL
*/

#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &n);

    int arr[n];

    printf("Masukkan %d NIM Siswa: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Masukkan %d Nilai Siswa: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Filter bilangan genap
    int genap[n], count_genap = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            genap[count_genap] = arr[i];
            count_genap++;
        }
    }

    printf("\nData Array Genap Sebelum Proses Insertion Sort:\n");
    for (i = 0; i < count_genap; i++) {
        printf("%d ", genap[i]);
    }
    printf("\n");

    printf("Data Array Genap Setelah Proses Insertion Sort:\n"); 

    for (i = 1; i < count_genap; i++) {
        temp = genap[i];
        j = i - 1;
        while (j >= 0 && genap[j] > temp) {
            genap[j + 1] = genap[j];
            j--;
        }
        genap[j + 1] = temp;

        printf("Pass-%d: ", i); 
        for (int k = 0; k < count_genap; k++) {
            printf("%d ", genap[k]);
        }
        printf("\n");
    }

    return 0;
}