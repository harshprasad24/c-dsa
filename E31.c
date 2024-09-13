#include <stdio.h>
#define MAX 100

int stack[MAX],i;
int top = -1;

void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        for (int i = ++top; i > 0; i--) {
            stack[i] = stack[i - 1];
        }
        stack[0] = item;
        printf("Pushed %d into the stack\n", item);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped %d from the stack\n", stack[0]);
        for ( i = 0; i < top; i++) {
            stack[i] = stack[i + 1];
        }
        top--;
    }
}

void peek() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", stack[0]);
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}