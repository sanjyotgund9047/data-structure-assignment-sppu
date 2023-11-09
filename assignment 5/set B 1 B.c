/*Write a C program to reverse the given string by using dynamic implementation of stack*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char* data;
    int top;
    int capacity;
};

void Initialize(struct Stack* stack, int capacity) {
    stack->top = -1;
    stack->capacity = capacity;
    stack->data = (char*)malloc(capacity * sizeof(char));
    if (!stack->data) {
        printf("Memory allocation error.\n");
        exit(1);
    }
}

int isempty(struct Stack* stack) {
    return stack->top == -1;
}

int isfull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, char value) {
    if (isfull(stack)) {
        printf("Stack is full. Cannot push %c\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int main() {
    int capacity = 100;
    struct Stack stack;
    Initialize(&stack, capacity);

    char input[capacity];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    for (int i = 0; i < len - 1; i++) {  // Exclude the newline character
        push(&stack, input[i]);
    }

    printf("Reversed String: ");
    while (!isempty(&stack)) {
        putchar(pop(&stack));
    }
    printf("\n");

    free(stack.data);

    return 0;
}

/*Outputs
Enter a string: hello world!
Reversed String: !dlrow olleh
*/