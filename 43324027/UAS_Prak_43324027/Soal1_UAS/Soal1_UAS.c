/*
 NIM            : Anas Tasya Limbong
 Nama           : 43324027
 Nama Program   : insertionsort
*/

#include <stdio.h>
#include <stdlib.h>

void printPass(int Array[], int N, int pass) {
    printf("Pass-%d: ", pass);
    for (int i = 0; i < N; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void insertionSort(int Array[], int N) {
    int i, j, key;
    for (i = 1; i < N; i++) {
        key = Array[i];
        j = i - 1;
        while (j >= 0 && key < Array[j]) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
        printPass(Array, N, i);
    }
}

void inputArray(int Array[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &Array[i]);
    }
}

void printArray(int Array[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

int main() {
    int Array[100];
    int N;

    printf("90, 72, 86, 66, 54: ");
    scanf("%d", &N);

    printf("Enter %d Element Array: ", N);
    inputArray(Array, N);

    printf("Original Sequence: ");
    printArray(Array, N);

    printf("Sorted using Insertion Sort:\5");
    insertionSort(Array, N);

    return 0;
}

 