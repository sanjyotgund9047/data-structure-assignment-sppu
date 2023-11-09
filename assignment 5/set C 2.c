/*Write a C program to convert infix expression to postfix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_SIZE 100

struct Stack {
    char data[MAX_EXPRESSION_SIZE];
    int top;
};

void Initialize(struct Stack* stack) {
    stack->top = -1;
}

int isempty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char value) {
    stack->data[++stack->top] = value;
}

char pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

char peek(struct Stack* stack) {
    return stack->data[stack->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int isAlphaNumeric(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack operatorStack;
    Initialize(&operatorStack);

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char currentChar = infix[i];
        if (isAlphaNumeric(currentChar)) {
            postfix[postfixIndex++] = currentChar;
        } else if (currentChar == '(') {
            push(&operatorStack, currentChar);
        } else if (currentChar == ')') {
            while (!isempty(&operatorStack) && peek(&operatorStack) != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the '('
        } else if (isOperator(currentChar)) {
            while (!isempty(&operatorStack) && precedence(peek(&operatorStack)) >= precedence(currentChar)) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, currentChar);
        }
    }

    while (!isempty(&operatorStack)) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    postfix[postfixIndex] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX_EXPRESSION_SIZE];
    char postfix[MAX_EXPRESSION_SIZE];
    
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

/*outputs
Enter an infix expression: (A + B) * (C - D)
Postfix expression: AB+CD-*
*/