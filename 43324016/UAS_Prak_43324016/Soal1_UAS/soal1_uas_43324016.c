#include <stdio.h>

// Structure to hold student data
typedef struct {
    int nim;
    int nilai;
} Siswa;

// Function to perform insertion sort and print each pass
void insertionSort(Siswa arr[], int n) {
    int i, j;
    Siswa key;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key.nim
        // to one position ahead of their current position
        while (j >= 0 && arr[j].nim > key.nim) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
        // Print the current pass
        printf("Pass-%d:\n", i);
        printf("NIM   : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k].nim);
        }
        printf("\nNilai : ");
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k].nilai);
        }
        printf("\n\n");
    }
}

int main() {
    int n;
    
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &n);
    
    Siswa siswa[n];
    
    printf("Masukkan %d NIM Siswa : \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &siswa[i].nim);
    }
    
    printf("Masukkan %d Nilai Siswa : \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &siswa[i].nilai);
    }
    
    printf("\nUrutan Berdasarkan NIM Setelah Insertion Sort : \n");
    insertionSort(siswa, n);
    
    return 0;
}