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

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return NULL;
    }

    struct Node* temp = head;

    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
    }

    free(temp);
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

    // Insert at the beginning
    head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    printf("Doubly linked list before deletion: ");
    printList(head);

    // Delete from the beginning
    head = deleteFromBeginning(head);

    printf("Doubly linked list after deletion from the beginning: ");
    printList(head);

  

    return 0;
}