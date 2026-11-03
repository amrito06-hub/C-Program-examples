/*Write a program to insert a value into a Binary Search Tree (BST), then print the tree’s values using an inorder traversal//#include <stdio.h> */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int value) {
    if (root == NULL) {
        Node *node = malloc(sizeof(Node));
        if (node == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root; // Duplicate values are ignored.
}

void inorder(const Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int count, value;

    printf("How many values? ");
    if (scanf("%d", &count) != 1 || count < 0) {
        fprintf(stderr, "Invalid count.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Invalid value.\n");
            freeTree(root);
            return EXIT_FAILURE;
        }
        root = insert(root, value);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}