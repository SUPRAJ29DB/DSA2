  #include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    int top;
    unsigned capacity;
    char *array;
} sstack;

sstack *createstack(unsigned capacity)
{
    sstack *stack = (sstack*)malloc(sizeof(stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(capacity * sizeof(char));

    if (stack->array == NULL) {
        printf("Memory allocation for array failed!\n");
        free(stack);
        return NULL;
    }

    return stack;
}

int isFull(sstack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(sstack *stack)
{
    return stack->top == -1;
}

void push(sstack *stack, char item)
{
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(sstack *stack)
{
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top--];
}

char peek(sstack *stack)
{
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top];
}

void freeStack(sstack *stack)
{
    if (stack != NULL) {
        free(stack->array);
        free(stack);
    }
}

// Function to check if parentheses are matching
int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// Main function to check parenthesis validity
int isValidExpression(char* expression)
{
    int i = 0;
    int len = strlen(expression);
    sstack *s = createstack(len);

    if (s == NULL) {
        return 0; // Memory allocation failed
    }

    for (i = 0; i < len; i++) {
        // If the character is an opening parenthesis, push it to stack
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(s, expression[i]);
        }
        // If the character is a closing parenthesis
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            // If stack is empty, there's no matching opening parenthesis
            if (isEmpty(s)) {
                freeStack(s);
                return 0;
            }
            // Pop from stack and check if it matches
            else if (!isMatchingPair(pop(s), expression[i])) {
                freeStack(s);
                return 0;
            }
        }
    }

    // If stack is empty, all parentheses are balanced
    int result = isEmpty(s);
    freeStack(s);
    return result;
}

// Function to display the expression with highlighted errors
void checkAndDisplay(char* expression)
{
    printf("Expression: %s\n", expression);

    if (isValidExpression(expression)) {
        printf("Result: VALID - All parentheses are properly balanced!\n");
    } else {
        printf("Result: INVALID - Parentheses are not properly balanced!\n");
    }
    printf("----------------------------------------\n");
}

int main()
{
    // Test cases
    char expr1[] = "{(a+b)*[c-d]}";
    char expr2[] = "((a+b)";
    char expr3[] = "[{()}]";
    char expr4[] = "((a+b)*c)";
    char expr5[] = "[(a+b)*{c-d}]";
    char expr6[] = "((a+b)*c))";
    char expr7[] = "[(a+b)*{c-d}]]";
    char expr8[] = "({[}]))";
    char expr9[] = "";
    char expr10[] = "a+b*c"; // No parentheses

    printf("PARENTHESIS VALIDITY CHECKER\n");
    printf("========================================\n");

    checkAndDisplay(expr1);
    checkAndDisplay(expr2);
    checkAndDisplay(expr3);
    checkAndDisplay(expr4);
    checkAndDisplay(expr5);
    checkAndDisplay(expr6);
    checkAndDisplay(expr7);
    checkAndDisplay(expr8);
    checkAndDisplay(expr9);
    checkAndDisplay(expr10);

    // Interactive input
    char input[100];
    printf("\nEnter an expression to check (or 'quit' to exit): ");

    while (fgets(input, sizeof(input), stdin)) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            break;
        }

        if (strlen(input) > 0) {
            checkAndDisplay(input);
        }

        printf("Enter another expression (or 'quit' to exit): ");
    }

    return 0;
}//
// Created by Suprakash Ghosh on 12-10-2025.
//