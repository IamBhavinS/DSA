//Write a C program to implement a circular queue using an array.

#include <stdio.h>
#define MAX 5

int bhavin[MAX];
int front=-1, rear=-1;

void enqueue(int value) {
    if ((rear+1) % MAX==front) {
        printf("Overflow\n");
        return;
    }

    if (front==-1)
        front=rear=0;
    else
        rear=(rear+1)%MAX;

    bhavin[rear]=value;
}

void dequeue() {
    if (front==-1) {
        printf("Underflow\n");
        return;
    }

    printf("%d removed\n", bhavin[front]);

    if (front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
}

void display() {
    if (front==-1) {
        printf("Empty\n");
        return;
    }

    int i=front;
    while (1) {
        printf("%d ",bhavin[i]);
        if (i==rear)
            break;
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);
    printf("enqueing:- 60,70 \n");
    display();

    return 0;
}
