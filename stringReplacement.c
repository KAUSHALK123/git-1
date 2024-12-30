#include <stdio.h>
#include <string.h>

void replace(char *str, char *pat, char *rep) {
    char result[200];
    int i = 0, j = 0;
    while (*str) {
        if (strstr(str, pat) == str) {
            strcpy(&result[j], rep);
            j += strlen(rep);
            str += strlen(pat);
        } else {
            result[j++] = *str++;
        }
    }
    result[j] = '\0';
    printf("Resultant String: %s\n", result);
}

int main() {
    char str[100], pat[50], rep[50];
    printf("Enter string: ");
    gets(str);
    printf("Enter pattern: ");
    gets(pat);
    printf("Enter replacement: ");
    gets(rep);
    replace(str, pat, rep);
    return 0;
}
