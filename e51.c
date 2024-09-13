#include <stdio.h>  
#include <stdlib.h>  
struct Node {  
    int data;  
    struct Node* next;  
};
struct Node* head = NULL;
void insert(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = value;  
    newNode->next = NULL;    
    if (head == NULL) 
	{  
        head = newNode;  
    } else 
	{  
        struct Node* current = head;  
        while (current->next != NULL) 
		{  
            current = current->next;  
        }   
        current->next = newNode;
    }
}
void traverse()
{
    struct Node* current = head;
    while (current != NULL)
	{
        printf("%d ", current->data);
        current = current->next;
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    printf("List:");
    traverse();
    return 0;
}