/* Write a C program to accept the following array and find ‘x=26’ is whether present in array or not. 
A[7] = {11, 5, 45, 26, 12,34,19}*/

#include <stdio.h>

int main() {
    int A[] = {11, 5, 45, 26, 12, 34, 19};
    int x = 26;
    int n = sizeof(A) / sizeof(A[0]);  // Calculate the size of the array

    int found = 0;  // Initialize a flag to indicate whether x is found

    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            found = 1;  // Set the flag to indicate x is found
            break;       // Exit the loop once x is found
        }
    }

    if (found) {
        printf("x=%d is present in the array.\n", x);
    } else {
        printf("x=%d is not present in the array.\n", x);
    }

    return 0;
}

/*Output
x=26 is present in the array.*/