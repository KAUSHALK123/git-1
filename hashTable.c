#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int id;       
    char name[20]; 
} Employee;

Employee hash_table[MAX];
int occupied[MAX] = {0}; 

int hash_function(int key) {
    return key % MAX;
}

void insert(int id, char *name) {
    int key = hash_function(id);
    while (occupied[key]) {
        key = (key + 1) % MAX;
    }
    hash_table[key].id = id;
    strcpy(hash_table[key].name, name);
    occupied[key] = 1;
}

void display() {
    printf("\nThe hash table is:\n");
    printf("\nHTKey\tEmpID\tEmpName\n");
    for (int i = 0; i < MAX; i++) {
        if (occupied[i]) {
            printf("%d\t%d\t%s\n", i, hash_table[i].id, hash_table[i].name);
        } else {
            printf("%d\t0\t\n", i); 
        }
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {
        hash_table[i].id = 0;
        strcpy(hash_table[i].name, "");
    }

    insert(287, "XXX");
    insert(562, "YYY");
    insert(683, "ZZZ");

    display();
    return 0;
}
