/*1) Write a C program to Implement Static implementation of Queue of integers with following
operation:
a) Initialize()
b) insert()
c) delete()
d) isempty()
e) isfull()
f) display()
g) peek()*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

void Initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isempty(struct Queue* queue) {
    return (queue->front == -1);
}

bool isfull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void insert(struct Queue* queue, int value) {
    if (isfull(queue)) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }

    if (isempty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = value;
}

int delete(struct Queue* queue) {
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
            queue->front = (queue->front + 1) % MAX_SIZE;
        }

        return item;
    }
}

int peek(struct Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue->data[queue->front];
}

void display(struct Queue* queue) {
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
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    Initialize(&queue);

    insert(&queue, 10);
    insert(&queue, 20);
    insert(&queue, 30);
    insert(&queue, 40);

    display(&queue);

    printf("Peek: %d\n", peek(&queue));

    delete(&queue);
    display(&queue);

    return 0;
}

/*Outputs
Queue elements: 10 20 30 40 
Peek: 10
Queue elements: 20 30 40
*/