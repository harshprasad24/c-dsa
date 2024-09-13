#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void CQINSERT(int item) {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    queue[rear] = item ;
}

void CQDELETE() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display() {
    int front_pos = front, rear_pos = rear;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            printf("%d ", queue[front_pos]);
            front_pos++;
        }
    } else {
        while (front_pos <= MAX - 1) {
            printf("%d ", queue[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos) {
            printf("%d ", queue[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main() {
    CQINSERT(14);
    CQINSERT(-3);
    CQINSERT(18);
    CQINSERT(21);
    CQINSERT(30);

    display();
    CQDELETE();
    display();

    return 0;
}
