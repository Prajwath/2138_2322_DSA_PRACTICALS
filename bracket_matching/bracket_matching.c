#include "bracket_matching.h"
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a stack
typedef struct {
    char* array;
    int size;
    int top;
} Stack;

// Function to initialize a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (char*)malloc(stack->size * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';  // Null character indicates an empty stack
}

// Function to check if brackets are matched
int areBracketsMatched(const char* expression) {
    Stack* stack = createStack(strlen(expression));
    
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return 0;
            }
            char topChar = pop(stack);
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == '}' && topChar != '{') ||
                (expression[i] == ']' && topChar != '[')) {
                free(stack->array);
                free(stack);
                return 0;
            }
        }
    }
    
    int result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}
