#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int ssn;
    char name[20], dept[20], desg[20], ph[15];
    float sal;
    struct Node *prev, *next;
} Node;

Node *head = NULL;

Node *create_node(int ssn, char *name, char *dept, char *desg, char *ph, float sal) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->ssn = ssn;
    strcpy(new_node->name, name);
    strcpy(new_node->dept, dept);
    strcpy(new_node->desg, desg);
    strcpy(new_node->ph, ph);
    new_node->sal = sal;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

void insert_front(int ssn, char *name, char *dept, char *desg, char *ph, float sal) {
    Node *new_node = create_node(ssn, name, dept, desg, ph, sal);
    if (head) head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void delete_front() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    printf("Deleted: %d %s\n", temp->ssn, temp->name);
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("DLL contents:\n");
    Node *temp = head;
    while (temp) {
        printf("%d %s %s %s %s %.2f\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->ph, temp->sal);
        temp = temp->next;
    }
}

int main() {
    insert_front(1, "Alice", "HR", "Manager", "1234567890", 50000);
    insert_front(2, "Bob", "IT", "Developer", "0987654321", 60000);
    display();
    delete_front();
    display();
    return 0;
}
