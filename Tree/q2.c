/*Write a C program that builds a Binary Search Tree (BST), asks for a value, and reports whether that value is in the tree.*/

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
            printf("Memory allocation failed.\n");
            exit(1);
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

    return root;
}

int search(Node *root, int target) {
    if (root == NULL)
        return 0;

    if (target == root->value)
        return 1;

    if (target < root->value)
        return search(root->left, target);

    return search(root->right, target);
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
    int count, value, target;

    printf("How many values? ");
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Invalid count.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid value.\n");
            freeTree(root);
            return 1;
        }
        root = insert(root, value);
    }

    printf("Enter a value to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid value.\n");
        freeTree(root);
        return 1;
    }

    if (search(root, target))
        printf("%d is in the tree.\n", target);
    else
        printf("%d is not in the tree.\n", target);

    freeTree(root);
    return 0;
}