//Write a C program to implement two stacks in a single array.

#include <stdio.h>
#define MAX 5

int arr[MAX];
int top1=-1;
int top2=MAX;

//for ctack 1 push
void push1(int value) {
    if (top1+1==top2) {
        printf("Overflow\n");
        return;
    }
    arr[++top1]=value;
}

//for stack 2 push
void push2(int value) {
    if (top1+1==top2) {
        printf("Overflow\n");
        return;
    }
    arr[--top2]=value;
}

//for stack 1 pop
void pop1() {
    if (top1==-1) {
        printf("Underflow\n");
        return;
    }
    printf("Popped from stack1: %d\n",arr[top1]);
    top1--;
}

//for stackk 2 pop
void pop2() {
    if (top2==MAX) {
        printf("Underflow\n");
        return;
    }
    printf("Popped from stack2: %d\n", arr[top2]);
    top2++;
}

// display
void display() {
    printf("Stack1:");
    for (int i=0;i<=top1;i++)
        printf("%d ", arr[i]);

    printf("\nStack2: ");
    for (int i=MAX-1; i>=top2;i--)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    push1(7);
    push1(77);
    push2(4);
    push2(44);

    display();

    pop1();
    pop2();

    display();

    return 0;
} 
