/*Write a C program to accept n elements from user store it in an array. Accept a value from the user 
and use recursive binary search method to check whether the value is present in array or not.*/

#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return 1;  // Element found
        }

        if (arr[mid] < x) {
            return binarySearch(arr, mid + 1, right, x);
        }

        return binarySearch(arr, left, mid - 1, x);
    }

    return 0;  // Element not found
}

     int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Create an array of size 'n'

    // Input values into the array (assume the array is sorted)
    printf("Enter %d sorted integers for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

     int searchNumber;

    // Ask the user for the number to search
    printf("Enter the number to search: ");
    scanf("%d", &searchNumber);

    int found = binarySearch(arr, 0, n - 1, searchNumber);

    if (found) {
        printf("%d is present in the array.\n", searchNumber);
    } else {
        printf("%d is not present in the array.\n", searchNumber);
    }

    return 0;
}

/*Output
Enter the number of elements in the array: 5
Enter 5 sorted integers for the array:
10
20
30
40
50
Enter the number to search: 40
40 is present in the array.*/