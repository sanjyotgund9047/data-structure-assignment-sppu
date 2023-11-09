/*Add the code in SETA(Q1) and SETB(Q1) to Print Time complexity for Quick sort and Merge sort.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ... Rest of the code for Quick Sort

int main() {
    int arr[5];

    // ...

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
    quickSort(arr, 0, 4);
    end_time = clock();

 printf("Sorted numbers in ascending order: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Quick Sort: %f seconds\n", cpu_time_used);

    return 0;
}

