#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1,i;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

void reverse(char str[]) {
    int n = strlen(str);

    for ( i = 0; i < n; i++) {
        push(str[i]);
    }

    for ( i = 0; i < n; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[] = "Hello, World!";
    reverse(str);
    printf("Reversed string is: %s\n", str);
    return 0;
}