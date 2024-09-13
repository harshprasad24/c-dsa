#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear = -1, front = -1;
int queue[MAX];

void insert(int data) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full.\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = data;
    }
}

int delete() {
    int data;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else if (front == rear) {
        data = queue[front];
        front = rear = -1;
    } else {
        data = queue[front];
        front = (front + 1) % MAX;
    }
    return data;
}

void view() {
    int i = front;
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Currently borrowed books: \n");
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d\n", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Borrow a book\n2. Return a book\n3. View borrowed books\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter the book number: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                data = delete();
                if (data != -1) {
                    printf("Returned book: %d\n", data);
                }
                break;
            case 3:
                view();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}