/*Write a C program that accepts the graph as an adjacency matrix and checks if the graph is undirected.
The matrix for undirected graph is symmetric*/

#include <stdio.h>

#define MAX_SIZE 100

// Function to check if a matrix is symmetric
int isSymmetric(int adjacencyMatrix[][MAX_SIZE], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

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

    if (isSymmetric(adjacencyMatrix, numVertices)) {
        printf("The graph represented by the adjacency matrix is undirected.\n");
    } else {
        printf("The graph represented by the adjacency matrix is not undirected.\n");
    }

    return 0;
}

/*Output 
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
The graph represented by the adjacency matrix is undirected.
*/