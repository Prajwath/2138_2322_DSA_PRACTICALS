
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "postfix_eval.c"
#include "infix_to_postfix.c"

int main() {
    char infix[100]; // Assuming a maximum input length of 100 characters
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char postfixResult[strlen(infix)];
    infixToPostfix(infix, postfixResult);

    printf("Infix to Postfix Conversion Result: %s\n", postfixResult);
    int result = evaluatePostfix(postfixResult);
    printf("Postfix Evaluation Result: %d\n", result);
    return 0;

}

