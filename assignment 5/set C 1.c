/*Write a C program to reverse the stack by using recursive function.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void Initialize(struct Stack* stack) {
    stack->top = -1;
}

int isempty(struct Stack* stack) {
    return stack->top == -1;
}

int isfull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isfull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void display(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(struct Stack* stack, int value) {
    if (isempty(stack)) {
        push(stack, value);
        return;
    }
    int temp = pop(stack);
    insertAtBottom(stack, value);
    push(stack, temp);
}

// Function to reverse a stack using recursion
void reverseStack(struct Stack* stack) {
    if (!isempty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}

int main() {
    struct Stack stack;
    Initialize(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Original Stack: ");
    display(&stack);

    reverseStack(&stack);

    printf("Reversed Stack: ");
    display(&stack);

    return 0;
}

/*Outputs
Original Stack: Stack elements: 10 20 30 40 
Reversed Stack: Stack elements: 40 30 20 10
*/