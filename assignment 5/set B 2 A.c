/* Write a C program to reverse the given number by using static implementation of
stack.*/

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

int main() {
    struct Stack stack;
    Initialize(&stack);

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int reversedNum = 0;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        push(&stack, digit);
        temp /= 10;
    }

    int placeValue = 1;
    while (!isempty(&stack)) {
        int digit = pop(&stack);
        reversedNum += digit * placeValue;
        placeValue *= 10;
    }

    printf("Reversed Number: %d\n", reversedNum);

    return 0;
}

/*Outputs
Enter a number: 12345
Reversed Number: 54321*/