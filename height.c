#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *createnode(int data)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int height(node *root)
{
    if (root==NULL)
        return 0;
    int left_height=height(root->left);
    int right_height=height(root->right);
    return (left_height>right_height)? left_height+1:right_height+1;
}
int main() {
    printf("=== TREE HEIGHT CALCULATION ===\n\n");

    // TEST CASE 1: Empty Tree
    printf("Test 1 - Empty Tree:\n");
    node* root1 = NULL;
    printf("Height: %d\n", height(root1));
    printf("(Height of empty tree is 0)\n\n");

    // TEST CASE 2: Single Node
    printf("Test 2 - Single Node:\n");
    node* root2 = createnode(1);
    printf("Tree: [1]\n");
    printf("Height: %d\n", height(root2));
    printf("(Single node has height 1)\n\n");

    // TEST CASE 3: Balanced Tree
    printf("Test 3 - Balanced Tree (Height 3):\n");
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    node* root3 = createnode(1);
    root3->left = createnode(2);
    root3->right = createnode(3);
    root3->left->left = createnode(4);
    root3->left->right = createnode(5);

    printf("Tree Structure:\n");
    printf("       1\n");
    printf("      / \\\n");
    printf("     2   3\n");
    printf("    / \\\n");
    printf("   4   5\n");
    printf("Height: %d\n\n", height(root3));

    // TEST CASE 4: Skewed Tree (Left Skewed)
    printf("Test 4 - Left Skewed Tree (Height 4):\n");
    //       1
    //      /
    //     2
    //    /
    //   3
    //  /
    // 4
    node* root4 = createnode(1);
    root4->left = createnode(2);
    root4->left->left = createnode(3);
    root4->left->left->left = createnode(4);

    printf("Tree Structure:\n");
    printf("       1\n");
    printf("      /\n");
    printf("     2\n");
    printf("    /\n");
    printf("   3\n");
    printf("  /\n");
    printf(" 4\n");
    printf("Height: %d\n\n", height(root4));

    // TEST CASE 5: Complex Tree
    printf("Test 5 - Complex Tree (Height 4):\n");
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6
    //      /
    //     7
    node* root5 = createnode(1);
    root5->left = createnode(2);
    root5->right = createnode(3);
    root5->left->left = createnode(4);
    root5->right->left = createnode(5);
    root5->right->right = createnode(6);
    root5->right->left->left = createnode(7);

    printf("Tree Structure:\n");
    printf("       1\n");
    printf("      / \\\n");
    printf("     2   3\n");
    printf("    /   / \\\n");
    printf("   4   5   6\n");
    printf("      /\n");
    printf("     7\n");
    printf("Height: %d\n\n", height(root5));

    // Free all trees
   /* freeTree(root2);
    freeTree(root3);
    freeTree(root4);
    freeTree(root5);
    */
    return 0;
}
//
// Created by Suprakash Ghosh on 27-10-2025.
//