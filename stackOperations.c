#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1;

void push(int item) {
    if (top == MAX - 1) { printf("Stack overflow\n"); return; }
    stack[++top] = item;
}

int pop() {
    if (top == -1) { printf("Stack underflow\n"); return -1; }
    return stack[top--];
}

void display() {
    if (top == -1) { printf("Stack is empty\n"); return; }
    printf("Stack contents: ");
    for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
    printf("\n");
}

void check_palindrome() {
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            printf("Not a palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("1.Push 2.Pop 3.Check Palindrome 4.Display 5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter item: "); scanf("%d", &item); push(item); break;
            case 2: printf("Popped: %d\n", pop()); break;
            case 3: check_palindrome(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
