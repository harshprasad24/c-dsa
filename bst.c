#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*left , *right;
};
struct node *newnode(int data){
    struct node*temp = (struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert(int data , struct node *root){
    if (root == NULL) {
        return newnode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int main(){
    struct node *root=NULL;
    root= insert(100,root);
    insert(100,root);
    insert(80,root);
    insert(120,root);
    insert(60,root);
    insert(90,root);
    insert(110,root);
    printf("bst tree ");

    return 0;
}