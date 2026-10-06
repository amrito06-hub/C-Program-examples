#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue - Insert Element
void enqueue(int value)
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value;

    if (front == NULL)
    {
        front = rear = new_node;
        rear->next = front;
    }
    else
    {
        new_node->next = front;
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d inserted into circular queue\n", value);
}

// Dequeue - Delete Element
void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue underflow\n");
        return;
    }

    // Only one node
    if (front == rear)
    {
        printf("%d deleted from queue\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;

        printf("%d deleted from queue\n", front->data);

        front = front->next;
        rear->next = front;

        free(temp);
    }
}

// Display Queue
void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Circular queue is empty\n");
        return;
    }

    temp = front;

    printf("Circular Queue: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

// Main Function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- Circular Queue -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program exited.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}