#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    struct node *newnode, *temp;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } 
        else {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

void removeDuplicates() {
    struct node *temp = head;
    struct node *dup;

    while(temp != NULL && temp->next != NULL) {

        if(temp->data == temp->next->data) {
            dup = temp->next;
            temp->next = dup->next;
            free(dup);
        }
        else {
            temp = temp->next;
        }
    }
}

void display() {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    printf("\nOriginal list:\n");
    display();

    removeDuplicates();

    printf("\nAfter removing duplicates:\n");
    display();

    return 0;
}

