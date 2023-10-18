#include "infix2postfix.h"
#include <string.h>
#include <stdio.h>

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

int isFull(Stack *stack) {
    return (stack->top == MAX_STACK_SIZE - 1);
}

void push(Stack *stack, char item) {
    if (!isFull(stack)) {
        stack->stack[++stack->top] = item;
    } else {
        printf("Stack is full. Cannot push %c\n", item);
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->stack[stack->top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return '0';  // You can choose another value to indicate an error.
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.stack[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.stack[stack.top] != '(')
                return; // Invalid expression
            else
                pop(&stack);
        } else {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(stack.stack[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}
