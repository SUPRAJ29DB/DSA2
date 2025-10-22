#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void insert_at_beginning(node **head, int data) {
    node *newnode = create_node(data);

    // If list is empty
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode; // points to itself
        return;
    }

    // Traverse to the last node
    node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    // Insert new node before head
    newnode->next = *head;
    temp->next = newnode;
    *head = newnode; // update head to newnode
}

// Insert at end
void insert_at_end(node **head, int data) {
    node *newnode = create_node(data);

    // If list is empty
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode; // points to itself
        return;
    }

    node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = *head;
}

// Display the circular linked list
void display(node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
int main() {
    node *head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_beginning(&head, 5);
    insert_at_end(&head, 40);
    insert_at_beginning(&head, 1);

    display(head);

    return 0;
}

// Created by Suprakash Ghosh on 22-10-2025.
//