#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    
    if (front == -1)
        front = 0;
    
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    
    printf("%d dequeued from the queue.\n", queue[front]);
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    
    return 0;
}

