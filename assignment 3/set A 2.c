/* Write a C program to accept a search element form user and using binary search method findw hether given 
element is present or not in the following array.
A[10] = {1,5,7,12,13,16,17,22,24}
*/
#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return 1;  // Element found
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;  // Element not found
}

int main() {
    int A[] = {1, 5, 7, 12, 13, 16, 17, 22, 24};
    int n = sizeof(A) / sizeof(A[0]);

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int found = binarySearch(A, n, x);

    if (found) {
        printf("%d is present in the array.\n", x);
    } else {
        printf("%d is not present in the array.\n", x);
    }

    return 0;
}

/*Output
Enter the element to search: 7
7 is present in the array.*/