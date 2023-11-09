/*Write a C program to Implement Dynamic implementation of circular queue of integers with
followingoperation:
a)Initialize()
b) insert()
c)delete()
d) isempty()
e)display()
f) peek()
*/

#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int* data;
    int front, rear, capacity;
};

void Initialize(struct CircularQueue* queue, int capacity) {
    queue->data = (int*)malloc(capacity * sizeof(int));
    if (queue->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
}

int isempty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

int isfull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void insert(struct CircularQueue* queue, int value) {
    if (isfull(queue)) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }

    if (isempty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->data[queue->rear] = value;
}

int delete(struct CircularQueue* queue) {
    int item;
    if (isempty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    } else {
        item = queue->data[queue->front];

        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->capacity;
        }

        return item;
    }
}

int peek(struct CircularQueue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue->data[queue->front];
}

void display(struct CircularQueue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->data[i]);
        if (i == queue->rear)
            break;
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    int capacity;

    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Initialize(&queue, capacity);

    insert(&queue, 10);
    insert(&queue, 20);
    insert(&queue, 30);
    insert(&queue, 40);

    display(&queue);

    printf("Peek: %d\n", peek(&queue));

    delete(&queue);
    display(&queue);

    free(queue.data);

    return 0;
}

/*Enter the capacity of the queue: 5
Queue elements: 10 20 30 40 
Peek: 10
Queue elements: 20 30 40
*/