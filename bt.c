#include <stdio.h>
#include <stdlib.h>


struct node {
    char data[10]; 
    struct node *left;
    struct node *right;
};


struct node *createNode(char *day) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->data, day);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct node *insert(struct node *root, char *day) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(day);
    }
    
    // Compare the day with the current node's data
    int cmp = strcmp(day, root->data);
    
    // If day is less than the current node's data, insert into the left subtree
    if (cmp < 0) {
        root->left = insert(root->left, day);
    }
    // If day is greater than the current node's data, insert into the right subtree
    else if (cmp > 0) {
        root->right = insert(root->right, day);
    }
    
    return root;
}

// Function to perform inorder traversal of the binary search tree
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct node *root = NULL;
    
    // Days of the week in alphabetical order
    char days[][10] = {"Friday", "Monday", "Saturday", "Sunday", "Thursday", "Tuesday", "Wednesday"};
    
    // Inserting days into the binary search tree
    for (int i = 0; i < 7; i++) {
        root = insert(root, days[i]);
    }
    
    // Printing the days in sorted order
    printf("Days of the week in sorted order: ");
    inorderTraversal(root);
    
    return 0;
}