#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createNode(int data){
    struct node*n;
    n = (struct node*) malloc(sizeof(struct node));
    n->data=data;
    n->left =NULL;
    n->right =NULL;
    return n;
}
int main(){
    struct node*p=createNode(2);
    struct node*p1=createNode(1);
    struct node*p2=createNode(4);

    p->left=p1;
    p->right=p2;

     return 0;
}