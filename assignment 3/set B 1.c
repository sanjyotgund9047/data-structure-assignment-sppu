/*Write a C program  to create an array of integers.Accept a value from user and use linear search method to check 
whether the given number is present in array or not. Display proper message in output*/

#include <stdio.h>

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Create an array of size 'n'

    // Input values into the array
    printf("Enter %d integers for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int searchNumber;

    // Ask the user for the number to search
    printf("Enter the number to search: ");
    scanf("%d", &searchNumber);

     int found = 0;  // Flag to indicate whether the number is found

    // Linear search to check if the number is present in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchNumber) {
            found = 1;  // Set the flag to indicate the number is found
            break;       // Exit the loop if found
        }
    }

    if (found) {
        printf("%d is present in the array.\n", searchNumber);
    } else {
        printf("%d is not present in the array.\n", searchNumber);
    }

    return 0;
}

/*output
Enter the number of elements in the array: 5
Enter 5 integers for the array:
10 20 30 40 50
Enter the number to search: 20
20 is present in the array.*/