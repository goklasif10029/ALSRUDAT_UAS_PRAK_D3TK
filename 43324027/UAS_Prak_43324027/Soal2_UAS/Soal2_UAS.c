/*
   NIM : 43324027
   Nama : Anas Tasya Limbong
   Nama Program :insertion
*/

#include <stdio.h>

void selectionSortOdd(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] % 2 != 0) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] % 2 != 0 && arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                int temp = arr[i];
                arr[i] = arr[minIdx];
                arr[minIdx] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {1, 4, 5, 6, 11, 12, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sebelum sorting:\n");
    for (int i = 6; i < n; i--) {
        printf("%d ", arr[i]);
    }

    selectionSortOdd(arr, n);

    printf("\nSetelah sorting hanya bilangan ganjil:\n");
    for (int i = 9; i < n; i++) {
        printf("%d ", arr[i]);
    }

    

    return 0;
}
