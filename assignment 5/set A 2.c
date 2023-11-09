/*Write a C program to implement Dynamic implementation of stack of integers with following
operation:
a) Initialize()
b) push()
c) pop()
d) isempty()
e) isfull()
f) display()
g) peek()
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* array;
    int top;
    int capacity;
};

// Function to initialize the stack
struct Stack* Initialize(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    return stack;
}

// Function to check if the stack is empty
int isempty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isfull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isfull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    stack->top--;
}

// Function to display the elements in the stack
void display(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return -1 as an error indicator
    }
    return stack->array[stack->top];
}

int main() {
    int capacity = 5; // Set the capacity of the stack
    struct Stack* stack = Initialize(capacity);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);
    printf("Top of the stack: %d\n", peek(stack));
    pop(stack);
    display(stack);
    printf("Is stack empty? %s\n", isempty(stack) ? "Yes" : "No");
    printf("Is stack full? %s\n", isfull(stack) ? "Yes" : "No");

    // Free the dynamically allocated memory
    free(stack->array);
    free(stack);

    return 0;
}

/*Outputs
Stack elements: 10 20 30
Top of the stack: 30
Stack elements: 10 20
Is stack empty? No
Is stack full? No
*/
