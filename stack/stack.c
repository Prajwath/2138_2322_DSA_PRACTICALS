#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack is full. Cannot push %d\n", value);
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // You can choose another value to indicate an error.
    }
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void destroyStack(Stack* stack) {
    free(stack);
}
