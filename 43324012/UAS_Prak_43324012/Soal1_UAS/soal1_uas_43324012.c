// Nama : Adelia P Simarmata 
// Nim  : 43324012

#include <stdio.h>

int main() {
    int n;
    
    // Input jumlah siswa
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);
    
    // Deklarasi array untuk NIM dan Nilai
    int nim[n], nilai[n];
    
    // Input NIM siswa
    printf("Masukkan %d NIM Siswa :\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nim[i]);
    }
    
    // Input Nilai siswa
    printf("Masukkan %d Nilai Siswa :\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }
    
    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort :\n");
    
    // Insertion Sort berdasarkan NIM (ascending)
    for(int pass = 1; pass < n; pass++) {
        int key_nim = nim[pass];
        int key_nilai = nilai[pass];
        int j = pass - 1;
        
        // Geser elemen yang lebih besar dari key ke kanan
        while(j >= 0 && nim[j] > key_nim) {
            nim[j + 1] = nim[j];
            nilai[j + 1] = nilai[j];
            j--;
        }
        
        // Tempatkan key pada posisi yang benar
        nim[j + 1] = key_nim;
        nilai[j + 1] = key_nilai;
        
        // Tampilkan hasil setiap pass
        printf("Pass-%d:\n", pass);
        printf("NIM : ");
        for(int i = 0; i < n; i++) {
            printf("%d ", nim[i]);
        }
        printf("\nNilai : ");
        for(int i = 0; i < n; i++) {
            printf("%d ", nilai[i]);
        }
        printf("\n\n");
    }
    
    return 0;
}