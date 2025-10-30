#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function to initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push an element to stack
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

// Pop an element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Indicates error
    }
    return s->items[(s->top)--];
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if parentheses are balanced
int isBalanced(char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s))
                return 0; // No matching opening bracket
            char top = pop(&s);
            if (!isMatchingPair(top, c))
                return 0; // Mismatched pair
        }
    }

    return isEmpty(&s); // True if stack is empty at the end
}

int main() {
    char expr[MAX];

    printf("Enter an expression with parentheses: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf(" Parentheses are balanced.\n");
    else
        printf(" Parentheses are NOT balanced.\n");
    return 0;
}
// Created by Suprakash Ghosh on 30-10-2025.
