/*Write a C program to reverse the given string by using static implementation of stack.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
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
    struct Stack stack;
    Initialize(&stack);

    char input[MAX_SIZE];
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

    return 0;
}

/*Outputs
Enter a string: hello World!
Reversed String: !dlroW olleh
*/