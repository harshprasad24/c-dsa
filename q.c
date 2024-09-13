#include<stdio.h>
#define MAXSIZE 10
int cq[MAXSIZE];
int rear=-1,front=-1;

void insert();
void DELETE_();
void display();                                    //fuction declaration

int main(){
int choice ;
do{
    printf("\nCircular Queue");
    printf("\n1.Insert\n2.DELETE_\n3.Display\n4.exit\n");
    printf("\nEnter your Choice\n");
    scanf("%d",& choice);
    switch(choice)
    {
        case 1: insert();
        break;
        case 2: DELETE_();
        break;
        case 3: display();                            //function call
        break;
        defult:printf("Wrong choice");
    }
} while(choice!=4);
return 0;
}
void insert()
{
    int n;
    if((rear+1)%MAXSIZE==front){
        printf("Queue is overflow");
    }else{
        printf("Enter an elements");
        scanf("%d",&n);
        if(rear==-1 && front==-1){
            rear=0;
            front=0;
        }else{
            rear=(rear+1)%MAXSIZE;
        }
        cq[rear]=n;
    }
}
void DELETE_()
{                                                                  //fuction defination 
    int n;
    if((rear+1) % MAXSIZE==front){
        printf("Queue is empty");
    }else{
        n=cq[front];
        if(front==rear){
            front=-1;
            rear=-1; 
        }else{
            front=(front+1)%MAXSIZE;
        }
        printf("DELETED_ Element %d",n);
    }
}
void display()
{
    if(front > rear){
        printf("Queue is empety");
    }else{
        printf("Queue Elements");
        for(int i=front;i!=rear;i=(i+1)%MAXSIZE){
            printf("%d\n",cq[i]);
        }
    }
}
