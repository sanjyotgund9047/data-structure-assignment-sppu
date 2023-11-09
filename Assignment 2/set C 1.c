/*Write a C program to sort the elements by initializing the array (e.g. int A[5] = {11, 12,15, 16, 17}) 
using Merge sort*/

#include <stdio.h>

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int A[5] = {11, 12, 15, 16, 17};

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    mergeSort(A, 0, 4);

    printf("Sorted array using Merge Sort: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}

/*Outputs
Original array: 11 12 15 16 17
Sorted array using Merge Sort: 11 12 15 16 17
*/