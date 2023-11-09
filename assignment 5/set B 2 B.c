/*Write a C program to reverse the given number by using dynamic implementation of
stack*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* data;
    int top;
    int capacity;
};

void Initialize(struct Stack* stack, int capacity) {
    stack->top = -1;
    stack->capacity = capacity;
    stack->data = (int*)malloc(capacity * sizeof(int));
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
    int capacity = 100;
    struct Stack stack;
    Initialize(&stack, capacity);

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

    free(stack.data);

    return 0;
}

/*Outputs
Enter a number: 987654321
Reversed Number: 123456789
*/