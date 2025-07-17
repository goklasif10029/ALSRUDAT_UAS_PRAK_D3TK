#include <stdio.h>


void printArrays(int nim[], int nilai[], int size, int pass) {
    printf("Pass-%d: NIM : ", pass);
    for (int i = 0; i < size; i++) {
        printf("%d ", nim[i]);
    }

    printf("\n       Nilai : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");
}


void insertionSort(int nim[], int nilai[], int n) {
    int i, j, keyNim, keyNilai;
    for (i = 1; i < n; i++) {
        keyNim = nim[i];
        keyNilai = nilai[i];
        j = i - 1;

       
        while (j >= 0 && nim[j] > keyNim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j = j - 1;
        }
        nim[j + 1] = keyNim;
        nilai[j + 1] = keyNilai;
        
       
        printArrays(nim, nilai, n, i);
    }
}

int main() {
    int n;
    
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);
    
    int nim[n], nilai[n];
    
    printf("Masukkan %d NIM Siswa : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }
    
    printf("Masukkan %d Nilai Siswa : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }
    
    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort : \n");
    insertionSort(nim, nilai, n);
    
    return 0;
}