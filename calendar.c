#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int date;
    char *activity;
} Day;

Day *calendar[7];

void create() {
    for (int i = 0; i < 7; i++) {
        calendar[i] = malloc(sizeof(Day));
        calendar[i]->name = malloc(20);
        calendar[i]->activity = malloc(100);
    }
}

void read() {
    for (int i = 0; i < 7; i++) {
        printf("Enter day name, date, and activity: ");
        scanf("%s %d %[^\n]", calendar[i]->name, &calendar[i]->date, calendar[i]->activity);
    }
}

void display() {
    printf("Weekly activity details:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s (%d): %s\n", calendar[i]->name, calendar[i]->date, calendar[i]->activity);
    }
}

int main() {
    create();
    read();
    display();
    for (int i = 0; i < 7; i++) {
        free(calendar[i]->name);
        free(calendar[i]->activity);
        free(calendar[i]);
    }
    return 0;
}
