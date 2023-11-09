/*To read the data from the file “employee.txt” which contains empno and empname and 
sort the data on names alphabetically (use strcmp) using Bubble Sort.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee record
struct Employee {
    int empno;
    char empname[100];
};

// Function to perform Bubble Sort based on employee names
void bubbleSort(struct Employee empArr[], int n) {
    int i, j;
    struct Employee temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(empArr[j].empname, empArr[j + 1].empname) > 0) {
                // Swap empArr[j] and empArr[j+1]
                temp = empArr[j];
                empArr[j] = empArr[j + 1];
                empArr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    file = fopen("person.txt","r");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    // Count the number of lines in the file
    int n = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        n++;
    }

    // Move the file pointer back to the beginning
    rewind(file);

    // Create an array of employee records
    struct Employee empArr[n];

    // Read data from the file into the array
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %s", &empArr[i].empno, empArr[i].empname);
    }

    // Sort the data using Bubble Sort
    bubbleSort(empArr, n);

    // Close the file
    fclose(file);

    // Print the sorted data
    printf("Sorted data based on employee names:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", empArr[i].empno, empArr[i].empname);
    }

    return 0;
}

/*Output

*/
