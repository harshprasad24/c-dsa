#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert data at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = createNode(newData);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to print the doubly linked list from the beginning
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    printf("Doubly linked list after inserting at the end: ");
    printList(head);



    return 0;
}