#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;


void initialize(Stack *stack) {
    stack->top = -1;
}


void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}


char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}


int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        }
        i++;
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

