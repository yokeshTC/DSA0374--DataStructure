#include <stdio.h>

#define MAX_SIZE 100


void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int insert(int arr[], int size, int pos, int element) {
    if (size >= MAX_SIZE || pos < 0 || pos > size) {
        return size;  
    }

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1]; 
    }
    arr[pos] = element; 
    return size + 1; 
}


int deleteElement(int arr[], int size, int pos) {
    if (size <= 0 || pos < 0 || pos >= size) {
        return size;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    return size - 1; 
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    int choice, element, pos;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at: ");
                scanf("%d", &pos);
                size = insert(arr, size, pos, element);
                break;

            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &pos);
                size = deleteElement(arr, size, pos);
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

