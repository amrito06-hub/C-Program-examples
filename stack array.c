#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push()
{
    int n;

    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter an element: ");
        scanf("%d", &n);

        top++;
        stack[top] = n;

        printf("Element pushed successfully.\n");
    }
}

void pop()
{
    int n;

    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        n = stack[top];
        printf("Popped element: %d\n", n);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements of stack:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n..... STACK .....\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("..................\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}