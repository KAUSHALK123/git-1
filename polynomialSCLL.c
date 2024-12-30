#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coef, xexp, yexp, zexp;
    struct Node *next;
} Node;

Node *create_node(int coef, int xexp, int yexp, int zexp, Node *head) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->coef = coef;
    new_node->xexp = xexp;
    new_node->yexp = yexp;
    new_node->zexp = zexp;
    if (head == NULL) {
        new_node->next = new_node;
        return new_node;
    }
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = new_node;
    new_node->next = head;
    return head;
}

void display(Node *head) {
    if (head == NULL) {
        printf("No polynomial\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%dx^%dy^%dz^%d ", temp->coef, temp->xexp, temp->yexp, temp->zexp);
        temp = temp->next;
        if (temp != head) printf("+ ");
    } while (temp != head);
    printf("\n");
}

int evaluate(Node *head, int x, int y, int z) {
    int result = 0;
    Node *temp = head;
    do {
        result += temp->coef * pow(x, temp->xexp) * pow(y, temp->yexp) * pow(z, temp->zexp);
        temp = temp->next;
    } while (temp != head);
    return result;
}

int main() {
    Node *poly = NULL;
    poly = create_node(6, 2, 2, 1, poly);
    poly = create_node(-4, 0, 1, 5, poly);
    poly = create_node(3, 3, 1, 1, poly);
    display(poly);
    printf("Evaluation (x=1, y=1, z=1): %d\n", evaluate(poly, 1, 1, 1));
    return 0;
}
