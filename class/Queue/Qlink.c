//Write a C program to implement a queue using a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Queue full\n");
        return;
    }

    newNode->data=val;
    newNode->next=NULL;

    if(front==NULL) front=rear=newNode;
    else{
        rear->next=newNode;
        rear=newNode;
    }

    printf("%d added\n",val);
}

void dequeue(){
    if(front==NULL){
        printf("Queue empty\n");
        return;
    }

    struct Node* temp=front;
    printf("%d removed\n",temp->data);

    front=front->next;
    if(front==NULL) rear=NULL;

    free(temp);
}

void display(){
    if(front==NULL){
        printf("Nothing\n");
        return;
    }

    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int ch,val;

    while(1){
        printf("\n1 Add 2 Remove 3 Show 4 Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                scanf("%d",&val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Wrong\n");
        }
    }
}
