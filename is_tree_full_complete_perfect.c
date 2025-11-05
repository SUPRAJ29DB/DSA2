#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* createNode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to find the depth of the leftmost leaf
int findDepth(node* root) {
    int d = 0;
    while (root != NULL) {
        d++;
        root = root->left;
    }
    return d;
}

// Function to check if the tree is perfect
int isPerfect(node* root, int depth, int level) {
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return (depth == level + 1);
    if (root->left == NULL || root->right == NULL)
        return 0;
    return isPerfect(root->left, depth, level + 1) &&
           isPerfect(root->right, depth, level + 1);
}

// Function to check if the tree is full
int isFull(node* root) {
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left && root->right)
        return isFull(root->left) && isFull(root->right);
    return 0;
}

// Queue implementation for level-order traversal
typedef struct queue {
    node* data;
    struct queue* next;
} queue;

void enqueue(queue** front, queue** rear, node* data) {
    queue* newnode = (queue*)malloc(sizeof(queue));
    newnode->data = data;
    newnode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newnode;
    } else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

node* dequeue(queue** front, queue** rear) {
    if (*front == NULL) return NULL;
    queue* temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    node* data = temp->data;
    free(temp);
    return data;
}

// Function to check if the tree is complete
int isComplete(node* root) {
    if (root == NULL)
        return 1;

    queue* front = NULL;
    queue* rear = NULL;
    int flag = 0;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        node* temp = dequeue(&front, &rear);

        if (temp->left) {
            if (flag) return 0;
            enqueue(&front, &rear, temp->left);
        } else {
            flag = 1;
        }

        if (temp->right) {
            if (flag) return 0;
            enqueue(&front, &rear, temp->right);
        } else {
            flag = 1;
        }
    }
    return 1;
}

// Function to free the entire tree
void freeTree(node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /*
            10
           /  \
         5     20
        / \
       3   7
    */
    node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    int depth = findDepth(root);
    printf("Tree Properties:\n");
    printf("Is Full Binary Tree? %s\n", isFull(root) ? "Yes" : "No");
    printf("Is Perfect Binary Tree? %s\n", isPerfect(root, depth, 0) ? "Yes" : "No");
    printf("Is Complete Binary Tree? %s\n", isComplete(root) ? "Yes" : "No");

    freeTree(root);
    return 0;
}//
// Created by Suprakash Ghosh on 05-11-2025.
//