#include <stdio.h>
#include <ctype.h>
#include <string.h>

double compute(char symbol, double op1, double op2) {
    switch (symbol) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default:
            printf("Invalid operator: %c\n", symbol);
            return 0;
    }
}

int main() {
    char postfix[100], symbol;
    double s[100], res;
    int top = -1;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];


        if (isdigit(symbol)) {
            s[++top] = symbol - '0';
        }
        else {
            double op2 = s[top--];
            double op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }

    res = s[top--];
    printf("\nThe postfix evaluation result: %.2f\n", res);


}
