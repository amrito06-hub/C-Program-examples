
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int main()
{
    struct node *root;
    struct node *second;
    struct node *third;

    // Create nodes
    root = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Insert data
    root->data = 10;
    second->data = 20;
    third->data = 30;

    // Connect nodes
    root->left = second;
    root->right = third;

    second->left = NULL;
    second->right = NULL;

    third->left = NULL;
    third->right = NULL;

    // Display
    printf("Root Node: %d", root->data);
    printf("\nLeft Child: %d", root->left->data);
    printf("\nRight Child: %d", root->right->data);

    return 0;
}
