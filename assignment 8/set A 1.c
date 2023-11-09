/*Write a C program to read a graph as adjacency matrix and display the adjacency matrix.*/

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Display the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*output 
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
Adjacency Matrix:
0       1       1       0
1       0       1       1
1       1       0       0
0       1       0       0
*/