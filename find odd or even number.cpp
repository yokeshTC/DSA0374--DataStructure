#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    printf("Odd or Even:\n");
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d is Even\n", numbers[i]);
        } else {
            printf("%d is Odd\n", numbers[i]);
        }
    }
    
    return 0;
}

