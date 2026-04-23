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

void display(struct node *start) {
    struct node *temp = start;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void splitList(struct node **first, struct node **second) {
    struct node *slow = head;
    struct node *fast = head;

    if(head == NULL)
        return;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

int main() {
    int n;
    struct node *firstHalf = NULL;
    struct node *secondHalf = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    splitList(&firstHalf, &secondHalf);

    printf("First half:\n");
    display(firstHalf);

    printf("Second half:\n");
    display(secondHalf);

    return 0;
}
