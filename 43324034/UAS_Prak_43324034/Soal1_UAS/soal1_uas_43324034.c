/*
NIM          :  43324034
Nama         :  Jonathan pasaribu
Nama Program :  Insertion Sort
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int Array[], int N)
{
    int i, j, key, k;
    for (i = 1; i < N; i++)
    {
        key = Array[i];
        j = i - 1;
        while (j >= 0 && key < Array[j])
        {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
        printf("Pass-%d: ", i);
        for (k = 0; k < N; k++)
        {
            printf("%d ", Array[k]);
        }
        printf("\n");
    }
}

void inputArray(int Array[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void separateArray(int original[], int N, int evenArray[], int *evenCount, int oddArray[], int *oddCount)
{
    *evenCount = 0;
    *oddCount = 0;
    for (int i = 0; i < N; i++)
    {
        if (original[i] % 2 == 0)
        {
            evenArray[*evenCount] = original[i];
            (*evenCount)++;
        }
        else
        {
            oddArray[*oddCount] = original[i];
            (*oddCount)++;
        }
    }
}

int main()
{
    int Array[100];
    int evenArray[100], oddArray[100];
    int N, evenCount, oddCount;

    printf("Masukkan Jumlah Data Array: ");
    scanf("%d", &N);
    printf("Masukkan %d elemen pada Array: ", N);
    inputArray(Array, N);

    printf("Data Array Sebelum Proses Insertion Sort: ");
    printArray(Array, N);

    separateArray(Array, N, evenArray, &evenCount, oddArray, &oddCount);

    printf("\nData Array Genap Setelah Proses Insertion Sort:\n");
    insertionSort(evenArray, evenCount);

    printf("\nData Array Ganjil Setelah Proses Insertion Sort:\n");
    insertionSort(oddArray, oddCount);

    return 0;
}
