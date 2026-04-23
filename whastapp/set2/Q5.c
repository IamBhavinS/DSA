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
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

void findNthFromEnd(int n) {
    struct node *first = head;
    struct node *second = head;

    for(int i = 0; i < n; i++) {
        if(first == NULL) {
            printf("Position exceeds list length\n");
            return;
        }
        first = first->next;
    }

    while(first != NULL) {
        first = first->next;
        second = second->next;
    }

    printf("Nth node from end = %d\n", second->data);
}

int main() {
    int nodes, n;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    createList(nodes);

    printf("Enter n: ");
    scanf("%d", &n);

    findNthFromEnd(n);

    return 0;
}
