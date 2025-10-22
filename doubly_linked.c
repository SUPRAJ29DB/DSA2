#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_node(int data) {
    node *newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insert_at_beginning(node **head, int data) {
    node *newnode = create_node(data);
    if (*head != NULL) {
        (*head)->prev = newnode;
        newnode->next = *head;
    }
    *head = newnode;
}

void insert_at_end(node **head, int data) {
    node *newnode = create_node(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void display(node *head) {
    node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d < >", temp->data);
        temp = temp->next;

    }
    printf("\n");
}

int main() {
    node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_beginning(&head, 5);
    insert_at_end(&head, 30);

    display(head);

    return 0;
}

//
// Created by Suprakash Ghosh on 19-10-2025.
//