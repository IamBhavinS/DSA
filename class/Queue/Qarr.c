//Write a C program to implement a linear queue using an array.

#include <stdio.h>
#define MAX 5

int arr[MAX];
int front=-1,rear=-1;

// for enqueueing
void enqueue(int value) {
    if (rear==MAX-1) {
        printf("Overflow\n");
        return;
    }
    if (front==-1)
        front=0;
    arr[++rear]=value;
}


//for dequeueing
void dequeue() {
    if (front==-1 || front>rear) {
        printf("Underflow\n");
        return;
    }
    printf("Removed:%d\n",arr[front++]);
}
//for displaying
void display() {
    if (front==-1 || front>rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i=front; i<=rear; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(40);
    enqueue(50);

    display();

    return 0;
}
