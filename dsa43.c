#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void CQINSERT(int element) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
    printf("Inserted %d into the circular queue\n", element);
}

void CQDELETE() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d from the circular queue\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

int main() {
    CQINSERT(10);
    CQINSERT(20);
    CQINSERT(30);
    CQDELETE();
    CQINSERT(40);
    CQDELETE();
    CQDELETE();
    CQDELETE();
    CQDELETE();
    return 0;
}