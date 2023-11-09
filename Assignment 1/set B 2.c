/*To read the data from the file “person.txt” which contains personno and personage and 
sort the data on age in ascending order using insertion Sort.*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a person record
struct Person {
    int personno;
    int personage;
};

// Function to perform Insertion Sort based on person ages
void insertionSort(struct Person personArr[], int n) {
    int i, j;
    struct Person key;
    for (i = 1; i < n; i++) {
        key = personArr[i];
        j = i - 1;
        while (j >= 0 && personArr[j].personage > key.personage) {
            personArr[j + 1] = personArr[j];
            j = j - 1;
        }
        personArr[j + 1] = key;
    }
}

int main() {
    FILE *file;
    file = fopen("person.txt", "r");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Count the number of lines in the file
    int n = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        n++;
    }

    // Move the file pointer back to the beginning
    rewind(file);

    // Create an array of person records
    struct Person personArr[n];

    // Read data from the file into the array
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d", &personArr[i].personno, &personArr[i].personage);
    }

    // Sort the data using Insertion Sort
    insertionSort(personArr, n);

    // Close the file
    fclose(file);

    // Print the sorted data
    printf("Sorted data based on person ages in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", personArr[i].personno, personArr[i].personage);
    }

    return 0;
}

/*Output
Sorted data based on person ages in ascending order:
3 23
1 25
2 30
*/