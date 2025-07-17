/*
NIM:43324052
Nama: Debora Tampubolon
Prodi: D3 - Teknologi Komputer
*/

#include <stdio.h>
#include <stdlib.h> 

// Fungsi untuk menampilkan array NIM dan Nilai
void display_arrays(int nim[], int nilai[], int n, int pass) {
    printf("Pass-%d:\n", pass);
    printf("NIM : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nim[i]);
    }
    printf("\n");
    printf("Nilai : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Meminta input jumlah siswa
    printf("Masukkan Jumlah Siswa: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input jumlah siswa tidak valid. Harap masukkan bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Deklarasi array untuk NIM dan Nilai
    int *nim = (int *)malloc(n * sizeof(int));
    int *nilai = (int *)malloc(n * sizeof(int));

    if (nim == NULL || nilai == NULL) {
        printf("Alokasi memori gagal.\n");
        return 1; // Keluar dengan kode error
    }

    // Meminta input NIM siswa
    printf("Masukkan %d NIM Siswa: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nim[i]) != 1) {
            printf("Input NIM tidak valid. Harap masukkan bilangan bulat.\n");
            free(nim);
            free(nilai);
            return 1;
        }
    }

    // Meminta input Nilai siswa
    printf("Masukkan %d Nilai Siswa: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nilai[i]) != 1) {
            printf("Input nilai tidak valid. Harap masukkan bilangan bulat.\n");
            free(nim);
            free(nilai);
            return 1;
        }
    }

    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");

    // Implementasi Insertion Sort
    for (int i = 1; i < n; i++) {
        int key_nim = nim[i];
        int key_nilai = nilai[i];
        int j = i - 1;

        /* Pindahkan elemen nim[0..i-1] yang lebih besar dari key_nim
           ke satu posisi di depan posisi saat ini */
        while (j >= 0 && nim[j] > key_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j]; // Pindahkan nilai juga
            j = j - 1;
        }
        nim[j + 1] = key_nim;
        nilai[j + 1] = key_nilai;

        // Menampilkan status setelah setiap pass (setelah satu elemen dimasukkan ke posisi yang benar di bagian yang terurut)
        display_arrays(nim, nilai, n, i); // Perhatikan bahwa pass dimulai dari 1
    }

    // Setelah semua pass selesai, array sudah terurut
    // Anda bisa menambahkan tampilan akhir jika diperlukan, tapi soal hanya meminta per pass

    // Membersihkan memori yang dialokasikan
    free(nim);
    free(nilai);

    return 0;
}
