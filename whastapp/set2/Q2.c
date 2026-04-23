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

void findMiddle() {
    struct node *slow = head;
    struct node *fast = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps
    }

    printf("Middle element = %d\n", slow->data);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    findMiddle();

    return 0;
}
