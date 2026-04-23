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

int length(struct node *temp) {
    if(temp == NULL)
        return 0;

    return 1 + length(temp->next);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    printf("Length of list = %d\n", length(head));

    return 0;
}
