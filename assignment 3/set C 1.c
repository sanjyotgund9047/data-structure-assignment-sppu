/*Write a C program to read the data from file 'cities.txt' containing names of 10 cities and their STD 
codes.Acceptanameofthecityfromuseranduselinearsearchalgorithmtocheckwhetherthename is present 
in the file and output the STD code, otherwise output “city not in thelist”*/

#include <stdio.h>
#include <string.h>

#define MAX_CITIES 10

// Structure to represent a city's name and STD code
struct City {
    char name[100];
    int stdCode;
};

int main() {
    // Open the file for reading
    FILE *file = fopen("cities.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read data from the file into an array of city structures
    struct City cities[MAX_CITIES];
    int cityCount = 0;

    while (cityCount < MAX_CITIES && fscanf(file, "%s %d", cities[cityCount].name, &cities[cityCount].stdCode) != EOF) {
        cityCount++;
    }

    // Close the file
    fclose(file);

    // Ask the user for a city name to search
    char searchCity[100];
    printf("Enter the name of the city to search: ");
    scanf("%s", searchCity);

    int found = 0;  // Flag to indicate whether the city is found
    int stdCode = 0; // To store the STD code if found

     // Linear search to check if the city name is present in the array
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cities[i].name, searchCity) == 0) {
            found = 1;
            stdCode = cities[i].stdCode;
            break;
        }
    }

    if (found) {
        printf("STD Code for %s is %d.\n", searchCity, stdCode);
    } else {
        printf("%s is not present in the list.\n", searchCity);
    }

    return 0;
}

/*output
Enter the name of the city to search: nashik
STD Code for nashik is 50331651.*/