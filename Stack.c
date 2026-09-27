#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(void);
void pop(void);
void display(void);

int main(void)
{
    int choice;

    do {
        printf("\nStack\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void push(void)
{
    int value;

    if (top == MAX_SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }

    printf("Enter a value to push: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed onto the stack.\n", value);
}

void pop(void)
{
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("%d popped from the stack.\n", stack[top--]);
}

void display(void)
{
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}