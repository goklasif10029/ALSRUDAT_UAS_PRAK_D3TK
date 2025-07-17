/*  Nama : Markos Panjaitan
    NIM  : 43324021
    Nama Program : soal1_UAS_43324021
*/

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int Array[], int N){
    int i, j, key;
    for (i = 1; i < N; i++){
        key = Array[i];
        j = i - 1;
        while(j >= 0 && key < Array[j]){
            Array[j+1] = Array[j];
            j = j - 1;
        }
        Array[j+1] = key;
        
        // Display the array after each pass
        printf("Pass-%d: ", i );
        for (int k = 0; k < N; k++) {
            printf("%d ", Array[k]);
        }
        printf("\n");
    }
}

void inputArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

int main(){
    int Array[100];
    int i, N;
    
    printf("Masukkan Jumlah Siswa : ");
    scanf("%d", &N);
    
    printf("Masukkan  %d NIM siswa: ", N);
    inputArray(Array, N);
    printf("Masukkan  %d Nilai  siswa: ", N);
    inputArray(Array, N);
    printf("Original Sequence: ");
    printArray(Array, N);
    
    printf("Sorted using Insertion Sort:\n");
    insertionSort(Array, N);
    printf("Enter %d Element Array: ", N);
    inputArray(Array, N);
    
    printf("Sorted using Insertion Sort:\n");
    insertionSort(Array, N);
    
}