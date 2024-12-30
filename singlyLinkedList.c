#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int usn, sem, phno;
    char name[20], branch[10];
    struct Node *next;
} Node;

Node *head = NULL;
int count = 0;

Node *create_node(int usn, char *name, char *branch, int sem, int phno) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->usn = usn;
    strcpy(new_node->name, name);
    strcpy(new_node->branch, branch);
    new_node->sem = sem;
    new_node->phno = phno;
    new_node->next = NULL;
    return new_node;
}

void insert_front(int usn, char *name, char *branch, int sem, int phno) {
    Node *new_node = create_node(usn, name, branch, sem, phno);
    new_node->next = head;
    head = new_node;
    count++;
}

void delete_front() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    printf("Deleted: %d %s\n", temp->usn, temp->name);
    head = head->next;
    free(temp);
    count--;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("SLL contents:\n");
    Node *temp = head;
    while (temp) {
        printf("%d %s %s %d %d\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
    }
    printf("Node count: %d\n", count);
}

int main() {
    insert_front(1, "Alice", "CSE", 3, 12345);
    insert_front(2, "Bob", "CSE", 3, 67890);
    display();
    delete_front();
    display();
    return 0;
}
