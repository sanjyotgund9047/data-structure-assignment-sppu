/*Write a C program to evaluate postfix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_SIZE 100

struct Stack {
    int data[MAX_EXPRESSION_SIZE];
    int top;
};

void Initialize(struct Stack* stack) {
    stack->top = -1;
}

int isempty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int evaluatePostfix(char* postfix) {
    struct Stack operandStack;
    Initialize(&operandStack);

    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        char currentChar = postfix[i];

        if (isDigit(currentChar)) {
            push(&operandStack, currentChar - '0');  // Convert char to int
        } else if (currentChar == ' ' || currentChar == '\n') {
            continue;  // Skip spaces and newline characters
        } else {
            if (operandStack.top < 1) {
                printf("Error: Invalid postfix expression.\n");
                exit(1);
            }

            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);

            switch (currentChar) {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&operandStack, operand1 / operand2);
                    } else {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Error: Invalid operator '%c'.\n", currentChar);
                    exit(1);
            }
        }
    }

    if (!isempty(&operandStack) && operandStack.top == 0) {
        int result = pop(&operandStack);
        return result;
    } else {
        printf("Error: Invalid postfix expression.\n");
        exit(1);
    }
}

int main() {
    char postfix[MAX_EXPRESSION_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}

/*Outputs
Enter a postfix expression: 45*5+
Result: 25
*/