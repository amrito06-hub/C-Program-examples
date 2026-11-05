#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("%d added to the queue\n", value);
}

void dequeue(void) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("%d removed from the queue\n", queue[front++]);

    if (front > rear) {
        front = rear = -1;
    }
}

void display(void) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    dequeue();
    display();

    return 0;
}