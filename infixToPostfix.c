#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    char stack[50];
    int top = -1, j = 0;
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (stack[top] != '(') postfix[j++] = stack[top--];
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
    }
    while (top != -1) postfix[j++] = stack[top--];
    postfix[j] = '\0';
}

int main() {
    char infix[50], postfix[50];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
