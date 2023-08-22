#include <stdio.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int table[], int key) {
    int index = hashFunction(key);

    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE; 
    }

    table[index] = key;
}

void display(int table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, table[i]);
    }
}

int main() {
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; 
    }

    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insert(hashTable, element);
    }

    display(hashTable);

    return 0;
}

