#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *createnode(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to print tree in-order
void inOrder(node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Recursive insert function for BST
node *insertRecursive(node *root, int data) {
    // Base case: tree is empty
    if (root == NULL) {
        node *newnode = createnode(data);
        printf("Inserted %d. In-order: ", data);
        inOrder(newnode);
        printf("\n");
        return newnode;
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertRecursive(root->left, data);
    } else if (data > root->data) {
        root->right = insertRecursive(root->right, data);
    }

    // Display in-order after insertion
    printf("After inserting %d. In-order: ", data);
    inOrder(root);
    printf("\n");
    return root;
}

// Function to free all nodes
void freeTree(node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to visually print the tree (right-root-left format)
void printTree(node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

// Main function
int main() {
    node *root = NULL;

    printf("=== BST Insertion with In-order Integration ===\n\n");
    printf("--- Using Recursive Insertion ---\n");

    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);

    printf("\nFinal BST Structure:\n");
    printTree(root, 0);

    printf("\nFinal sorted order: ");
    inOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}

//
// Created by Suprakash Ghosh on 27-10-2025.
//