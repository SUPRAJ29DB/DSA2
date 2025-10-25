#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
   struct  node *right;
}node;

node *createnode(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void preorder(node *root)
{
    if (root==NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL) return;

    inorder(root->left);        // Traverse left subtree FIRST
    printf("%d ", root->data);  // Then process root
    inorder(root->right);
}

void postorder(node *root)
{
    if (root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    // Create this tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6

    node * root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);

    /*printf("Tree Structure:\n");
    printf("       1\n");
    printf("      / \\\n");
    printf("     2   3\n");
    printf("    / \\   \\\n");
    printf("   4   5   6\n\n");
*/
    printf("PRE-ORDER Traversal (Root → Left → Right):\n");
    printf("Output: ");
    preorder(root);
   // printf("\nExplanation: 1 2 4 5 3 6\n\n");

    printf("IN-ORDER Traversal (Left → Root → Right):\n");
    printf("Output: ");
    inorder(root);
   // printf("\nExplanation: 4 2 5 1 3 6\n\n");

    printf("POST-ORDER Traversal (Left → Right → Root):\n");
    printf("Output: ");
    postorder(root);
  //  printf("\nExplanation: 4 5 2 6 3 1\n");


    return 0;
}//
// Created by Suprakash Ghosh on 25-10-2025.
//