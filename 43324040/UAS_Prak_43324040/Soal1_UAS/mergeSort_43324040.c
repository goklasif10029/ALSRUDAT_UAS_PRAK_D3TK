/*
    NIM : 43324040
    Nama : Gian Gilly sibarani
    Nama Program : mergeSort.c
*/

#include<stdio.h>
#include<stdlib.h>

// Merge  two subarrays L and M into arr
void merge(int Array[], int p, int q, int r){

    // Create L <- A[p..q] and M <- A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    L[i] = Array[p + i];
    for (int j = 0; j < n2; j++)
    M[j] = Array[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick large among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2){
        if (L[i] <= M[j]){
            Array[k] = L[i];
            i++;
        } else{
            Array[k] = M[j];
            j++;
        }
        k++;
    }

    //When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1){
        Array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        Array[k]= M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int Array[], int l, int r){
    if (1 < r){

        // m is the point where the array is divided into two subarrays
        int m = 1 + (r - l) / 2;

        mergeSort(Array, l, m);
        mergeSort(Array, m + 1, r);

        // Merge the sorted subarrays
        merge(Array, l, m, r);
    }
}


void inputArray(int Array[], int N){
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d",&Array[i]);
    }

}

void printArray(int Array[], int N){
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d ",Array[i]);
    }
    printf("\n");

}

int main(){
    int Array[100];
    int i,N;

    printf("Enter Number of Array: ");
    scanf("%d",&N);
    printf("Enter %d Element Array: ",N);
    inputArray(Array,N);
    printf("Original Sequence: ");
    printArray(Array,N);

    printf("Sorted using Merge Sort: \n");
    mergeSort(Array,0,N);
    printArray(Array,N);
    
}