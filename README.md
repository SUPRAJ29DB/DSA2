# DSA2
```
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
};

 struct node *top=NULL;
int empty(){
    if (top==NULL){
        return 1;
    }
}
int push(int data)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

int pop() {
    if (empty()) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedValue =top->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack.\n", poppedValue);
    return poppedValue;
}

int peek() {
    if (empty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Display the stack
void display() {
    if (empty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", top->data);
        temp = top->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    printf("Top element: %d\n", peek());

    pop();
    pop();
    pop(); // Attempting to pop from an empty stack

    display();
    return 0;
}
