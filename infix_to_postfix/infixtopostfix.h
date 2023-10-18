#ifndef INFIX2POSTFIX_H
#define INFIX2POSTFIX_H

#define MAX_STACK_SIZE 100

typedef struct {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
int isOperator(char ch);
int precedence(char ch);
void infixToPostfix(const char *infix, char *postfix);

#endif
