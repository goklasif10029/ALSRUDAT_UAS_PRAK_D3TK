#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Pindahin elemen arr[0..i-1] yang lebih besar dari key
        // ke posisi satu tempat di depan posisi mereka saat ini
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int array[10];
    int genap[10]; // Asumsi maksimal 10 bilangan genap
    int jumlahGenap = 0;

    // Input array dari user
    printf("Masukkan Jumlah Data Array : 10\n");
    printf("Masukkan 10 elemen pada Array : ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
        // Cek apakah elemen array genap
        if (array[i] % 2 == 0) {
            genap[jumlahGenap] = array[i];
            jumlahGenap++;
        }
    }

    // Output bilangan genap sebelum diurutkan
    printf("\nData Array Genap Sebelum Proses Insertion Sort :\n");
    for (int i = 0; i < jumlahGenap; i++) {
        printf("%d ", genap[i]);
    }
    printf("\n");

    // Urutin bilangan genap pake Insertion Sort
    insertionSort(genap, jumlahGenap);

    // Output bilangan genap setelah diurutkan, tampilkan juga prosesnya
    printf("\nData Array Genap Setelah Proses Insertion Sort :\n");
    for (int i = 0; i < jumlahGenap; i++) {
        printf("Pass - %d : ", i + 1);
        for (int j = 0; j < jumlahGenap; j++) {
            printf("%d ", genap[j]);
        }
        printf("\n");
    }

    return 0;
}