#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int rear = -1, Front = 0;

void insert();
void delete_();
void display();

int main() {
    int choice;
    do {
        printf("\nQueue");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete_();
                break;
            case 3:
                display();
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 4);
    return 0;
}

void insert() {
    int n;
    if (rear == MAXSIZE - 1) {
        printf("Queue is overflow\n");
    } else {
        printf("Enter an element: ");
        scanf("%d", &n);
        rear ++ ;
        queue[rear] = n;
    }
}

void delete_() {
    int n;
    if (Front > rear) {
        printf("Queue is empty\n");
    } else {
        n = queue[Front];
        printf("Deleted Element: %d\n", n);
        Front++;
    }
}
//first in first out(FIFO)
void display() {
    if (Front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue Elements:\n");
        for (int i = rear; i >= Front; i--) {
            printf("%d\n", queue[i]);
        }
    }
}
