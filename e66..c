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

// Function to delete a node at a given position in the doubly linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return NULL;
    }

    struct Node* temp = head;

    // Traverse to the desired position
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the position is invalid
    if (temp == NULL) {
        printf("Invalid position for deletion\n");
        return head;
    }

    // Update the pointers of the adjacent nodes
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If deleting the head node, update the head
    if (temp == head) {
        head = temp->next;
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

    // Delete at position 2 (0-indexed)
    head = deleteAtPosition(head, 2);

    printf("Doubly linked list after deletion at position 2: ");
    printList(head);


    return 0;
}