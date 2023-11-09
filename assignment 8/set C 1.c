/*Write a C program to read a graph as adjacency matrix and Traverse using DFS*/


#include <stdio.h>

#define MAX_SIZE 100

// Function for Depth-First Search (DFS) traversal
void dfsTraversal(int adjacencyMatrix[][MAX_SIZE], int visited[], int numVertices, int currentVertex) {
    printf("%d ", currentVertex); // Visit the current vertex
    visited[currentVertex] = 1;   // Mark it as visited

    // Traverse all adjacent vertices
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
            dfsTraversal(adjacencyMatrix, visited, numVertices, i);
        }
    }
}

int main() {
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int visited[MAX_SIZE] = {0}; // 0 for unvisited, 1 for visited
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

    printf("DFS Traversal starting from vertex 0: ");
    dfsTraversal(adjacencyMatrix, visited, numVertices, 0);

    return 0;
}

/*Output
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0 
DFS Traversal starting from vertex 0: 0 1 2 3
*/