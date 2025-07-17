#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi setelahnya
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertion(int array[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi setelahnya
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main() {
    int jumlah_siswa;
    int jumlah_nilai;
    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &jumlah_siswa);

    int arr[jumlah_siswa];
    printf("Masukkan %d  NIM Siswa: ", jumlah_siswa);
    for (int i = 0; i < jumlah_siswa; i++) {
        scanf("%d", &arr[i]);   
}

    // Pisahkan bilangan genap
    int genap[jumlah_siswa];
    int count_genap = 0;
    for (int i = 0; i < jumlah_siswa; i++) {
        if (arr[i] % 2 == 0) {
            genap[count_genap++] = arr[i];
        }
    }

    int array[jumlah_nilai];
    printf("Masukkan %d  Nilai Siswa: ", jumlah_nilai);
    for (int i = 0; i < jumlah_nilai; i++) {
        scanf("%d", &array[i]);
    }
     // Pisahkan bilangan genap
    int ganjil[jumlah_nilai];
    int count_ganjil = 0;
    for (int i = 0; i < jumlah_nilai; i++) {
        if (array[i] % 2 == 0) {
            ganjil[count_ganjil++] = array[i];
        }
    }
   

    // Proses insertion sort dan tampilkan setiap pass
    printf("\nUrutkan Berdasarkan NIM Setelah Insertion Sort :\n");
    for (int i = 1; i < count_genap; i++) {
        int key = genap[i];
        int j = i - 1;

        while (j >= 0 && genap[j] > key) {
            genap[j + 1] = genap[j];
            j = j - 1;
        }
        genap[j + 1] = key;

        // Tampilkan array setelah setiap pass
        printf("Pass-%d:\n ", i);
        printf("\nNIM : ");
        for (int k = 0; k < count_genap; k++) {
            printf("%d ", genap[k]);
        }

        printf("\nNilai : ");
        for (int k = 0; k < count_ganjil; k++) {
            printf("%d ", ganjil[k]);
        }
        printf("\n");
    }

    return 0;
}