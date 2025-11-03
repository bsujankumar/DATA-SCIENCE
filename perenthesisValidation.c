#include <stdio.h>
#include <string.h>

int pValidation(char str[]) {
    int i, top = -1;
    char s[20];

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s[++top] = str[i];

        else if (str[i] == ')' && top != -1 && s[top] == '(')
            top--;
        else if (str[i] == ']' && top != -1 && s[top] == '[')
            top--;
        else if (str[i] == '}' && top != -1 && s[top] == '{')
            top--;
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            return 0;
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char str[100];
    int res;

    printf("Enter the expression:\n");
    scanf("%s", str);

    res = pValidation(str);

    if (res)
        printf("Parentheses are balanced\n");
    else
        printf("Parentheses are NOT balanced\n");

    return 0;
}
