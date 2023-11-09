/*Write a C program to convert adjacency matrix into adjacency list. Display the adjacency list.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define an array to store the adjacency list
struct Node* adjacencyList[MAX_SIZE];

// Function to add an edge to the adjacency list
void addEdge(int fromVertex, int toVertex) {
    // Create a new node for the 'toVertex'
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = toVertex;
    newNode->next = NULL;

    // Add the 'toVertex' to the adjacency list of 'fromVertex'
    if (adjacencyList[fromVertex] == NULL) {
        adjacencyList[fromVertex] = newNode;
    } else {
        struct Node* current = adjacencyList[fromVertex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // For an undirected graph, add an edge from 'toVertex' to 'fromVertex' as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = fromVertex;
    newNode->next = NULL;

    if (adjacencyList[toVertex] == NULL) {
        adjacencyList[toVertex] = newNode;
    } else {
        struct Node* current = adjacencyList[toVertex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the adjacency list
void displayAdjacencyList(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        printf("Adjacency list of vertex %d: ", i);
        struct Node* current = adjacencyList[i];
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int numVertices;
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Initialize the adjacency list
    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = NULL;
    }

    // Convert the adjacency matrix to adjacency list
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                addEdge(i, j);
            }
        }
    }

    // Display the adjacency list
    displayAdjacencyList(numVertices);

    return 0;
}

/*Output
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
Adjacency list of vertex 0: 1 -> 2 -> NULL
Adjacency list of vertex 1: 0 -> 2 -> 3 -> NULL
Adjacency list of vertex 2: 0 -> 1 -> NULL
Adjacency list of vertex 3:

*/