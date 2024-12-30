#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char queue[MAX];
int front = 0, rear = -1, count = 0;

void insert(char item) {
    if (count == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    count++;
}

void delete() {
    if (count == 0) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %c\n", queue[front]);
    front = (front + 1) % MAX;
    count--;
}

void display() {
    if (count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < count; i++) {
        printf("%c ", queue[(front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    int choice;
    char item;
    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter item: "); scanf(" %c", &item); insert(item); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
