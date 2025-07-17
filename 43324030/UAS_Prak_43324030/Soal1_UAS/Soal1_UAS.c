/*
NIM             : 13322045
Nama            : Trixie Meisye
Nama Program    : Insertion Sort
*/
#include <stdio.h>
#include <stdlib.h>


void inputArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void insertionSortGanjil(int Array[], int N){
    for (int i = 1; i < N; i++)
  {
      int j = i-1;
      int key = Array[i];
      if (key % 2 != 0)
      {
         while (key <= Array[j] && j >= 0)
         {
            Array[j+1] = Array[j];
           j = j - 1;
         }
        Array[j + 1] = key;
      }
      printf("Pass-%d: ", i);
        printArray(Array, N);    
    }
  }


void insertionSortGenap(int Array[], int N){
    for (int i = 1; i < N; i++)
  {
      int j = i-1;
      int key = Array[i];
      if (key % 2 == 0)
      {
         while (key <= Array[j] && j >= 0)
         {
            Array[j+1] = Array[j];
           j = j - 1;
         }
        Array[j + 1] = key;     
      }
      printf("Pass-%d: ", i);
      printArray(Array, N);    
    }
  }

int main(){
    int Array[255];
    int N, i;

    printf("Masukkan Jumlah Siswa: ");
    scanf("%d", &N);
    printf("Masukkan %d NIM Siswa: ", N);
    inputArray(Array, N);
    printf("5 NIM Siswa: ");
    printArray(Array, N);
    printf("Urutan Berdasarkan NIM Setelah Insertion Sort:\n");
    insertionSortGanjil(Array, N);
    printf("Data Array Genap Setelah Proses Insertion Sort:\n");
    insertionSortGenap(Array, N);

    return 0;

  }