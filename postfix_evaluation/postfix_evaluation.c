#include "postfix_evaluation.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return (stack->top == MAX_STACK_SIZE - 1);
}

void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->stack[++stack->top] = item;
    } else {
        printf("Stack is full. Cannot push %d\n", item);
        exit(1);  // Terminate the program on error
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->stack[stack->top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);  // Terminate the program on error
    }
}

int evaluatePostfix(const char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0');  // Convert character to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);  // Terminate the program on error
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid postfix expression.\n");
                    exit(1);  // Terminate the program on error
            }
            push(&stack, result);
        }
    }

    if (isEmpty(&stack)) {
        printf("Result: %d\n", stack.stack[stack.top]);
        return stack.stack[stack.top];
    } else {
        printf("Invalid postfix expression.\n");
        exit(1);  // Terminate the program on error
    }
}
