#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *newnode(int data) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(int data, struct node *root) {
    if (root == NULL) {
        return newnode(data);
    }
    if (data < root->data) {
        root->left = insert(data, root->left);
    } else if (data > root->data) {
        root->right = insert(data, root->right);
    }
    return root;
}


int main() {
    struct node *root = NULL;
    root = insert(100, root);
    insert(80, root);
    insert(120, root);
    insert(60, root);
    insert(90, root);
    insert(110, root);
    insert(130, root);

    return 0;
}
