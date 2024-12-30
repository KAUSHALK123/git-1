#include <stdio.h>
#include <math.h>
#include <ctype.h>

double compute(double op1, double op2, char op) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        default: return 0;
    }
}

void evaluate_postfix(char *postfix) {
    double stack[50];
    int top = -1;
    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else {
            double op2 = stack[top--];
            double op1 = stack[top--];
            stack[++top] = compute(op1, op2, ch);
        }
    }
    printf("Result: %.2f\n", stack[top]);
}

int main() {
    char postfix[50];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    evaluate_postfix(postfix);
    return 0;
}
