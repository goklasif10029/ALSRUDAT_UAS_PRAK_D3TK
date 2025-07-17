/*
   Nama  : Yusmita Pasaribu
   NIM   : 43324010
   Prodi : D3 Teknologi Komputer
*/



#include <stdio.h>

// Fungsi untuk menampilkan array
void printArray(int NIM[], int Nilai[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", NIM[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Nilai[i]);
    }
    printf("\n");
}

// Fungsi Insertion Sort
void insertionSort(int NIM[], int Nilai[], int size) {
    for (int i = 1; i < size; i++) {
        int keyNIM = NIM[i];
        int keyNilai = Nilai[i];
        int j = i - 1;

        while (j >= 0 && NIM[j] > keyNIM) {
            NIM[j + 1] = NIM[j];
            Nilai[j + 1] = Nilai[j];
            j--;
        }
        NIM[j + 1] = keyNIM;
        Nilai[j + 1] = keyNilai;

        // Menampilkan proses sorting pada setiap pass
        printf("Pass-%d:\nNIM: ", i);
        printArray(NIM, Nilai, size);
        printf("\n");
    }
}

int main() {
    int size;
    printf("Masukkan jumlah siswa: ");
    scanf("%d", &size);

    int NIM[size], Nilai[size];
    
    printf("Masukkan %d NIM siswa: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &NIM[i]);
    }

    printf("Masukkan %d nilai siswa: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &Nilai[i]);
    }

    insertionSort(NIM, Nilai, size);

    return 0;
}
