/*Write a C program to read a graph as adjacency matrix and Traverse using BFS*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a queue for BFS
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Add an item to the rear of the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Remove and return an item from the front of the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Breadth-First Search traversal
void bfsTraversal(int adjacencyMatrix[][MAX_SIZE], int numVertices, int startVertex) {
    int visited[MAX_SIZE] = {0}; // 0 for unvisited, 1 for visited
    struct Queue q;

    initQueue(&q);
    visited[startVertex] = 1;
    printf("BFS Traversal starting from vertex %d: ", startVertex);

    printf("%d ", startVertex);
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfsTraversal(adjacencyMatrix, numVertices, startVertex);

    return 0;
}

/*Output
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
Enter the starting vertex for BFS: 0
BFS Traversal starting from vertex 0: 0 1 2 3 
*/