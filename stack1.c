#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int top;
    unsigned capacity;
    char *array;
}sstack;

sstack *createStack(unsigned capacity)
{
    sstack *stack=(sstack*)malloc(sizeof(sstack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(char*)malloc(stack->capacity*sizeof(char));
    return stack;
}

int full(sstack *s)
{
    return s->top==s->capacity-1;
}

int empty(sstack *s)
{
    return s->top==-1;
}

void push(sstack *s, char item)
{
    if (full(s))
    {
        return ;
    }
    s->array[++s->top]=item;
}

char pop(sstack *s)
{
    if (empty(s))
return '\0';
    {
        return s->array[s->top--];
    }
}

void reversestring(char *str)
{
    int n=strlen(str);
    sstack *stack=createStack(n);
    for (int i=0; i<n; i++)

        push(stack,str[i]);

    for (int i = 0; i < n; i++)
        str[i] = pop(stack);
    free(stack->array);
    free(stack);
}

int main()
{
    char str[] = "// Created by Suprakash Ghosh on 12-10-2025.";
    printf("Original: %s\n", str);
    reversestring(str);
    printf("Reversed: %s\n", str);
    return 0;
}
//
// Created by Suprakash Ghosh on 12-10-2025.
//