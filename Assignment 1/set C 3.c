/*Write a C program to sort the elements by initializing the array (e.g int A[5] = {10, 20, 35, 23, 12}) using 
bubble sort.*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[5] = {10, 20, 35, 23, 12};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    bubbleSort(A, n);

    printf("Sorted array using Bubble Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}

/*outputs
Original array: 10 20 35 23 12 
Sorted array using Bubble Sort: 10 12 20 23 35
*/