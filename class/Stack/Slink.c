//Write a C program to implement a stack using a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack id overflow\n");
        return;
    }
    newnode->data= value;
    newnode->next= top;
    top= newnode;
}

void pop() {
    struct node *temp;

    if (top==NULL) {
        printf("Stack is Underflow\n");
        return;
    }
    temp=top;
    printf("Popped:-%d\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
