#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow: Cannot push element %d\n", value);
        return;
    }

    stack[++top] = value;
    printf("%d pushed to the stack\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return;
    }

    int value = stack[top--];
    printf("Popped element: %d\n", value);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

int main() {
    int choice, value;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

