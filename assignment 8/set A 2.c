/* Add a function in Q1 (above question) to count total degree, indegree and outdegree of the graph*/

#include <stdio.h>

#define MAX_SIZE 100

void calculateDegrees(int adjacencyMatrix[][MAX_SIZE], int numVertices) {
    int inDegree[MAX_SIZE] = {0};
    int outDegree[MAX_SIZE] = {0};
    int totalDegree[MAX_SIZE] = {0};

    // Calculate in-degrees and out-degrees
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                outDegree[i]++;
                inDegree[j]++;
                totalDegree[i]++;
                totalDegree[j]++;
            }
        }
    }

    // Display degrees
    printf("Vertex\tIn-Degree\tOut-Degree\tTotal Degree\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, inDegree[i], outDegree[i], totalDegree[i]);
    }
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

    // Display the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and display degrees
    calculateDegrees(adjacencyMatrix, numVertices);

    return 0;
}

/*output
Enter the number of vertices: 4
Enter the adjacency matrix:
1 0 1 0 
0 1 0 1
0 0 1 1 
1 1 0 0 
Adjacency Matrix:
1       0       1       0
0       1       0       1
0       0       1       1
1       1       0       0
Vertex  In-Degree       Out-Degree      Total Degree
0       2               2               4
1       2               2               4
2       2               2               4
3       2               2               4
*/