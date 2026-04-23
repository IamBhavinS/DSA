//Write a C program to create a binary tree with 5 nodes using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

int main(){
    struct node*n1,*n2,*n3,*n4,*n5;

    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));

    n1->data=1;
    n2->data=2;
    n3->data=3;
    n4->data=4;
    n5->data=5;

    n1->left=n2;
    n1->right=n3;

    n2->left=n4;
    n2->right=n5;

    n3->left=NULL;
    n3->right=NULL;

    n4->left=NULL;
    n4->right=NULL;

    n5->left=NULL;
    n5->right=NULL;

    printf("%d ",n1->data);
    printf("%d ",n1->left->data);
    printf("%d ",n1->right->data);
    printf("%d ",n1->left->left->data);
    printf("%d ",n1->left->right->data);

    return 0;
}
