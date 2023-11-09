/* Write a C program to implement Static implementation of stack of integers with following
operation:
a) Initialize()
b) push()
c) pop()
d) isempty()
e) isfull()
f) display()
g) peek()*/

#include <stdio.h>

#define MAX_SIZE 100 // Maximum stack size

int stack[MAX_SIZE]; // Static array to implement the stack
int top = -1; // Initialize the top of the stack

// Function to initialize the stack
void Initialize() {
    top = -1; // Set the top to -1 to indicate an empty stack
}

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    top--;
}

// Function to check if the stack is empty
int isempty() {
    return top == -1;
}

// Function to check if the stack is full
int isfull() {
    return top == MAX_SIZE - 1;
}

// Function to display the elements in the stack
void display() {
    if (isempty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Function to peek at the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return -1 as an error indicator
    }
    return stack[top];
}

int main() {
    Initialize();
    push(10);
    push(20);
    push(30);
    display();
    printf("Top of the stack: %d\n", peek());
    pop();
    display();
    printf("Is stack empty? %s\n", isempty() ? "Yes" : "No");
    printf("Is stack full? %s\n", isfull() ? "Yes" : "No");

    return 0;
}


/*Output
Stack elements: 10 20 30
Top of the stack: 30
Stack elements: 10 20
Is stack empty? No
Is stack full? No   
*/