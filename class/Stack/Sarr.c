//Write a C program to implement a stack using an array.
 
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top=-1;

void push(int value) {
    if (top==MAX-1) {
        printf("Stack is Overflow\n");
        return;
    }
    top++;
    stack[top]=value;
}

void pop() {
    if (top==-1) {
        printf("Stack is Underflow\n");
        return;
    }
    printf("Popped:-%d\n",stack[top]);
    top--;
}

void display() {
    if (top==-1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i=top;i>=0;i--) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:-");
        scanf("%d",&choice);

        if (choice==1) {
            printf("Enter value:-");
            scanf("%d",&value);
            push(value);
        }
        else if (choice==2) {
            pop();
        }
        else if (choice==3) {
            display();
        }
        else if (choice==4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
